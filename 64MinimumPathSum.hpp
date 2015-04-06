// 64 Minimum Path Sum 
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
// 
// Note: You can only move either down or right at any point in time.

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int m = grid.size();
		if (!m) return 0;
		int n = grid[0].size();
		if (!n) return 0;
		vector<vector<int>> matrix;
		matrix.resize(m);
		for (auto & row : matrix) row.resize(n);
		for (int i = 0; i < m; i++){
			matrix[i][0] = (i>0 ? matrix[i - 1][0] : 0) + grid[i][0];
		}
		for (int j = 0; j < n; j++){
			matrix[0][j] = (j>0 ? matrix[0][j - 1] : 0) + grid[0][j];
		}
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1]) + grid[i][j];
			}
		}
		return matrix[m - 1][n - 1];
	}
};