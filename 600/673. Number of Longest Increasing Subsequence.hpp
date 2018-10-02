// 673. Number of Longest Increasing Subsequence

// Given an unsorted array of integers, find the number of longest increasing subsequence.

// Example 1:
// Input: [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
// Example 2:
// Input: [2,2,2,2,2]
// Output: 5
// Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
// Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.

class Solution {
public:
    int findNumberOfLIS(const vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<vector<pair<int, int>>> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.empty() || nums[i] > s.back().back().first) s.push_back({make_pair(nums[i], i)});
            else {
                for (int j = 0; j < s.size(); ++j) {
                    if (nums[i] > s[j].back().first) continue;
                    s[j].emplace_back(nums[i], i); break;
                }
            }
        }
        return dfs(s, (int)s.size() - 1, INT_MAX, INT_MAX);
    }
    
    int dfs(vector<vector<pair<int, int>>>& s, int cur, int nextV, int nextIndex) {
        if (cur < 0) return 1;
        int sum = 0;
        for (auto&& can : s[cur]) {
            if (can.first  < nextV && can.second < nextIndex) {
                sum += dfs(s, cur - 1, can.first, can.second);
            }
        }
        return sum;
    }
};

 int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0, max_len = 0;
        vector<pair<int,int>> dp(n,{1,1});            //dp[i]: {length, number of LIS which ends with nums[i]}
        for(int i = 0; i<n; i++){
            for(int j = 0; j <i ; j++){
                if(nums[i] > nums[j]){
                    if(dp[i].first == dp[j].first + 1)dp[i].second += dp[j].second;
                    if(dp[i].first < dp[j].first + 1)dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
            if(max_len == dp[i].first)res += dp[i].second;
            if(max_len < dp[i].first){
                max_len = dp[i].first;
                res = dp[i].second;
            }
        }
        return res;
    }