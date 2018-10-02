// 498. Diagonal Traverse

// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

// Example:
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output:  [1,2,4,7,5,3,6,8,9]
// Explanation:

// Note:
// The total number of elements of the given matrix will not exceed 10,000.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (!m) return res;
        int n = matrix[0].size();
        int di = -1, dj = 1;
        int i = 0, j = 0;
        while (1) {
            res.push_back(matrix[i][j]);
            if (res.size() == m * n) break;
            i += di, j += dj;
            if (i < 0 || j == n || i == m || j < 0) {
                di = -di;
                dj = -dj;
            }
            if (i < 0 && j < n) ++i;
            else if (i < 0 && j == n) {i += 2; --j;}
            else if (j < 0 && i < m) ++j;
            else if (j < 0 && i == m) {j += 2; --i;}
            else if (i == m) {--i; j += 2;}
            else if (j == n) {--j; i += 2;}
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size(), row = 0, col = 0, d = 1;
        vector<int> result(m*n);
        
        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];
            row -= d;
            col += d;
            
            if (row >= m) { row = m - 1; col += 2; d = -d;}
            if (col >= n) { col = n - 1; row += 2; d = -d;}
            if (row < 0)  { row = 0; d = -d;}
            if (col < 0)  { col = 0; d = -d;}
        }
        
        return result;
    }
};