// 54 Spiral Matrix 
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// 
// For example,
// Given the following matrix:
// 
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

 class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> ret;
		int m = matrix.size();
		if (!m) return ret;
		int n = matrix[0].size();
		int x = 0, y = 0;
		while (m>1&& n>1){
			for (int i = 0; i < 4; i++){
				switch (i){
				case 0://top&(left to right)
					for (int j = 0; j < n - 1; j++){
						ret.push_back(matrix[x][y++]);
					}
					break;
				case 1://right&(top to bottom)
					for (int j = 0; j < m - 1; j++){
						ret.push_back(matrix[x++][y]);
					}
					break;
				case 2://bottom&(left to right)
					for (int j = 0; j < n - 1; j++){
						ret.push_back(matrix[x][y--]);
					}
					break;
				case 3://left&(bottom to top)
					for (int j = 0; j < m - 1; j++){
						ret.push_back(matrix[x--][y]);
					}
					break;
				default:
					break;
				}
			}
            m -= 2; n -= 2; x++; y++;
		}
		if (m == 1)
        {//include m==1 && n==1
			for (int i = 0; i < n; i++){
				ret.push_back(matrix[x][y++]);
			}
		} 
        else if (n == 1)
        {
			for (int i = 0; i < m; i++){
				ret.push_back(matrix[x++][y]);
			}
		}
		return ret;
	}
};

class Solution2 {
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
