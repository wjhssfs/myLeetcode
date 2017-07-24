// 611. Valid Triangle Number
// Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

// Example 1:
// Input: [2,2,3,4]
// Output: 3
// Explanation:
// Valid combinations are: 
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
// Note:
// The length of the given array won't exceed 1000.
// The integers in the given array are in the range of [0, 1000].

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        size_t i = 0;
        while (i < nums.size() && nums[i] == 0) ++i;
        if (nums.size() - i < 3) return 0;
        for (; i < nums.size(); ++i) {
            size_t r = nums.size() - 1, l = r;
            while (r > i + 1) {
                while (l > i + 1 && nums[l-1] > nums[r] - nums[i]) --l;
                //if (nums[l] <= nums[r] - nums[i]) break;
                res += r - l;
                --r;
            }
        }
        return res;
    }
};

public static int triangleNumber(int[] A) {
    Arrays.sort(A);
    int count = 0, n = A.length;
    for (int i=n-1;i>=2;i--) {
        int l = 0, r = i-1;
        while (l < r) {
            if (A[l] + A[r] > A[i]) {
                count += r-l;
                r--;
            }
            else l++;
        }
    }
    return count;
}