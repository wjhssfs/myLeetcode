// 581. Shortest Unsorted Continuous Subarray
// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

// You need to find the shortest such subarray and output its length.

// Example 1:
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Note:
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        int s = 0, e = nums.size() - 1;
        while (s < nums.size() && nums[s] == sortedNums[s]) ++s;
        while (e >= 0 && nums[e] == sortedNums[e]) --e;
        return e >= s ? e - s + 1 : 0;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), beg = -1, end = -1, l = nums[n-1], h = nums[0];
        for (int i=1;i<n;i++) {
          h = max(h, nums[i]);
          l = min(l, nums[n-1-i]);
          if (nums[i] < h) end = i;
          if (nums[n-1-i] > l) beg = n-1-i; 
        }
        return end == -1 ? 0 : end - beg + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s = 1;
        while (s < nums.size() && nums[s-1] <= nums[s]) ++s;
        if (s >= nums.size()) return 0;
        int v = nums[s];
        for (int i = s + 1; i < nums.size(); ++i) v = min(v, nums[i]);
        s = 0;
        while (nums[s] <= v) ++s;
        int e = nums.size() - 1;
        while (e - 1 >= 0 && nums[e - 1] <= nums[e]) --e;
        v = nums[e - 1];
        for (int i = e - 2; i >= 0; --i) v = max(v, nums[i]);
        e = nums.size() - 1;
        while (nums[e] >= v) --e;
        return e - s + 1;
    }
};