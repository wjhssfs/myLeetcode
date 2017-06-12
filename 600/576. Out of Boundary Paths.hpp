// 576. Out of Boundary Paths
// There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

// Example 1:
// Input:m = 2, n = 2, N = 2, i = 0, j = 0
// Output: 6
// Explanation:

// Example 2:
// Input:m = 1, n = 3, N = 3, i = 0, j = 1
// Output: 12
// Explanation:

// Note:
// Once you move the ball out of boundary, you cannot move it back.
// The length and height of the grid is in range [1,50].
// N is in range [0,50].

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int base = pow(10, 9) + 7, res = 0;
        vector<vector<int>> g(m, vector<int>(n));
        g[i][j] = 1;
        for (int t = 0; t < N; ++t) {
            vector<vector<int>> gn(m, vector<int>(n));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    vector<int> d{-1, 0, 1, 0, -1};
                    for (int k = 0; k < 4; ++k) {
                        int ip = i + d[k], jp = j + d[k + 1];
                        if (ip < 0 || jp < 0 || ip == m || jp == n) res = (res + g[i][j]) % base;
                        else gn[ip][jp] = (gn[ip][jp] + g[i][j]) % base;
                    }
                }
            }
            swap(g, gn);
        }
        return res;
    }
};

// The number of paths for N moves is the sum of paths for N - 1 moves from the adjacent cells.
// If an adjacent cell is out of the border, the number of paths is 1.
int findPaths(int m, int n, int N, int i, int j) {
  uint dp[51][50][50] = {};
  for (auto Ni = 1; Ni <= N; ++Ni)
    for (auto mi = 0; mi < m; ++mi)
      for (auto ni = 0; ni < n; ++ni)
        dp[Ni][mi][ni] = ((mi == 0 ? 1 : dp[Ni - 1][mi - 1][ni]) + (mi == m - 1? 1 : dp[Ni - 1][mi + 1][ni])
            + (ni == 0 ? 1 : dp[Ni - 1][mi][ni - 1]) + (ni == n - 1 ? 1 : dp[Ni - 1][mi][ni + 1])) % 1000000007;
  return dp[N][i][j];
}