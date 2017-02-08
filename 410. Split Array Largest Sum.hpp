// 410. Split Array Largest Sum

// Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

// Note:
// If n is the length of array, assume the following constraints are satisfied:

// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)
// Examples:

// Input:
// nums = [7,2,5,10,8]
// m = 2

// Output:
// 18

// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.

// https://discuss.leetcode.com/topic/61395/c-fast-very-clear-explanation-clean-code-solution-with-greedy-algorithm-and-binary-search/2
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (auto num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (isValueLargeEnough(nums, m, mid)) {// mid may be too large 
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    bool isValueLargeEnough(vector<int>& nums, int m, long long maxV) {
        long long curSum = 0;
        for (auto num : nums) {
           curSum += num;
           if (curSum > maxV) {
               curSum = num;
               --m;
               if (!m) return false;
           }
        }
        return true;
    }
};

// https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java/2
        while (l <= r) {
            long mid = (l + r)/ 2;
            if (valid(mid, nums, m)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }