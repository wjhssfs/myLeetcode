// 516. Longest Palindromic Subsequence

// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

// Example 1:
// Input:

// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".
// Example 2:
// Input:

// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb".

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 1; i <= n; ++i) {
            for (int start = 0; start + i - 1 < n; ++start) {
                if (i == 1) dp[start][start] = 1;
                else if (i == 2) dp[start][start + 1] = (s[start] == s[start + 1] ? 2 : 1);
                else {
                    if (s[start] == s[start + i - 1]) dp[start][start + i - 1] = dp[start + 1][start + i - 2] + 2;
                    else dp[start][start + i - 1] = max( dp[start + 1][start + i - 1],  dp[start][start + i - 2]);
                }
            }
        }
        return dp[0][n-1];
    }
};

public class Solution {
    public int longestPalindromeSubseq(String s) {
        int[][] dp = new int[s.length()][s.length()];
        
        for (int i = s.length() - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < s.length(); j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.length()-1];
    }
}