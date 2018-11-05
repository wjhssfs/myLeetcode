// 688. Knight Probability in Chessboard
// On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

// A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.


// Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

// The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

// Example:
// Input: 3, 2, 0, 0
// Output: 0.0625
// Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
// From each of those positions, there are also two moves that will keep the knight on the board.
// The total probability the knight stays on the board is 0.0625.
// Note:
// N will be between 1 and 25.
// K will be between 0 and 100.
// The knight always initially starts on the board.

class Solution {
    double knightProbability(int N, int K, int r, int c, double cp) {
        if (r < 0 || c < 0 || r >= N || c >= N) return 0;
        if (K == 0) return cp;
        if (m[r][c][K] != 0.0) return m[r][c][K];
        double ncp = cp / 8.0;
        double res = 0;
        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
                if (abs(i) + abs(j) != 3) continue;
                res += knightProbability(N, K - 1, r + i, c + j, ncp);
            }
        }
        m[r][c][K] = res;
        return res;
    }
    double m[26][26][101];
public:
    double knightProbability(int N, int K, int r, int c) {
        memset(m, 0, sizeof(m));
        return knightProbability(N, K, r, c, 1.0);
    }
};

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(K+1, vector<vector<double>>(N, vector<double>(N, -1.0)));
        return helper(dp, N, K, r, c)/pow(8, K);
    }
private:
    double helper(vector<vector<vector<double>>>& dp, int N, int k, int r, int c) {
        // if out of board, return 0.0
        if (r < 0 || r >= N || c < 0 || c >= N) return 0.0;
        // when k = 0, no more move, so it's 100% safe
        if (k == 0) return 1.0;
        if (dp[k][r][c] != -1.0) return dp[k][r][c];
        dp[k][r][c] = 0.0;
        for (int i = -2; i <= 2; i++) {
            if (i == 0) continue;
            dp[k][r][c] += helper(dp, N, k-1, r+i, c+3-abs(i)) + helper(dp, N, k-1, r+i, c-(3-abs(i)));
        }      
        return dp[k][r][c];
    }
};


int[][] moves = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
public double knightProbability(int N, int K, int r, int c) {
    int len = N;
    double dp0[][] = new double[len][len];
    // dp[i][j] valid ways with k steps starting from i, j. 
    for(double[] row : dp0) Arrays.fill(row, 1); // 0 step, 1 way
    for(int l = 0; l < K; l++) {
        double[][] dp1 = new double[len][len];
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                for(int[] move : moves) {
                    int row = i + move[0];
                    int col = j + move[1];
                    if(isLegal(row, col, len)) dp1[i][j] += dp0[row][col];
                }
            }
        }
        dp0 = dp1;
    }
    return dp0[r][c] / Math.pow(8, K); 
}
private boolean isLegal(int r, int c, int len) {
    return r >= 0 && r < len && c >= 0 && c < len;
}

const int N = 30;
const int K = 101;
double dp[N][N][K];
const int d[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};

class Solution {
public:
    int n;
    double solve(int x, int y, int k) {
        if (x < 0 || x >= n || y < 0 || y >= n) return 0;
        double& ret = dp[x][y][k];
        if (ret >= 0) return ret;
        if (k == 0) return ret = 1;
        ret = 0;
        for (int i = 0; i < 8; ++i) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            ret += 1.0 / 8 * solve(nx, ny, k - 1);
        }
        return ret;
    }
    double knightProbability(int n, int k, int r, int c) {
        this->n = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int u = 0; u <= k; ++u) {
                    dp[i][j][u] = -1;
                }
            }
        }
        return solve(r, c, k);
    }
};