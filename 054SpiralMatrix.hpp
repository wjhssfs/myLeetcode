// 54 Spiral Matrix 
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// For example,
// Given the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int imin = 0, imax = matrix.size()-1;
        int jmin = 0, jmax = matrix[0].size()-1;
        while (true)
        {
            for (int j = jmin; j <= jmax; ++j) res.push_back(matrix[imin][j]);
            if (++imin > imax) break;
            for (int i = imin; i <= imax; ++i) res.push_back(matrix[i][jmax]);
            if (jmin > --jmax) break;
            for (int j = jmax; j >= jmin; --j) res.push_back(matrix[imax][j]);
            if (imin > --imax) break;
            for (int i = imax; i >= imin; --i) res.push_back(matrix[i][jmin]);
            if (++jmin > jmax) break;
        }
        return res;
    }
};


public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<Integer>();
        if (matrix.length == 0) {
            return res;
        }
        int rowBegin = 0;
        int rowEnd = matrix.length-1;
        int colBegin = 0;
        int colEnd = matrix[0].length - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // Traverse Right
            for (int j = colBegin; j <= colEnd; j ++) {
                res.add(matrix[rowBegin][j]);
            }
            rowBegin++;

            // Traverse Down
            for (int j = rowBegin; j <= rowEnd; j ++) {
                res.add(matrix[j][colEnd]);
            }
            colEnd--;

            if (rowBegin <= rowEnd) {
                // Traverse Left
                for (int j = colEnd; j >= colBegin; j --) {
                    res.add(matrix[rowEnd][j]);
                }
            }
            rowEnd--;

            if (colBegin <= colEnd) {
                // Traver Up
                for (int j = rowEnd; j >= rowBegin; j --) {
                    res.add(matrix[j][colBegin]);
                }
            }
            colBegin ++;
        }

        return res;
    }
}