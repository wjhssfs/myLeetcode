// 330. Patching Array
// Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

// Example 1:
// nums = [1, 3], n = 6
// Return 1.

// Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
// Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
// Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
// So we only need 1 patch.

// Example 2:
// nums = [1, 5, 10], n = 20
// Return 2.
// The two patches can be [2, 4].

// Example 3:
// nums = [1, 2, 2], n = 5
// Return 0.

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long  nll = n, cur = 1, sz = (int)nums.size();
        int nPatch = 0, i = 0;
        while(cur <= nll){
            if(i >= sz || nums[i] > cur)
            {
                ++nPatch;
                cur += cur;
            }
            else if(nums[i] == cur){
                cur += cur;
                ++i;
            }
            else {
                cur += nums[i];
                ++i;
            }
        }
        
        return nPatch;
    }
};

// https://leetcode.com/discuss/73256/mergesort-solution
def countSmaller(self, nums):
    def sort(enum):
        half = len(enum) / 2
        if half:
            left, right = sort(enum[:half]), sort(enum[half:])
            for i in range(len(enum))[::-1]:
                if not right or left and left[-1][1] > right[-1][1]:
                    smaller[left[-1][0]] += len(right)
                    enum[i] = left.pop()
                else:
                    enum[i] = right.pop()
        return enum
    smaller = [0] * len(nums)
    sort(list(enumerate(nums)))
    return smaller
};

// https://discuss.leetcode.com/topic/35494/solution-explanation
int minPatches(vector<int>& nums, int n) {
    long miss = 1, added = 0, i = 0;
    while (miss <= n) {
        if (i < nums.size() && nums[i] <= miss) {
            miss += nums[i++];
        } else {
            miss += miss;
            added++;
        }
    }
    return added;
}

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxSumBeforeI = 0, needPatch = 0;
        for (int i = 0; maxSumBeforeI < n;) {
            if ( i < nums.size() && nums[i] <= maxSumBeforeI + 1) {
                maxSumBeforeI += nums[i];
                ++i;
            } else {
                needPatch++;
                maxSumBeforeI = 2 *  maxSumBeforeI + 1;
            }
        }
        return needPatch;
    }
};