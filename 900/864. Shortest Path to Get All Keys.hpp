// 864. Shortest Path to Get All Keys

// We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@" is the starting point, ("a", "b", ...) are keys, and ("A", "B", ...) are locks.

// We start at the starting point, and one move consists of walking one space in one of the 4 cardinal directions.  We cannot walk outside the grid, or walk into a wall.  If we walk over a key, we pick it up.  We can't walk over a lock unless we have the corresponding key.

// For some 1 <= K <= 6, there is exactly one lowercase and one uppercase letter of the first K letters of the English alphabet in the grid.  This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

// Return the lowest number of moves to acquire all keys.  If it's impossible, return -1.

 

// Example 1:

// Input: ["@.a.#","###.#","b.A.B"]
// Output: 8
// Example 2:

// Input: ["@..aA","..B#.","....b"]
// Output: 6
 

// Note:

// 1 <= grid.length <= 30
// 1 <= grid[0].length <= 30
// grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
// The number of keys is in [1, 6].  Each key has a different letter and opens exactly one lock.


class Solution {
public:
	int shortestPathAllKeys(vector<string>& grid) {
		int m = grid.size(), n = grid[0].size();
		int si = -1, sj = -1;
		char mc = 'a';
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '@') {
					si = i; sj = j;
				}
				else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
					mc = max(mc, grid[i][j]);
				}
			}
		}
		int mask = (1 << mc) - 1;
		queue<vector<int>> q;
		set<vector<int>> vistied;
		q.push({ 0, si, sj });
		vistied.insert(q.front());
		int step = 0;
		int d[] = { 0, 1, 0, -1, 0 };
		while (!q.empty())
		{
			++step;
			for (int i = 0, sz = q.size(); i < sz; ++i) {
				auto f = q.front(); q.pop();
                //cout << "from:" << f[1] << " " << f[2] << " " << f[0] << endl;
				for (int j = 0; j < 4; ++j) {
				    int key = f[0];
					int ni = f[1] + d[j], nj = f[2] + d[j + 1];
                    if (ni < 0 || nj < 0 || ni == m || nj == n) continue;
					char g = grid[ni][nj];
					if (g == '#' || (g >= 'A' && g <= 'Z' && (0 == (key & (1 << (g - 'A')))))) continue;
					if (g >= 'a' && g <= 'z') {
						key |= (1 << (g - 'a'));
					}
					if (key == mask) return step;
					vector<int> next{ key, ni, nj };
					if (vistied.count(next)) continue;
                    //cout << ni << " " << nj << " " << key << " " << g << endl;
                    vistied.insert(next);
					q.push(next);
				}
			}
		}
		return -1;
	};
};
