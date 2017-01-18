// 115 Distinct Subsequences 
// Given a string S and a string T, count the number of distinct subsequences of T in S.
// A subsequence of a string is a new string which is formed from the original string by
// deleting some (can be none) of the characters without disturbing the relative positions
// of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not). 
// Here is an example:
// S = "rabbbit", T = "rabbit"
// Return 3.
class Solution {
public:
    int numDistinct(string S, string T) {
        if (T.empty()) return 1;
        else if (S.empty()) return 0;
        int m = S.size(), n = T.size();
        vector<vector<int>> M(n);
        for (auto & r : M) r.resize(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < m; j++)
            {
                if (i == 0)
                {
                    if (j > 0) M[i][j] = M[i][j - 1];
                    if (S[j] == T[i]) M[i][j]++;
                }
                else
                {
                    M[i][j] = M[i][j - 1];
                    if (S[j] == T[i])
                    {
                        M[i][j] += M[i - 1][j - 1];
                    }
                }
            }
        }
        return M[n - 1][m - 1];
    }
};

// https://leetcode.com/discuss/19735/a-dp-solution-with-clarification-and-explanation
class Solution2 {
public:
    int numDistinct(string S, string T) {
        int N = S.size(), M = T.size();
        int dp[M+1][N+1];
        dp[0][0] = 1;
        for (int j = 1; j <= N; ++j)
            dp[0][j] = 1; // since aligning T = "" with any substring of S would have only ONE solution which is to delete all characters in S.
        for (int i = 1; i <= M; ++i)
            dp[i][0] = 0;

        for (int i = 1; i <= M; ++i)
            for (int j = 1; j <= N; ++j)
                if (S[j-1] == T[i-1])
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];

        return dp[M][N];
    }
};

