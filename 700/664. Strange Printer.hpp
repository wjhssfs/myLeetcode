// 664. Strange Printer

// There is a strange printer with the following two special requirements:

// The printer can only print a sequence of the same character each time.
// At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.
// Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.

// Example 1:
// Input: "aaabbb"
// Output: 2
// Explanation: Print "aaa" first and then print "bbb".
// Example 2:
// Input: "aba"
// Output: 2
// Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
// Hint: Length of the given string will not exceed 100.

class Solution {
public:
    int strangePrinter(string s) {
        auto n = s.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; i + j < n; ++j) {
                dp[j][j + i] = i + 1;
                for (int k = j; k < i + j; ++k) {
                    int c = dp[j][k] + dp[k+1][i + j];
                    if (s[j] == s[i + j]) --c;
                    dp[j][j + i] = min(dp[j][j + i], c);
                }
            }
        }
        return dp[0][n - 1];
    }
};