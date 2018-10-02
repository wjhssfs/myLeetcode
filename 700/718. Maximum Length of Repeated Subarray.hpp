// 718. Maximum Length of Repeated Subarray
// Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

// Example 1:
// Input:
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// Output: 3
// Explanation: 
// The repeated subarray with maximum length is [3, 2, 1].
// Note:
// 1 <= len(A), len(B) <= 1000
// 0 <= A[i], B[i] < 100

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), r = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i] == B[j]) {
                    dp[i][j] = ((i > 0 && j > 0) ? dp[i-1][j-1] : 0) + 1;
                } else {
                    dp[i][j] = 0;
                }
                r = max(r, dp[i][j]);
            }
        }
        return r;
    }
};