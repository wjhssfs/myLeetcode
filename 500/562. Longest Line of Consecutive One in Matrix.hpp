// 562. Longest Line of Consecutive One in Matrix
// Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

// Example:
// Input:
// [[0,1,1,0],
//  [0,1,1,0],
//  [0,0,0,1]]
// Output: 3
// Hint: The number of elements in the given matrix will not exceed 10,000.

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int m = M.size(), n = M[0].size(), res = 0;
        vector<int> c(n), ldia(m + n), rdia(m + n);
        for (int i = 0; i < m; ++i) {
            int r = 0;
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) {
                    ++ldia[n + i - j];
                    ++rdia[i + j];
                    ++c[j];
                    ++r;
                    
                    res = max(res, r);
                    res = max(res, c[j]);
                    res = max(res, ldia[n + i - j]);
                    res = max(res, rdia[i + j]);
                } else {
                    r = 0;
                    c[j] = 0;
                    ldia[n + i - j] = 0;
                    rdia[i+j] = 0;
                }
            }
        }
        return res;
    }
};

// https://discuss.leetcode.com/topic/87197/java-o-nm-time-dp-solution
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int m = M.size(), n = M[0].size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(4));
        int leftTop = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 0) {
                    leftTop = dp[j][2];
                    dp[j] = {0, 0, 0, 0};
                    continue;
                }
                vector<int> cur(4, 1);
                if (j > 0) cur[0] += dp[j-1][0];
                if (i > 0) cur[1] += dp[j][1];
                if (j > 0 && i > 0) cur[2] += leftTop;
                if (j < n - 1 && i > 0) cur[3] += dp[j + 1][3];
                res = max(res, *max_element(cur.begin(), cur.end()));
                leftTop = dp[j][2];
                dp[j] = cur;
            }
        }
        return res;
    }
};