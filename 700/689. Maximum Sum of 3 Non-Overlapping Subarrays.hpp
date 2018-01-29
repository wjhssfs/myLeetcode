// 689. Maximum Sum of 3 Non-Overlapping Subarrays
// In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

// Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

// Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

// Example:
// Input: [1,2,1,2,6,7,5,1], 2
// Output: [0, 3, 5]
// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
// We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
// Note:
// nums.length will be between 1 and 20000.
// nums[i] will be between 1 and 65535.
// k will be between 1 and floor(nums.length / 3).

class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<int> kSum(nums.size() - k + 1);
		for (int i = 0; i < k; ++i) kSum[0] += nums[i];
		for (int i = 1; i < kSum.size(); ++i) kSum[i] = kSum[i - 1] + nums[k + i - 1] - nums[i - 1];
		vector<vector<int>> p(2, vector<int>(sum.size(), -1)); // previous index
		vector<int> dp = kSum;
		for (int i = 0; i < 2; ++i) {
			vector<int> newDp(sum.size(), 0);
			int bestI = 0;
			for (int j = k + k * i; j < kSum.size(); ++j) {
				if (dp[j - k] > dp[bestI]) bestI = j - k;
				newDp[j] = dp[bestI] + kSum[j];
				p[i][j] = bestI;
			}
			swap(dp, newDp);
		}
		int i = max_element(dp.begin(), dp.end()) - dp.begin();
		return { p[0][p[1][i]], p[1][i], i};
	}
};

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), maxsum = 0;
        vector<int> sum = {0}, posLeft(n, 0), posRight(n, n-k), ans(3, 0);
        for (int i:nums) sum.push_back(sum.back()+i);
       // DP for starting index of the left max sum interval
        for (int i = k, tot = sum[k]-sum[0]; i < n; i++) {
            if (sum[i+1]-sum[i+1-k] > tot) {
                posLeft[i] = i+1-k;
                tot = sum[i+1]-sum[i+1-k];
            }
            else 
                posLeft[i] = posLeft[i-1];
        }
        // DP for starting index of the right max sum interval
        // caution: the condition is ">= tot" for right interval, and "> tot" for left interval
        for (int i = n-k-1, tot = sum[n]-sum[n-k]; i >= 0; i--) {
            if (sum[i+k]-sum[i] >= tot) {
                posRight[i] = i;
                tot = sum[i+k]-sum[i];
            }
            else
                posRight[i] = posRight[i+1];
        }
        // test all possible middle interval
        for (int i = k; i <= n-2*k; i++) {
            int l = posLeft[i-1], r = posRight[i+k];
            int tot = (sum[i+k]-sum[i]) + (sum[l+k]-sum[l]) + (sum[r+k]-sum[r]);
            if (tot > maxsum) {
                maxsum = tot;
                ans = {l, i, r};
            }
        }
        return ans;
    }
};


