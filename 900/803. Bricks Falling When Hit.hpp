// 803. Bricks Falling When Hit
// We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will not drop if and only if it is directly connected to the top of the grid, or at least one of its (4-way) adjacent bricks will not drop.

// We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j), the brick (if it exists) on that location will disappear, and then some other bricks may drop because of that erasure.

// Return an array representing the number of bricks that will drop after each erasure in sequence.

// Example 1:
// Input: 
// grid = [[1,0,0,0],[1,1,1,0]]
// hits = [[1,0]]
// Output: [2]
// Explanation: 
// If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
// Example 2:
// Input: 
// grid = [[1,0,0,0],[1,1,0,0]]
// hits = [[1,1],[1,0]]
// Output: [0,0]
// Explanation: 
// When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move. So each erasure will cause no bricks dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.
 

// Note:

// The number of rows and columns in the grid will be in the range [1, 200].
// The number of erasures will not exceed the area of the grid.
// It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
// An erasure may refer to a location with no brick - if it does, no bricks drop.

// https://leetcode.com/problems/bricks-falling-when-hit/discuss/119829/Python-Solution-by-reversely-adding-hits-bricks-back
class Solution {
    // Mark grid[i][j] as connected to top with value 2
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1) return 0;
        grid[i][j] = 2;
        int ret = 1;
        for (auto && r : vector<vector<int>>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) ret += dfs(grid, r[0], r[1]);
        return ret;
    }
    bool isConnected(vector<vector<int>>& grid, int i, int j) { // adding back (i,j) makes it connects
        if (i == 0) return true;
        for (auto && r : vector<vector<int>>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) {
            if (r[0] < 0 || r[1] < 0 || r[0] == grid.size() || r[1] == grid[0].size()) continue;
            if (grid[r[0]][r[1]] == 2) return true;
        }
        return false;
    }
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int> result(hits.size());
        for (auto&& h : hits) grid[h[0]][h[1]]--; // remove all hits
        for (int i = 0; i < grid[0].size(); ++i) dfs(grid, 0, i); // get final state for state 2 which is connected to top
        for (int k = (int)hits.size() - 1; k >= 0; --k) {
            auto h = hits[k];
            grid[h[0]][h[1]]++; // recover current hit, if it changes to 1 and is connected to cell with value 2, then dfs it
            // which change all 1 cells connected to it to 2
            if (grid[h[0]][h[1]] == 1 && isConnected(grid, h[0], h[1])) result[k] = dfs(grid, h[0], h[1]) - 1;
        }
        
        return result;
    }
};

class Solution:
    def hitBricks(self, grid, hits):
        """
        :type grid: List[List[int]]
        :type hits: List[List[int]]
        :rtype: List[int]
        """

        m, n = len(grid), len(grid[0])
        
        # Connect unconnected bricks and 
        def dfs(i, j):
            if not (0<=i<m and 0<=j<n) or grid[i][j]!=1:
                return 0
            ret = 1
            grid[i][j] = 2
            ret += sum(dfs(x, y) for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)])
            return ret
        
        # Check whether (i, j) is connected to Not Falling Bricks
        def is_connected(i, j):
            return i==0 or any([0<=x<m and 0<=y<n and grid[x][y]==2 for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]])
        
        # Mark whether there is a brick at the each hit
        for i, j in hits:
            grid[i][j] -= 1
                
        # Get grid after all hits
        for i in range(n):
            dfs(0, i)
        
        # Reversely add the block of each hits and get count of newly add bricks
        ret = [0]*len(hits)
        for k in reversed(range(len(hits))):
            i, j = hits[k]
            grid[i][j] += 1
            if grid[i][j]==1 and is_connected(i, j):
                ret[k] = dfs(i, j)-1
            
        return ret

// https://leetcode.com/problems/bricks-falling-when-hit/discuss/120057/C++-DFS-(similar-to-LC749)
when there is a hit, we change grid cell to 0.
we assign all the resulting connecting parts a unique id and judge if it falls.
for each falling parts, we count the number, reset the falling cell = 0.
++id (prepare to check another resulting parts of this run/start a new run of hit).
class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    vector<vector<int>> g;
    int vst[201][201], id;
    int n, m;
		
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size(),m = grid[0].size();
        g.swap(grid);
        vector<int> ret;
        for(auto h:hits){
            int r = h[0], c = h[1];
            int removal = 0;
            if(g[r][c] == 1){
                g[r][c] = 0;
                for(int d = 0;d<4;d++){
                    int x = r+dr[d],y = c + dc[d];
                    if (!valid(x, y) || !g[x][y]) continue;
                    ++id; //mark each connecting parts with a unique id in this run
                    if(falling(x,y)) removal += cnt(x,y);
                }
            }
            ret.push_back(removal);
        }
        return ret;
    }
    bool falling(int r,int c){
        if(!valid(r,c)||!g[r][c]) return true;
        if (vst[r][c] == id) return true; //visited and belongs to the same part this run
        if (r == 0) return false; //connecting 1st row
        vst[r][c] = id;
        for (int d = 0; d < 4; ++d){
            if (!falling(r + dr[d], c + dc[d])) return false;
        } 
        return true;
    }
    int cnt(int r,int c){
        if (!valid(r,c)||!g[r][c]) return 0;
        int ret = 1;
        g[r][c] = 0;
        for(int d = 0; d < 4; ++d){
            ret += cnt(r + dr[d], c + dc[d]);
        }
        return ret;
    }
    bool valid(int r,int c){
        return 0 <= r && r < n && 0 <= c && c < m;
    }
};