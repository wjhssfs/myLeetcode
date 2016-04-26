// 200 Number of Islands 
// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water
// and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
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



//  only need to do it for two directions, which are "right" and "down", because all "left" and "up" has already been seen if exists connection (undirected for Union Find).
class UF {
public int count = 0;
public int[] id = null;

public UF(int m, int n, char[][] grid) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') count++;
        }
    }
    id = new int[m * n];
    for(int i = 0; i < m * n; i++) {
        id[i] = i;
    }
}

public int find(int p) {
    while(p != id[p]) {
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

public boolean isConnected(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if(pRoot != qRoot) return false;
    else return true;
}

public void union(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if(pRoot == qRoot) return;
    id[pRoot] = qRoot;
    count--;
}
}

public int numIslands(char[][] grid) {
    if(grid.length == 0 || grid[0].length == 0) return 0;
    int m = grid.length, n = grid[0].length;
    UF uf = new UF(m , n, grid);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '0') continue;
            int p = i * n + j;
            int q;
            if(i > 0 && grid[i - 1][j] == '1') {
                q = p - n;
                uf.union(p, q);
            }
            if(i < m - 1 && grid[i + 1][j] == '1') {
                q = p + n;
                uf.union(p, q);
            }
            if(j > 0 && grid[i][j - 1] == '1') {
                q = p - 1;
                uf.union(p, q);
            }
            if(j < n - 1 && grid[i][j + 1] == '1') {
                q = p + 1;
                uf.union(p, q);
            }
        }
    }
    return uf.count;
}