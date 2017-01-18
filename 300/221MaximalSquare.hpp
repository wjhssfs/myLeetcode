// 221 Maximal Square
// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
// For example, given the following matrix:
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 4.

// https://leetcode.com/discuss/38489/easy-solution-with-detailed-explanations-8ms-time-and-space
// preDp[i-1]        preDp[i] = dp[ic](cur)
// dp[ic-1](cur)     dp[ic](next)
// dp[ic](next) = min(dp[ic], dp[ic-1], preDP[i-1]) + 1
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int nr = matrix.size(); if (nr == 0) return 0;
    int nc = matrix[0].size(); if (nc == 0) return 0;

    vector<int> dp(nc+1, 0);
    int maxsize = 0;
    int last_topleft = 0;  // This is 'preDp[i-1]' for the current element

    for (int ir = 1; ir <= nr; ++ir) {
        for (int ic = 1; ic <= nc; ++ic) {
            int temp = dp[ic];      // This is 'preDp[i-1]' for the next element                
             if (matrix[ir-1][ic-1] == '0') dp[ic] = 0; 
            else {
                dp[ic] = min(min(dp[ic], dp[ic-1]), last_topleft) + 1;
                maxsize = max(maxsize, dp[ic]);
            }
            last_topleft = temp;  // update 'preDp[i-1]'
        }
    }
    return maxsize * maxsize;
  }
};

public int maximalSquare(char[][] a) {
  if (a == null || a.length == 0 || a[0].length == 0)
    return 0;

  int max = 0, n = a.length, m = a[0].length;

  // dp(i, j) represents the length of the square 
  // whose lower-right corner is located at (i, j)
  // dp(i, j) = min{ dp(i-1, j-1), dp(i-1, j), dp(i, j-1) }
  int[][] dp = new int[n + 1][m + 1];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1][j - 1] == '1') {
        dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
        max = Math.max(max, dp[i][j]);
      }
    }
  }

  // return the area
  return max * max;
}
