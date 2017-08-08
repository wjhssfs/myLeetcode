// 311 Sparse Matrix Multiplication

// Given two sparse matrices A and B, return the result of AB.

// You may assume that A's column number is equal to B's row number.

// Example:

// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]

// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]


//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |
                  

class Solution {
public:
	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int>> r;
		int m = A.size();
		if (!m) return r;
		int k = A[0].size();
		int n = B[0].size();
		r.resize(m, vector<int>(n));

		unordered_map<int, vector<int>> Ap, Bp;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < k; j++) {
				if (A[i][j])
					Ap[i].push_back(j);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				if (B[j][i])
					Bp[i].push_back(j);
			}
		}

		for (auto && elemA : Ap) {
			int row = elemA.first;
			for (auto && elemB : Bp) {
				int col = elemB.first;
				int i = 0, j = 0, sum = 0;
				while (i < elemA.second.size() && j < elemB.second.size()) {
					if (elemA.second[i] < elemB.second[j])
						++i;
					else if (elemA.second[i] > elemB.second[j])
						++j;
					else {
						sum += A[row][elemA.second[i]] * B[elemB.second[j]][col];
						++i; ++j;
					}
				}

				r[row][col] = sum;
			}
		}

		return r;
	}
};

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), l = B.size();
        if (m + l == 0) return {};
        int n = B[0].size();
        auto res = vector<vector<int>>(m, vector<int>(n));
        unordered_map<int, vector<int>> Ah, Bh;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < l; ++j) {
                if (A[i][j]) Ah[i].push_back(j);
            }
        }
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < n; ++j) {
                if (B[i][j]) Bh[i].push_back(j);
            }
        }
        for (auto && a : Ah) {
            for (auto c : a.second) {
                for (auto && d : Bh[c]) {
                    res[a.first][d] += A[a.first][c] * B[c][d];
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> res(m, vector<int>(B[0].size(),0));

        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //          for(int k = 0; k < n; k++){
        //              res[i][j] += A[i][k] * B[k][j];
        //          }
        //     }
        // }
        // imporved on upper version, this is a math solution
        for(int i = 0; i < m; i++){
            for(int k = 0; k < n; k++){
                if(A[i][k] != 0)
                    for(int j = 0; j < B[0].size(); j++){
                        res[i][j] += A[i][k] * B[k][j];
                    }
            }
        }
        return res;
    }
};