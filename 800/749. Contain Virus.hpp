// 749. Contain Virus

// A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

// The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

// Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night. There will never be a tie.

// Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return the number of walls used.

// Example 1:
// Input: grid = 
// [[0,1,0,0,0,0,0,1],
//  [0,1,0,0,0,0,0,1],
//  [0,0,0,0,0,0,0,1],
//  [0,0,0,0,0,0,0,0]]
// Output: 10
// Explanation:
// There are 2 contaminated regions.
// On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

// [[0,1,0,0,0,0,1,1],
//  [0,1,0,0,0,0,1,1],
//  [0,0,0,0,0,0,1,1],
//  [0,0,0,0,0,0,0,1]]

// On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
// Example 2:
// Input: grid = 
// [[1,1,1],
//  [1,0,1],
//  [1,1,1]]
// Output: 4
// Explanation: Even though there is only one cell saved, there are 4 walls built.
// Notice that walls are only built on the shared boundary of two different cells.
// Example 3:
// Input: grid = 
// [[1,1,1,0,0,0,0,0,0],
//  [1,0,1,0,1,1,1,1,1],
//  [1,1,1,0,0,0,0,0,0]]
// Output: 13
// Explanation: The region on the left only builds two new walls.
// Note:
// The number of rows and columns of grid will each be in the range [1, 50].
// Each grid[i][j] will be either 0 or 1.
// Throughout the described process, there is always a contiguous viral region that will infect strictly more uncontaminated squares in the next round.

template<typename Ctnr, typename Func>
inline void for_4neighbors(const Ctnr &ctnr, int row, int col, Func func) {
    if (row - 1 >= 0)
        func(row - 1, col);
    if (row + 1 < ctnr.size())
        func(row + 1, col);
    if (col - 1 >= 0)
        func(row, col - 1);
    if (col + 1 < ctnr[0].size())
        func(row, col + 1);
}
class Solution {
public:
	int containVirus(vector<vector<int>>& g) {
	    int res = 0, c = 1; // c increments for visited cells

	    while (true) {
	        // tuple components: walls, inside coords with value c, border coords with value 0
	        vector<tuple<int, vector<pair<int, int>>, set<pair<int, int>>>> areas;
	        int mx = 0, idx;

	        for (int i = 0; i < g.size(); i++) {
	            for (int j = 0; j < g[0].size(); j++) {
	                if (g[i][j] == c) {
	                    areas.resize(areas.size() + 1); // found a new area

	                    int &walls = get<0>(areas.back());
	                    auto &inside = get<1>(areas.back());
	                    auto &border = get<2>(areas.back());

	                    g[i][j] = c + 1; // mark as visited
	                    inside.emplace_back(i, j);

	                    queue<pair<int, int>> q;
	                    q.emplace(i, j);

	                    while (!q.empty()) {
	                        int x, y;
	                        tie(x, y) = q.front();
	                        q.pop();

	                        for_4neighbors(g, x, y, [&](int a, int b) {
	                            if (g[a][b] == c) {
	                                q.emplace(a, b);
	                                g[a][b] = c + 1; // mark as visited
	                                inside.emplace_back(a, b);
	                            } else if (g[a][b] == 0) {
	                                border.emplace(a, b);
	                                walls++;
	                            }
	                        });
	                    }

	                    if (border.size() > mx) {
	                        mx = border.size();
	                        idx = areas.size() - 1;
	                    }
	                }
	            }
	        }

	        if (mx == 0) break;
	        c++; // all visited viruses are back

	        for (auto &p : get<1>(areas[idx]))
	            g[p.first][p.second] = -1; // mark as dead
	        get<2>(areas[idx]).clear(); // dead viruses no longer spread

	        for (auto &a : areas)
	            for (auto &p : get<2>(a))
	                g[p.first][p.second] = c; // mark as contaminated

	        res += get<0>(areas[idx]);
	    }

	    return res;
	}
};

class Solution2{
public:
    int containVirus(vector<vector<int>>& grid) {
        int ans = 0;
        while (true) {
            int walls = model(grid);
            if (walls == 0) break;
            ans += walls;
        }
        return ans;
    }
private:
    int model(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), N = 100;
        vector<unordered_set<int>> virus, toInfect;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<int> walls;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    virus.push_back(unordered_set<int>());
                    toInfect.push_back(unordered_set<int>());
                    walls.push_back(0);
                    dfs(grid, visited, virus.back(), toInfect.back(), walls.back(), i, j);
                }
            }
        }
        int maxArea = 0, idx = -1;
        for (int i = 0; i < toInfect.size(); i++) {
            if (toInfect[i].size() > maxArea) {
                maxArea = toInfect[i].size();
                idx = i;
            }
        }
        if (idx == -1) return 0;
        for (int i = 0; i < toInfect.size(); i++) {
            if (i != idx) {
                for (int key : toInfect[i]) 
                    grid[key/N][key%N] = 1;
            }
            else {
                for (int key: virus[i]) 
                    grid[key/N][key%N] = -1;
            }
        }
        return walls[idx];
    }
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, unordered_set<int>& virus, unordered_set<int>& toInfect, int& wall, int row, int col) {
        int m = grid.size(), n = grid[0].size(), N = 100;
        if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] == 1) return;
        if (grid[row][col] == 1) {
            visited[row][col] = 1;
            virus.insert(row*N + col);
            vector<int> dir = {0, -1, 0, 1, 0};
            for (int i = 0; i < 4; i++)
                dfs(grid, visited, virus, toInfect, wall, row+dir[i], col+dir[i+1]);
        }
        else if (grid[row][col] == 0) {
            wall++;
            toInfect.insert(row*N + col);
        }
    }
};

class Solution3 {
public:
    enum class Mode {Count, Clear, Spread};
    pair<int, int> dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited, Mode mode) {
        int cell = 0, wall = 0;
        int d[] = {-1, 0, 1, 0, -1};
        visited[i][j] = true;
        grid[i][j] = mode == Mode::Clear ? -1 : 1;
        for (int k = 0; k < 4; ++k) {
            int ni = i + d[k], nj = j + d[k + 1];
            if (ni < 0 || nj < 0 || ni == grid.size() || nj == grid[0].size()) continue;
            if (grid[ni][nj] == 0) {
                ++wall;
                if (!visited[ni][nj]) ++cell;
                if (mode == Mode::Spread) grid[ni][nj]  = 1;
                visited[ni][nj] = true;
                continue;
            }
            if (grid[ni][nj]  == 1 && !visited[ni][nj]) {
                auto sub = dfs(grid, ni, nj, visited, mode);
                cell += sub.first;
                wall += sub.second;
            }
        }
        return make_pair(cell, wall);
    }
public:
    int containVirus(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        vector<vector<int>> visitedEmpty(m, vector<int>(n, false));
        int total = 0;
        while (1) {
            pair<int, int> maxR(-1, -1), maxPos;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1) {
                        auto visited = visitedEmpty;
                        auto sub = dfs(grid, i, j, visited, Mode::Count);
                        if (sub.first > maxR.first) {
                            maxR = sub;
                            maxPos = make_pair(i, j);
                        }
                    }
                }
            }
            if (maxR.first == -1) return total;
            total += maxR.second;
            auto visited = visitedEmpty;
            dfs(grid, maxPos.first, maxPos.second, visited, Mode::Clear);
            visited = visitedEmpty; // outside of loop so won't spread from cell spreaded from other region
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        dfs(grid, i, j, visited, Mode::Spread);
                    }
                }
            }
        }
        return total;
    }
};