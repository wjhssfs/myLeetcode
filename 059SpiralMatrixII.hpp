// 59 Spiral Matrix II
// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
// For example,
// Given n = 3,
// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret;
        if (n <= 0) return ret;
        ret.resize(n);
        for (auto & r : ret) r.resize(n);
        int s = 1, e = n*n;
        int x = 0, y = 0;
        while (n > 1){
            for (int i = 0; i < 4; i++){
                switch (i){
                case 0://top&(left to right)
                    for (int j = 0; j < n - 1; j++){
                        ret[x][y++] = s++;
                    }
                    break;
                case 1://right&(top to bottom)
                    for (int j = 0; j < n - 1; j++){
                        ret[x++][y] = s++;
                    }
                    break;
                case 2://bottom&(left to right)
                    for (int j = 0; j < n - 1; j++){
                        ret[x][y--] = s++;
                    }
                    break;
                case 3://left&(bottom to top)
                    for (int j = 0; j < n - 1; j++){
                        ret[x--][y] = s++;
                    }
                    break;
                default:
                    break;
                }
            }
            n -= 2; x++; y++;
        }
        if (n == 1)
        {
            ret[x][y] = s;
        }
        return ret;
    }
};

class Solution2 {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) return vector<vector<int> >();
        vector<vector<int> > res(n, vector<int>(n));
        int imin = 0, imax = n-1, jmin = 0, jmax = n-1;
        int number = 1;
        while (true)
        {
            for (int j = jmin; j <= jmax; ++j) res[imin][j] = number++;
            if (++imin > imax) break;
            for (int i = imin; i <= imax; ++i) res[i][jmax] = number++;
            if (jmin > --jmax) break;
            for (int j = jmax; j >= jmin; --j) res[imax][j] = number++;
            if (imin > --imax) break;
            for (int i = imax; i >= imin; --i) res[i][jmin] = number++;
            if (++jmin > jmax) break;
        }
        return res;
    }
};
