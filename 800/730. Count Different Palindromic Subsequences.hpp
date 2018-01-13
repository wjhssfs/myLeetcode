// 730. Count Different Palindromic Subsequences
// Given a string S, find the number of different non-empty palindromic subsequences in S, and return that number modulo 10^9 + 7.

// A subsequence of a string S is obtained by deleting 0 or more characters from S.

// A sequence is palindromic if it is equal to the sequence reversed.

// Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i for which A_i != B_i.

// Example 1:
// Input: 
// S = 'bccb'
// Output: 6
// Explanation: 
// The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
// Note that 'bcb' is counted only once, even though it occurs twice.
// Example 2:
// Input: 
// S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
// Output: 104860361
// Explanation: 
// There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
// Note:

// The length of S will be in the range [1, 1000].
// Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.

// Let dp[len][i][x] be the number of distinct palindromes of the subtring starting at i of length len, where the first (and last) character is x. The DP formula is simple :

// If s[i] != x, then dp[len][i][x] = dp[len-1][i+1][x] (ignoring the first character in this window)
// If s[i+len-1] != x then dp[len][i][x] = dp[len-1][i][x] (ignoring the last character in this window)
// If both the first and last characters are x, then we need to count the number of distinct palindromes in the sub-window from i+1 to i + len -2. Need to be careful with how we count empty string.
// Since we only need to subproblems of length len-1, len-2, we only need to remember the solutions for the subproblems of length len, len-1, len-2. This is needed to pass the max test case.

// For each window, this method count palindromes of the form a...a, b...b, c...c, d...d, and the strings in different groups are distinct. The strings within each group are guaranteed to be distinct by recursing into the inside subwindows.

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int md = 1000000007;
        int n = s.size();
        int dp[3][n][4];
        for (int len = 1; len <=n; ++len) {
            for (int i = 0; i + len <=n; ++i) for (int x = 0; x < 4; ++x)  {
                int &ans = dp[(len + 2) % 3][i][x];
                ans = 0;
                int j = i + len - 1;
                char c = 'a' + x;
                if (len == 1) ans = s[i] == c;
                else {
                    if (s[i] != c) ans = dp[(len + 1) % 3][i+1][x];
                    else if (s[j] != c) ans = dp[(len + 1) % 3][i][x];
                    else {
                        ans = 2;// x and xx. note dp[0][i+1][y] doesn't count empty palindrome. So it
                        // doesn't matter even dp[0][i+1][y] includes x and xx as they become xxx and xxxx with x at s[i] and s[j].
                        if (len > 2) for (int y = 0; y < 4;++y) {
                            ans += dp[len % 3][i+1][y];
                            ans %=md;
                        }
                    }
                }
            }
        }
        int ret = 0;
        for (int x = 0; x < 4;++x) ret = (ret + dp[(n + 2) % 3][0][x]) %md;
        return ret;
    }
};