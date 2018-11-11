// 659. Split Array into Consecutive Subsequences

// You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

// Example 1:
// Input: [1,2,3,3,4,5]
// Output: True
// Explanation:
// You can split them into two consecutive subsequences : 
// 1, 2, 3
// 3, 4, 5
// Example 2:
// Input: [1,2,3,3,4,4,5,5]
// Output: True
// Explanation:
// You can split them into two consecutive subsequences : 
// 1, 2, 3, 4, 5
// 3, 4, 5
// Example 3:
// Input: [1,2,3,4,4,5]
// Output: False
// Note:
// The length of the input is in range of [1, 10000]

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        queue<int> q;
        int last = -1;
        for (int i = 0, j = 0; i < nums.size(); i = j) {
            if (last != -1 && nums[i] != last + 1) {
                while(q.size()) {
                    if (nums[i - 1] - q.front() + 1 < 3) return false;
                    q.pop();
                }
            }
            while (j < nums.size() && nums[j]  == nums[i]) ++j;
            last = nums[i];
            int n = j - i;
            if (n > q.size()) {
                for (int k = q.size(); k < n; ++k) q.push(nums[i]);
            } else if (n < q.size()){
                int t = q.size();
                for (int k = n; k < t; ++k) {
                    if (nums[i - 1] - q.front() + 1 < 3) return false;
                    q.pop();
                }
            }
        }
        while(q.size()) {
            if (nums.back() - q.front() + 1 < 3) return false;
            q.pop();
        }
        return true;
    }
};

// We iterate through the array once to get the frequency of all the elements in the array
// We iterate through the array once more and for each element we either see if it can be appended to a previously constructed consecutive
// sequence or if it can be the start of a new consecutive sequence. If neither are true, then we return false.
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, appendfreq;
        for (auto i : nums) ++freq[i];
        for (auto i : nums) {
            if (freq[i] == 0) continue;
            else if (appendfreq[i] > 0) { // needs to be before create new
                // consider  1 2 3 4 5 5 6 7
                --appendfreq[i];
                ++appendfreq[i + 1];
            } else if (freq[i + 1] > 0 && freq[i + 2] > 0) {
                --freq[i + 1];
                --freq[i + 2];
                ++appendfreq[i + 3];
            } else return false;
            --freq[i];
        }
        return true;
    }
};