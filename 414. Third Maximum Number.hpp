// 414. Third Maximum Number

// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

// Example 1:
// Input: [3, 2, 1]

// Output: 1

// Explanation: The third maximum is 1.
// Example 2:
// Input: [1, 2]

// Output: 2

// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
// Example 3:
// Input: [2, 2, 3, 1]

// Output: 1

// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.

int thirdMax(vector<int>& nums) {
    set<int> top3;
    for (int num : nums) {
        top3.insert(num);
        if (top3.size() > 3)
            top3.erase(top3.begin());
    }
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long firstMax = LONG_MIN, secondMax = LONG_MIN, thirdMax = LONG_MIN;
        for (auto num : nums) {
            if (num > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            }
            else if (num == firstMax) continue;
            else if (num > secondMax) {
                thirdMax = secondMax;
                secondMax = num;
            }
            else if (num == secondMax) continue;
            else if (num > thirdMax) thirdMax = num;
        }
        return thirdMax == LONG_MIN ? firstMax : thirdMax;
    }
};

class Solution {
public:
    int thirdMax(vector<int>const & nums) {
        vector<int> q;
        for (auto num : nums) {
            bool handled = false;
            for (auto it = q.begin(); it != q.end(); ++it) {
                if (num > *it) {
                    q.insert(it, num);
                    handled = true;
                    break;
                }
                else if (num == *it) {
                    handled = true;
                    break;
                }
            }
            if (!handled && q.size() < 3) q.push_back(num);
            if (q.size() == 4) q.pop_back();
        }
        if (q.size() < 3) return q[0];
        else return q[2];
    }
};