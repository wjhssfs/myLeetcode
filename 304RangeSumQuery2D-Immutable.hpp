// 304 Range Sum Query 2D - Immutable
// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

// Range Sum Query 2D
// The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
// Note:
// You may assume that the matrix does not change.
// There are many calls to sumRegion function.
// You may assume that row1 ≤ row2 and col1 ≤ col2.

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) {
		nRow = matrix.size(); nCol = 0; total = 0;
		if (!nRow) return;
		nCol = matrix[0].size();
		auxLT = auxRB = auxLB = auxRT = matrix;
		for (int i = 0; i < nRow; i++) {
			int sumLT = 0, sumLB = 0, sumRT = 0, sumRB = 0;
			for (int j = 0; j < nCol; j++) {
				sumLT += matrix[i][j];
				sumLB += matrix[nRow-1-i][j];
				sumRB += matrix[nRow - 1 - i][nCol - 1 - j];
				sumRT += matrix[i][nCol - 1 - j];

				auxLT[i][j] = (i == 0 ? 0 : auxLT[i - 1][j]) + sumLT;
				auxLB[nRow -1 -i][j] = (i == 0 ? 0 : auxLB[nRow - i][j]) + sumLB;
				auxRB[nRow - 1 - i][nCol - 1 - j] = (i == 0 ? 0 : auxRB[nRow - i][nCol - 1 - j]) + sumRB;
				auxRT[i][nCol - 1 - j] = (i == 0 ? 0 : auxRT[i-1][nCol - 1 - j]) + sumRT;
			}
			total += sumLT;
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (row1 < 0 || row1 > nRow - 1 || row2 < 0 || row2 > nRow - 1 ||
			col1 < 0 || col1 > nCol - 1 || col2 < 0 || col2 > nCol - 1) return 0;
		int result = auxLT[row2][col2] + auxRB[row1][col1];
		if (row2 < nRow - 1 && col1 >0) result += auxLB[row2 + 1][col1 - 1];
		if (row1 > 0 && col2 < nCol -1) result += auxRT[row1 - 1][col2 + 1];
		result -= total;
		return result;
	}
private:
	int total, nRow, nCol;
	vector<vector<int>> auxLT, auxRB, auxLB, auxRT;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);