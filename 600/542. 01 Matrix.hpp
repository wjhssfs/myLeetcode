// 542. 01 Matrix

// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.
// Example 1: 
// Input:

// 0 0 0
// 0 1 0
// 0 0 0
// Output:
// 0 0 0
// 0 1 0
// 0 0 0
// Example 2: 
// Input:

// 0 0 0
// 0 1 0
// 1 1 1
// Output:
// 0 0 0
// 0 1 0
// 1 2 1
// Note:
// The number of elements of the given matrix will not exceed 10,000.
// There are at least one 0 in the given matrix.
// The cells are adjacent in only four directions: up, down, left and right.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> qc, qn;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;
                    qn.emplace(i, j);
                }
            }
        }
        vector<int> d{-1, 0, 1, 0, -1};
        int dis = 0;
        while (!qn.empty()) {
            ++dis;
            swap(qn, qc);
            while(!qc.empty()) {
                auto cur = qc.front(); qc.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = cur.first + d[i], y = cur.second + d[i+1];
                    if (x < 0 || x == m || y < 0 || y == n || res[x][y] != -1) continue;
                    res[x][y] = dis;
                    qn.emplace(x, y);
                }
            }
        }
        return res;
    }
};