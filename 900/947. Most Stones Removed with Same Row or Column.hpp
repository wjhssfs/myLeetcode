// 947. Most Stones Removed with Same Row or Column

// On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

// Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

// What is the largest possible number of moves we can make?

 

// Example 1:

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Example 2:

// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
// Example 3:

// Input: stones = [[0,0]]
// Output: 0
 

// Note:

// 1 <= stones.length <= 1000
// 0 <= stones[i][j] < 10000

class Solution {
    int find(vector<int>&p, int i) {
        if (p[i] != i) p[i] = find(p, p[i]);
        return p[i];
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int m = 0, n = 0, res = 0;
        for (auto&& stone : stones) m = max(m, stone[0]), n = max(n, stone[1]);
        ++m, ++n;
        vector<int> sz(m + n), p(m + n); // rows + cols
        iota(begin(p), end(p), 0);
        for (auto&& stone : stones) {
            int p0 = find(p, stone[0]);
            int p1 = find(p, stone[1] + m);
            if (p0 != p1) {
                p[p0] = p1;
                sz[p1] += sz[p0];
            }
            ++sz[p[p0]];
        }
        for (int i = 0; i < m + n; ++i) if (p[i] == i) res += max(0, sz[i] - 1);
        return res;
    }
};