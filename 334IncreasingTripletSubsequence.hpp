// 334. Increasing Triplet Subsequence

// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

// Formally the function should:
// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Your algorithm should run in O(n) time complexity and O(1) space complexity.

// Examples:
// Given [1, 2, 3, 4, 5],
// return true.

// Given [5, 4, 3, 2, 1],
// return false.

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sz = nums.size(), lowerBound = INT_MAX, minInLeft = INT_MAX;
        for(int i = 0; i < sz; i++){
            if(nums[i] > lowerBound)
                return true;
            if(nums[i] > minInLeft)
                lowerBound = min(lowerBound, nums[i]);
            minInLeft = min(minInLeft, nums[i]);
        }
        return false;
    }
};