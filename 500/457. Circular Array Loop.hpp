// 457. Circular Array Loop

// You are given an array of positive and negative integers. If a number n at an index is positive, then move forward n steps. Conversely, if it's negative (-n), move backward n steps. Assume the first element of the array is forward next to the last element, and the last element is backward next to the first element. Determine if there is a loop in this array. A loop starts and ends at a particular index with more than 1 element along the loop. The loop must be "forward" or "backward'.

// Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 -> 2 -> 3 -> 0.

// Example 2: Given the array [-1, 2], there is no loop.

// Note: The given array is guaranteed to contain no element "0".

// Can you do it in O(n) time complexity and O(1) space complexity?

class Solution {
    int getIndex(int i, vector<int>& nums) {
        int n = (int)nums.size();
        return (n + i + nums[i]) % n;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;
            int j = i, k = getIndex(i, nums);
            while(nums[k] * nums[j] > 0 && nums[getIndex(k, nums)] * nums[i] > 0) {
                if (j == k) {
                    // single element loop
                    if (j == getIndex(j, nums)) break;
                    return true;
                }
                j = getIndex(j, nums);
                k = getIndex(getIndex(k, nums), nums);
            }
            j = i;
            int val = nums[i];
            while(nums[j] * val > 0) {
                int next = getIndex(j, nums);
                nums[j] = 0;
                j = next;
            }
        }
        return false;
    }
};