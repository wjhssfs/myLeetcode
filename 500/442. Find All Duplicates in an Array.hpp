// 442. Find All Duplicates in an Array

// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements that appear twice in this array.

// Could you do it without extra space and in O(n) runtime?

// Example:
// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [2,3]

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if (nums.size() < 2) return res;
        int cur = 0;
        while (cur < nums.size()) {
            if (nums[nums[cur]-1] != nums[cur]) swap(nums[cur], nums[nums[cur] - 1]);
            else ++cur;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1) res.push_back(nums[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i]) -1] < 0) res.push_back(abs(nums[i]));
            nums[abs(nums[i]) -1] = -nums[abs(nums[i]) -1];
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) nums[i] = -nums[i];
        }
        return res;
    }
};