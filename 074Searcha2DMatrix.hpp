// 74 Search a 2D Matrix 
// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// 
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,
// 
// Consider the following matrix:
// 
// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int rowSz = matrix.size();
		if (!rowSz) return false;
		int colSz = matrix[0].size();
		if (!colSz) return false;
		int rLow = 0, rHigh = rowSz - 1;
		while (rLow <= rHigh){
			int rMiddle = (rLow + rHigh) / 2;
			if (matrix[rMiddle][0] > target){
				rHigh = rMiddle-1;
			}
			else if (matrix[rMiddle][0] < target){
				if (rMiddle + 1 == rowSz || matrix[rMiddle + 1][0] > target) {
					rLow = rMiddle;
					break;
				}
				rLow = rMiddle + 1;
			}
			else return true;
		}
		int cLow = 0, cHigh = colSz - 1;
		while (cLow <= cHigh){
			int cMiddle = (cLow + cHigh) / 2;
			if (matrix[rLow][cMiddle] > target){
				cHigh = cMiddle - 1;
			}
			else if (matrix[rLow][cMiddle] < target){
				cLow = cMiddle + 1;
			}
			else return true;
		}
		return false;
	}
};


class Solution2 {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        return searchMatrix_2(matrix, target);
    }
    
    // Solution 1.
    bool searchMatrix_1(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int N = matrix.size(), M = matrix[0].size();
        int i = 0, j = N-1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) i++;
            else j--;
        }
        int row = j;
        if (row < 0) return false;
        i = 0, j = M - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) i++;
            else j--;
        }
        return false;
    }
    
    // Solution 2.
    bool searchMatrix_2(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int N = matrix.size(), M = matrix[0].size();
        int i = 0, j = M * N - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            int row = mid / M, col = mid % M;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) i = mid + 1;
            else j = mid - 1;
        }
        return false;
    }
};