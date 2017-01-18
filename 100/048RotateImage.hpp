// 48 Rotate Image
// You are given an n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).
// Could you do this in-place?

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		for (int i = 0; i < n/2; i++){
			for (int j = i; j < n - 1 - i; j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j]  = matrix[j][n-1-i];
				matrix[j][n-1-i] = temp;
			}
		}
	}
};

/*
 Solution: 1. Rotate one-fourth of the image clockwise.
           2. 123   ->  147   ->   741    (preferable)
              456       258        852
              789       369        963
 */
class Solution2 {
public:
    void rotate(vector<vector<int> > &matrix) {
        rotate_2(matrix);
    }
    
    void rotate_1(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++)
            for (int j = 0; j < n / 2; j++)
                rotateElement(matrix, i, j);
    }
    void rotateElement(vector<vector<int> > &matrix, int row, int col)
    {
        int temp = matrix[row][col];
        for (int i = 0; i < 3; i++)
        {
            int c = row;
            int r = matrix.size() - 1 - col;
            matrix[row][col] = matrix[r][c];
            row = r;
            col = c;
        }
        matrix[row][col] = temp;
    }
    
    void rotate_2(vector<vector<int> > &matrix) {
        int N = matrix.size();
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (int j = 0; j < N/2; ++j)
            for (int i = 0; i < N; ++i)
                swap(matrix[i][j], matrix[i][N-j-1]);
    }
};

/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

// https://leetcode.com/discuss/38426/seven-short-solutions-1-to-7-lines