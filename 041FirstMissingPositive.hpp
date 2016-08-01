// 41 First Missing Positive
// Given an unsorted integer array, find the first missing positive integer.
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
// Your algorithm should run in O(n) time and uses constant space.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i < n)
        {
            if (nums[i] > 0 && nums[i] < n && nums[i] != i+1 && nums[nums[i] - 1] != nums[i]) swap(nums[i], nums[nums[i] - 1]);
            else i++;
        }
        for (i = 0; i < n && nums[i] == i + 1; i++){}
        return i + 1;
    }
};