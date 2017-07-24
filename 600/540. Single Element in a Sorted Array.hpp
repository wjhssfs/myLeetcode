// 540. Single Element in a Sorted Array

// Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

// Example 1:
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:
// Input: [3,3,7,7,10,11,11]
// Output: 10
// Note: Your solution should run in O(log n) time and O(1) space.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1 || nums.back() != nums[nums.size() - 2]) return nums.back();
        int l = 0, r = nums.size() / 2 - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m * 2] == nums[m * 2 + 1]) l = m + 1;
            else r = m;
        }
        return nums[r * 2];
    } 
};

// need not to worry about out of bound for last element.
// it will break out of loop (l == r) when it get to last element.

public class Solution {
    public int singleNonDuplicate(int[] nums) {
        // binary search
        int n=nums.length, lo=0, hi=n/2;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (nums[2*m]!=nums[2*m+1]) hi = m;
            else lo = m+1;
        }
        return nums[2*lo];
    }
}