// 694. Number of Distinct Islands

// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

// Example 1:
// 11000
// 11000
// 00011
// 00011
// Given the above grid map, return 1.
// Example 2:
// 11011
// 10000
// 00001
// 11011
// Given the above grid map, return 3.

// Notice that:
// 11
// 1
// and
//  1
// 11
// are considered different island shapes, because we do not consider reflection / rotation.
// Note: The length of each dimension in the given grid does not exceed 50.

class Solution {
	void dfs(vector<vector<int>>& grid, int i, int j, int s, int di, string& cur) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
		if (grid[i][j] != 1) return;
		cur += "|" + to_string(s) + "," + to_string(di);
		grid[i][j] = 2;
		int d[] = { -1, 0, 1, 0, -1 };
		for (int k = 0; k < 4; ++k) {
			dfs(grid, i + d[k], j + d[k + 1], s + 1, k, cur);
		}
	}
public:
	int numDistinctIslands(vector<vector<int>>& grid) {
		unordered_set<string> m;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				string cur;
				dfs(grid, i, j, 0, 0, cur);
				if (cur.size()) m.insert(cur);
			}
		}
		return m.size();
	}
};