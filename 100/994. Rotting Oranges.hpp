// 994. Rotting Oranges
// In a given grid, each cell can have one of three values:

// the value 0 representing an empty cell;
// the value 1 representing a fresh orange;
// the value 2 representing a rotten orange.
// Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

// Example 1:



// Input: [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: [[0,2]]
// Output: 0
// Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Note:

// 1 <= grid.length <= 10
// 1 <= grid[0].length <= 10
// grid[i][j] is only 0, 1, or 2.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> newRotten;
        int nFresh = 0, step = 0;
        int d[] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) newRotten.emplace(i, j);
                else if (grid[i][j] == 1) ++nFresh;
            }
        }
        while (true) {
            for (int i = 0, sz = newRotten.size(); i < sz; ++i) {
                auto rotten = newRotten.front(); newRotten.pop();
                for (int k = 0; k < 4; ++k) {
                    int ii = rotten.first + d[k], jj = rotten.second + d[k + 1];
                    if (ii < 0 || jj < 0 || ii == grid.size() || jj == grid[0].size() || grid[ii][jj] != 1) continue;
                    grid[ii][jj] = 2;
                    newRotten.emplace(ii, jj);
                    --nFresh;
                }
            }
            if (newRotten.empty()) break;
            else ++step;
        }
                        
                           
        return nFresh ? -1 : step;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        bool changed = true;
        int d[] = {-1, 0, 1, 0, -1};
        while (1) {
            changed = false;
            vector<vector<int>> gridnext(grid);
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    if (grid[i][j] == 2) {
                        for (int k = 0; k < 4; ++k) {
                            int ii = i + d[k], jj = j + d[k + 1];
                            if (ii < 0 || jj < 0 || ii == grid.size() || jj == grid[0].size()) continue;
                            if (grid[ii][jj] == 1) {
                                changed = true;
                                gridnext[ii][jj] = 2;
                            }
                        }
                    }
                }
            }
            swap(grid, gridnext);
            if (!changed) break;
            else ++res;
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
};