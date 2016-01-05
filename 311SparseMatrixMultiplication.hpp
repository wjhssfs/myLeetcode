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
