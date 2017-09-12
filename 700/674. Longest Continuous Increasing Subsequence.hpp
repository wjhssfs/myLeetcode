// 674. Longest Continuous Increasing Subsequence
// Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

// Example 1:
// Input: [1,3,5,4,7]
// Output: 3
// Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
// Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
// Example 2:
// Input: [2,2,2,2,2]
// Output: 1
// Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
// Note: Length of the array will not exceed 10,000.

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int start = 0, res = 1;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) continue;
            res = max(res, i - start);
            start = i;
        }
        res = max(res, (int)nums.size() - start);
        return res;
    }
};

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cur = 0, res = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) res = max(res, ++cur);
            else cur = 1;
        }
        return res;
    }
};