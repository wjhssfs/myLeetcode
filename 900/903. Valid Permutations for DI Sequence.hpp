// 903. Valid Permutations for DI Sequence  
// We are given S, a length n string of characters from the set {'D', 'I'}. (These letters stand for "decreasing" and "increasing".)

// A valid permutation is a permutation P[0], P[1], ..., P[n] of integers {0, 1, ..., n}, such that for all i:

// If S[i] == 'D', then P[i] > P[i+1], and;
// If S[i] == 'I', then P[i] < P[i+1].
// How many valid permutations are there?  Since the answer may be large, return your answer modulo 10^9 + 7.

 

// Example 1:

// Input: "DID"
// Output: 5
// Explanation: 
// The 5 valid permutations of (0, 1, 2, 3) are:
// (1, 0, 3, 2)
// (2, 0, 3, 1)
// (2, 1, 3, 0)
// (3, 0, 2, 1)
// (3, 1, 2, 0)
 

// Note:

// 1 <= S.length <= 200
// S consists only of characters from the set {'D', 'I'}.

// https://leetcode.com/problems/valid-permutations-for-di-sequence/discuss/168278/C++JavaPython-DP-Solution-O(N2)

class Solution {
public:
   int numPermsDISequence(string S) {
        int n = S.length(), mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int i = 0; i < n; i++)
            if (S[i] == 'I')
                for (int j = 0, cur = 0; j < n - i; j++)
                    dp[i + 1][j] = cur = (cur + dp[i][j]) % mod;
            else
                for (int j = n - i - 1, cur = 0; j >= 0; j--)
                    dp[i + 1][j] = cur = (cur + dp[i][j + 1]) % mod;
        return dp[n][0];
    }
};