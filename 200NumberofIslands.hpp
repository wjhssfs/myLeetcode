// 200 Number of Islands 
// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// 11110
// 11010
// 11000
// 00000
// Answer: 1

// Example 2:

// 11000
// 11000
// 00100
// 00011
// Answer: 3

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size() || !grid[0].size()) return 0;
        int nIsland = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    nIsland++;
                    dfsMark(grid, i, j);
                }
            }
        }
        return nIsland;
    }
    
    void dfsMark(vector<vector<char>>& grid, int x, int y){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1') return;
        grid[x][y] = '2';
        dfsMark(grid, x-1, y);
        dfsMark(grid, x+1, y);
        dfsMark(grid, x, y-1);
        dfsMark(grid, x, y+1);
    }
};
