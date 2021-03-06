// 403. Frog Jump

// A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

// Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

// If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

// Note:

// The number of stones is ≥ 2 and is < 1,100.
// Each stone's position will be a non-negative integer < 231.
// The first stone's position is always 0.
// Example 1:

// [0,1,3,5,6,8,12,17]

// There are a total of 8 stones.
// The first stone at the 0th unit, second stone at the 1st unit,
// third stone at the 3rd unit, and so on...
// The last stone at the 17th unit.

// Return true. The frog can jump to the last stone by jumping 
// 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
// 2 units to the 4th stone, then 3 units to the 6th stone, 
// 4 units to the 7th stone, and 5 units to the 8th stone.
// Example 2:

// [0,1,2,3,4,8,9,11]

// Return false. There is no way to jump to the last stone as 
// the gap between the 5th and 6th stone is too large.

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> m;
        m[1].insert(1);
        for (int i = 1; i < stones.size(); ++i) {
            for (auto step : m[stones[i]]) {
                if (step > 1) m[stones[i] + step - 1].insert(step - 1);
                m[stones[i] + step].insert(step);
                m[stones[i] + step + 1].insert(step + 1);
            }
        }
        return !m[stones.back()].empty();
    }
};

// https://discuss.leetcode.com/topic/59439/straight-forward-9ms-7-line-c-solution-with-explanation/2
class Solution {
public:
   unordered_map<int, bool> dp;

    bool canCross(vector<int>& stones, int pos = 0, int k = 0) {
        // pos will always be less than 2^11 (2048).
        // k must start from 0 and 1 and at the 1100th step the greatest valid k would be 1100.
        // combining pos and k is safe here.
        int key = pos | k << 11;

        if (dp.count(key) > 0)
            return dp[key];

        for (int i = pos + 1; i < stones.size(); i++) {
            int gap = stones[i] - stones[pos];
            if (gap < k - 1)
                continue;
            if (gap > k + 1)
                return dp[key] = false;
            if (canCross(stones, i, gap))
                return dp[key] = true;
        }

        return dp[key] = (pos == stones.size() - 1);
    }
};