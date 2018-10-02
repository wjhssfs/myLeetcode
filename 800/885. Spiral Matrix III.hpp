// 885. Spiral Matrix III

// On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.

// Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

// Now, we walk in a clockwise spiral shape to visit every position in this grid. 

// Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 

// Eventually, we reach all R * C spaces of the grid.

// Return a list of coordinates representing the positions of the grid in the order they were visited.

// Example 1:

// Input: R = 1, C = 4, r0 = 0, c0 = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]

// Example 2:

// Input: R = 5, C = 6, r0 = 1, c0 = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]

// Note:

// 1 <= R <= 100
// 1 <= C <= 100
// 0 <= r0 < R
// 0 <= c0 < C

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> d {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res;
        res.push_back({r0, c0});
        int curD = 0;
        int r = r0, c = c0, len = 1;
        while (res.size() != R * C) {
            for (int t = 0; t < 2; ++t) {
                for (int i = 0; i < len; ++i) {
                    r += d[curD][0], c += d[curD][1];
                    //cout << r << " " << c << endl;
                    if (r < 0 || r >= R || c < 0 || c >= C) continue;
                    res.push_back({r, c});
                    if (res.size() == R * C) return res;
                }
                curD = (curD + 1) % 4;
            }
            ++len;
        }
        return res;
    }
};

// https://www.youtube.com/watch?v=qsgK1d-_8ik
// https://leetcode.com/problems/spiral-matrix-iii/discuss/158970/C++JavaPython-112233-Steps
// How to turn right?
// By cross product:
// Assume current direction is (x, y) in plane, which is (x, y, 0) in space.
// Then the direction after turn right (x, y, 0) × (0, 0, 1) = (y, -x, 0)
// Translate to code: tmp = x; x = y; y = -tmp;

   vector<vector<int>> spiralMatrixIII(int R, int C, int r, int c) {
        vector<vector<int>> res = {{r, c}};
        int x = 0, y = 1, tmp;
        for (int n = 0; res.size() < R * C; n++) {
            for (int i = 0; i < n / 2 + 1; i++) {
                r += x, c += y;
                if (0 <= r && r < R && 0 <= c && c < C)
                    res.push_back({r, c});
            }
            tmp = x, x = y, y = -tmp;
        }
        return res;
    }