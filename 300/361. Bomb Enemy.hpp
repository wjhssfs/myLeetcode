// 361. Bomb Enemy

// Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
// The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
// Note that you can only put the bomb at an empty cell.

// Example:
// For the given grid

// 0 E 0 0
// E 0 W E
// 0 E 0 0

// return 3. (Placing a bomb at (1,1) kills 3 enemies)

// https://discuss.leetcode.com/topic/48565/short-o-mn-solution
int maxKilledEnemies(vector<vector<char>>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0;
    int result = 0, rowhits, colhits[n];
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (!j || grid[i][j-1] == 'W') {
                rowhits = 0;
                for (int k=j; k<n && grid[i][k] != 'W'; k++)
                    rowhits += grid[i][k] == 'E';
            }
            if (!i || grid[i-1][j] == 'W') {
                colhits[j] = 0;
                for (int k=i; k<m && grid[k][j] != 'W'; k++)
                    colhits[j] += grid[k][j] == 'E';
            }
            if (grid[i][j] == '0')
                result = max(result, rowhits + colhits[j]);
        }
    }
    return result;
}

class Solution {
public:
	int maxKilledEnemies(vector<vector<char>>& grid) {
    	int m = grid.size();
		if (!m) return 0;
		int n = grid[0].size();
		vector<vector<int>> hCount(m, vector<int>(n)), vCount(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			int start = 0, nE = 0;
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 'E') ++nE;
				if (grid[i][j] == 'W' || j == n - 1) {
					int end = grid[i][j] == 'W' ? j - 1 : j;
					for (int k = start; k <= end; ++k) {
						hCount[i][k] = nE;
					}
					start = j + 1;
					nE = 0;
				}
			}
		}
		for (int j = 0; j < n; ++j) {
			int start = 0, nE = 0;
			for (int i = 0; i < m; ++i) {
				if (grid[i][j] == 'E') ++nE;
				if (grid[i][j] == 'W' || i == m - 1) {
					int end = grid[i][j] == 'W' ? i - 1 : i;
					for (int k = start; k <= end; ++k) {
						vCount[k][j] = nE;
					}
					start = i + 1;
					nE = 0;
				}
			}
		}
		int nMax = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] != '0') continue;
				nMax = max(nMax, hCount[i][j] + vCount[i][j]);
			}
		}
		return nMax;
	}
};