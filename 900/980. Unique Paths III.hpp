// 980. Unique Paths III
// On a 2-dimensional grid, there are 4 types of squares:

// 1 represents the starting square.  There is exactly one starting square.
// 2 represents the ending square.  There is exactly one ending square.
// 0 represents empty squares we can walk over.
// -1 represents obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

// Example 1:

// Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
// Example 2:

// Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// Output: 4
// Explanation: We have the following four paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
// Example 3:

// Input: [[0,1],[2,0]]
// Output: 0
// Explanation: 
// There is no path that walks over every empty square exactly once.
// Note that the starting and ending square can be anywhere in the grid.
 

// Note:

// 1 <= grid.length * grid[0].length <= 20

class Solution {
    int count, tr, tc, sr, sc, rn;
    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r == grid.size() || c == grid[0].size() || grid[r][c] == -1 || grid[r][c] == 3) return;
        if (r == tr && c == tc && !rn) {
            ++count;
            return;
        }
        auto b = grid[r][c];
        if (b == 0) --rn;
        grid[r][c] = 3;
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
        grid[r][c] = b;
        if (b == 0) ++rn;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int c = grid[i][j];
                if (c == 0) ++rn;
                else if (c == 2) tr = i, tc = j;
                else if (c == 1) sr = i, sc = j;
            }
        }
        dfs(grid, sr, sc);
        return count;
    }
};