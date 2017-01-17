// 417. Pacific Atlantic Water Flow

// Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

// Note:
// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.
// Example:

// Given the following 5x5 matrix:

//   Pacific ~   ~   ~   ~   ~ 
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * Atlantic

// Return:

// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        int m = matrix.size();
        if (!m) return result;
        int n = matrix[0].size();
        if (!n) return result;
        vector<vector<char>> pFlags(m, vector<char>(n, 0)), aFlags(pFlags);
        for (int i = 0; i < matrix.size(); ++i) {
            DFS(matrix, pFlags, i, 0, matrix[i][0]);
            DFS(matrix, aFlags, i, n-1, matrix[i][n-1]);
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            DFS(matrix, pFlags, 0, i, matrix[0][i]);
            DFS(matrix, aFlags, m-1, i, matrix[m-1][i]);
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (pFlags[i][j] && aFlags[i][j]) {
                    result.emplace_back(i, j);
                }
            }
        }
        return result;
    }
    void DFS(vector<vector<int>>& matrix, vector<vector<char>> &flags, int x, int y, int v) {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || flags[x][y] || matrix[x][y] < v) return;
        flags[x][y] = 1;
        v = matrix[x][y];
        DFS(matrix, flags, x-1, y, v);
        DFS(matrix, flags, x+1, y, v);
        DFS(matrix, flags, x, y-1, v);
        DFS(matrix, flags, x, y+1, v);
    }
};