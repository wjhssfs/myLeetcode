// 959. Regions Cut By Slashes
// In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

// (Note that backslash characters are escaped, so a \ is represented as "\\".)

// Return the number of regions.

 

// Example 1:

// Input:
// [
//   " /",
//   "/ "
// ]
// Output: 2
// Explanation: The 2x2 grid is as follows:

// Example 2:

// Input:
// [
//   " /",
//   "  "
// ]
// Output: 1
// Explanation: The 2x2 grid is as follows:

// Example 3:

// Input:
// [
//   "\\/",
//   "/\\"
// ]
// Output: 4
// Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
// The 2x2 grid is as follows:

// Example 4:

// Input:
// [
//   "/\\",
//   "\\/"
// ]
// Output: 5
// Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
// The 2x2 grid is as follows:

// Example 5:

// Input:
// [
//   "//",
//   "/ "
// ]
// Output: 3
// Explanation: The 2x2 grid is as follows:

 

// Note:

// 1 <= grid.length == grid[0].length <= 30
// grid[i][j] is either '/', '\', or ' '.

class Solution {
    struct UnionFind {
        UnionFind(int sz) : p(sz) {
            for (int i = 0; i < sz; ++i) p[i] = i;
        };
        int find(int c) {
            if (p[c] != c) p[c] = find(p[c]);
            return p[c];
        }
        void connect(int x, int y) {
            //if (x < 0 || y < 0 || x >= p.size() || y >= p.size()) return;
            //cout << x << " " << y << endl;
            p[find(x)] = find(y);
            //cout << p[find(x)] << endl;
        }
        vector<int> p;
    };
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UnionFind uf(n * n * 4);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j > 0)
                    uf.connect(4 * (i * n + j), (i * n + j - 1) * 4 + 2);
                if (i > 0)
                    uf.connect(4 * (i * n + j) + 1, (i * n + j - n) * 4 + 3);
                if (grid[i][j] == ' ') {
                    uf.connect(4 * (i * n + j), 4 * (i * n + j) + 1);
                    uf.connect(4 * (i * n + j), 4 * (i * n + j) + 2);
                    uf.connect(4 * (i * n + j), 4 * (i * n + j) + 3);
                } else if (grid[i][j] == '/') {
                    uf.connect(4 * (i * n + j), 4 * (i * n + j) + 1);
                    uf.connect(4 * (i * n + j) + 2, 4 * (i * n + j) + 3);
                } else {
                    uf.connect(4 * (i * n + j), 4 * (i * n + j) + 3);
                    uf.connect(4 * (i * n + j) + 1, 4 * (i * n + j) + 2);
                }
            }
        }
        unordered_set<int> t;
        for (int i = 0; i < n * n * 4; ++i) {
            t.insert(uf.find(i));
        }
        return t.size();
    }
};

class Solution {
public:
   int count, n;
   vector<int> f;
   int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        count = n * n * 4;
        for (int i = 0; i < n * n * 4; ++i)
            f.push_back(i);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) uni(g(i - 1, j, 2), g(i, j, 0));
                if (j > 0) uni(g(i , j - 1, 1), g(i , j, 3));
                if (grid[i][j] != '/') {
                    uni(g(i , j, 0), g(i , j,  1));
                    uni(g(i , j, 2), g(i , j,  3));
                }
                if (grid[i][j] != '\\') {
                    uni(g(i , j, 0), g(i , j,  3));
                    uni(g(i , j, 2), g(i , j,  1));
                }
            }
        }
        return count;
    }

    int find(int x) {
        if (x != f[x]) {
            f[x] = find(f[x]);
        }
        return f[x];
    }
    void uni(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            f[x] = y;
            count--;
        }
    }
    int g(int i, int j, int k) {
        return (i * n + j) * 4 + k;
    }
};

// https://leetcode.com/problems/regions-cut-by-slashes/discuss/205674/C++-with-picture-DFS-on-upscaled-grid