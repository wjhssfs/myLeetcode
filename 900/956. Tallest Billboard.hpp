// 956. Tallest Billboard

// You are installing a billboard and want it to have the largest height.  The billboard will have two steel supports, one on each side.  Each steel support must be an equal height.

// You have a collection of rods which can be welded together.  For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

// Return the largest possible height of your billboard installation.  If you cannot support the billboard, return 0.

 

// Example 1:

// Input: [1,2,3,6]
// Output: 6
// Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
// Example 2:

// Input: [1,2,3,4,5,6]
// Output: 10
// Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
// Example 3:

// Input: [1,2]
// Output: 0
// Explanation: The billboard cannot be supported, so we return 0.
 

// Note:

// 0 <= rods.length <= 20
// 1 <= rods[i] <= 1000
// The sum of rods is at most 5000.

// https://leetcode.com/problems/tallest-billboard/discuss/203261/Java-knapsack-O(N*sum)

class Solution {
public:
	int tallestBillboard(vector<int>& rods) {
		vector<vector<bool>> dp(rods.size() + 1, vector<bool>(10001));
		vector<vector<int>> m(rods.size() + 1, vector<int>(10001));
		dp[0][5000] = true;
		for (int i = 0; i < rods.size(); ++i) {
			for (int j = 0; j < 10001; ++j) {
				if (j - rods[i] >= 0 && dp[i][j - rods[i]]) {
					m[i + 1][j] = max(m[i + 1][j], m[i][j - rods[i]] + rods[i]);
					dp[i + 1][j] = true;
				}
				if (dp[i][j]) {
					m[i + 1][j] = max(m[i + 1][j], m[i][j]);
					dp[i + 1][j] = true;
				}
				if (j + rods[i] <= 10000 && dp[i][j + rods[i]]) {
					m[i + 1][j] = max(m[i + 1][j], m[i][j + rods[i]]);
					dp[i + 1][j] = true;
				}
			}
		}
		return m[rods.size()][5000];
	}
};