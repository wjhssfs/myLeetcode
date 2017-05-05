// 548. Split Array with Equal Sum
// Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

// 0 < i, i + 1 < j, j + 1 < k < n - 1
// Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
// where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.
// Example:
// Input: [1,2,1,2,1,2,1]
// Output: True
// Explanation:
// i = 1, j = 3, k = 5. 
// sum(0, i - 1) = sum(0, 0) = 1
// sum(i + 1, j - 1) = sum(2, 2) = 1
// sum(j + 1, k - 1) = sum(4, 4) = 1
// sum(k + 1, n - 1) = sum(6, 6) = 1
// Note:
// 1 <= n <= 2000.
// Elements in the given array will be in range [-1,000,000, 1,000,000].

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if (nums.size() < 7) return false;
        for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i-1];
        for (int j = 3; j < nums.size() - 3; ++j) {
            unordered_set<int> s;
            for (int i = 1; i < j - 1; ++i) {
                if (nums[i-1] == nums[j-1] - nums[i]) s.insert(nums[i-1]);
            }
            for (int k = j + 2; k < nums.size() - 1; ++k){
                if (nums.back() - nums[k] == nums[k-1] - nums[j] && s.count(nums.back() - nums[k])) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if (nums.size() < 7) return false;
        for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i-1];
        for (int i = 1; i < nums.size(); ++i) {
            if (dfs(nums, i + 1, nums[i-1], 1)) return true;
        }
        return false;
    }
private:
    bool dfs(vector<int>& nums, int start, int g, int n) {
        for (int i = start + 1; i < nums.size(); ++i) {
            int s = nums[i-1] - nums[start - 1];
            if (s != g) continue;
            if (n == 2) return nums.back() - nums[i] == g;
            if (dfs(nums, i + 1, g, n + 1)) return true;
        }
        return false;
    }
};

