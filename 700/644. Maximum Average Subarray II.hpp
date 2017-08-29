// 644. Maximum Average Subarray II

// Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.

// Example 1:
// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation:
// when length is 5, maximum average value is 10.8,
// when length is 6, maximum average value is 9.16667.
// Thus return 12.75.
// Note:
// 1 <= k <= n <= 10,000.
// Elements of the given array will be in range [-10,000, 10,000].
// The answer with the calculation error less than 10-5 will be accepted.

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = INT_MAX, right = INT_MIN, mid;
        for(int num:nums){
            right = max(right, double(num));
            left = min(left, double(num));
        }
        while(left + 0.00001 < right){
            mid = left + (right - left)/2;
            if(islarger(nums, mid, k))right = mid;
            else left = mid;
        }
        return left;
    }
    
    //Return true when mid is larger than or equal to the maximum average value;
    bool islarger(vector<int>& nums, double mid, int k){
        // sum: the sum from nums[0] to nums[i];
        // prev_sum:  the sum from nums[0] to nums[i-k];
        // min_sum: the minimal value of prev_sum
        double sum = 0, prev_sum = 0, min_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] - mid;
            if(i >= k){
                prev_sum += nums[i-k] - mid;                        
                min_sum = min(prev_sum, min_sum); 
            }
            if(i >= k-1 && sum > min_sum)return false;
        }
        return true;                                               
    }
};


// https://discuss.leetcode.com/topic/96131/python-advanced-o-n-solution-convex-hull-window