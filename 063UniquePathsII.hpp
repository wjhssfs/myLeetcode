// 63 Unique Paths II 
// Follow up for "Unique Paths":
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.
// Note: m and n will be at most 100.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) return 0;
        int n = obstacleGrid[0].size();
        if (!n) return 0;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m && obstacleGrid[i][0] != 1; i++) matrix[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] != 1; j++) matrix[0][j] = 1;
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if (obstacleGrid[i][j] == 1) continue;
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
        return matrix[m - 1][n - 1];
    }
};

public int uniquePathsWithObstacles(int[][] obstacleGrid) {
    int width = obstacleGrid[0].length;
    int[] dp = new int[width];
    dp[0] = 1;
    for (int[] row : obstacleGrid) {
        for (int j = 0; j < width; j++) {
            if (row[j] == 1)
                dp[j] = 0;
            else if (j > 0)
                dp[j] += dp[j - 1];
        }
    }
    return dp[width - 1];
}