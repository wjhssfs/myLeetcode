// 713. Subarray Product Less Than K
// Your are given an array of positive integers nums.

// Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

// Example 1:
// Input: nums = [10, 5, 2, 6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
// Note:

// 0 < nums.length <= 50000.
// 0 < nums[i] < 1000.
// 0 <= k < 10^6.

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0;
        int end = start;
        int result = 0;
        long long p = 1;
        while (end < nums.size()) {
            if (p * nums[end] < k) {
                p *= nums[end];
                result += ++end - start;
            } else {
                p = (start == end) ? 1 : p / nums[start];
                end = max(++start , end);
            }
        }
        return result;
    }
};