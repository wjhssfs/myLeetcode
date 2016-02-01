// 329. Longest Increasing Path in a Matrix

// Given an integer matrix, find the length of the longest increasing path.

// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

// Example 1:

// nums = [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ]
// Return 4
// The longest increasing path is [1, 2, 6, 9].

// Example 2:

// nums = [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ]
// Return 4
// The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        if (!m) return 0;
        int n = (int)matrix[0].size();
        if (!n) return 0;
        vector<vector<int>> maxLenTable(m, vector<int>(n));
        int maxL = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(matrix, i, j, maxLenTable);
                maxL = max(maxL, maxLenTable[i][j]);
            }
        }
        return maxL;
    }
private:
    void dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& maxLenTable) {
        if (maxLenTable[r][c] != 0)
            return;
        maxLenTable[r][c] = -1;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int maxLenNext = 0;
        int d[] = { 0, 1, 0, -1, 0 };
        for (int i = 0; i < 4; i++) {
            int nR = r + d[i], nC = c + d[i + 1];
            if (nR < 0 || nR >= m || nC < 0 || nC >= n)
                continue;
            if (matrix[r][c] >= matrix[nR][nC])
                continue;
            dfs(matrix, nR, nC, maxLenTable);
            int nextL = maxLenTable[nR][nC];
            maxLenNext = max(maxLenNext, nextL);
        }
        
        maxLenTable[r][c] = maxLenNext + 1;
        return;
    }
};