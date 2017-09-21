639. Decode Ways II

A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.

class Solution {
public:
    int numDecodings(string s) {
        int mod = 1000000007;
        if (s.empty() || s[0] == '0') return 0;
        vector<long> dp(s.size());
        dp[0] = s[0] == '*' ? (s.size() > 1 && s[1] == '0' ? 2 : 9) : 1;
        for (int i = 1; i < s.size(); ++i) {
            
            if (s[i - 1] == '0' && s[i] == '0') return 0;
            if (s[i - 1] > '2' && s[i] == '0') return 0;
            if (s[i] == '*') {
                if (i + 1 < s.size() && s[i + 1] == '0') {
                    dp[i] = 2 * dp[i - 1] % mod;
                }
                else {
                    dp[i] = (dp[i - 1] * 9) % mod;
                    long pre = i < 2 ? 1 : dp[i - 2];
                    if (s[i - 1] == '1') dp[i] = (dp[i] + pre * 9) % mod;
                    else if (s[i - 1] == '2') dp[i] = (dp[i] + pre * 6) % mod;
                    else if (s[i - 1] == '*') dp[i] = (dp[i] + pre * 15) % mod;
                }
            }
            else if (s[i] != '0') {
                dp[i] = dp[i - 1];
                if (i + 1 < s.size() && s[i + 1] == '0') continue;
                long pre = i < 2 ? 1 : dp[i - 2];
                if (s[i - 1] == '1') dp[i] = (dp[i] + pre) % mod;
                else if (s[i - 1] == '2' && s[i] <= '6') dp[i] = (dp[i] + pre) % mod;
                else if (s[i - 1] == '*') {
                    dp[i] = (dp[i] + pre) % mod;
                    if (s[i] <= '6') dp[i] = (dp[i] + pre) % mod;
                }
            }
            else dp[i] = dp[i - 1];
        }
        return dp[s.size() - 1];
    }
};

// https://discuss.leetcode.com/topic/95301/python-straightforward-with-explanation
// e0 = current number of ways we could decode, ending on any number;
// e1 = current number of ways we could decode, ending on an open 1;
// e2 = current number of ways we could decode, ending on an open 2;
// (Here, an "open 1" means a 1 that may later be used as the first digit of a 2 digit number, because it has not been used in a previous 2 digit number.)
class Solution {
public:
    int numDecodings(string s) {
        int mod = 1000000007;
        long e0 = 1, e1 = 0, e2 = 0;
        for (auto c : s) {
            long ne0 = 0, ne1 = 0, ne2 = 0;
            if (c == '*') {
                ne0 = 9 * e0 + 9 * e1 + 6 * e2;
                ne1 = e0;
                ne2 = e0;
            } else {
                ne0 = (c > '0') * e0 + e1 + (c <= '6') * e2;
                ne1 = (c == '1') * e0;
                ne2 = (c == '2') * e0;
            }
            e0 = ne0 % mod;
            e1 = ne1;
            e2 = ne2;
        }
        return e0;
    }
};

class Solution {
public:
    int dp[100010];
    int MOD = 1000000007;
    void ck(int &x, int y) {
        x += y;
        if (x >= MOD) {
            x -= MOD;
        }
    }
    int numDecodings(string s) {
        int n = s.size();
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            // check single
            for (int j = 1; j <= 9; j++) {
                if (s[i] == '*' || s[i] == j + '0') {
                    ck(dp[i + 1], dp[i]);
                }
            }
            // check double
            if (i + 1 == n) {
                continue;
            }
            for (int j = 1; j <= 2; j++) {
                for (int k = 0; k <= 9; k++) {
                    if (j * 10 + k > 26) {
                        continue;
                    }
                    if (s[i] == '*' || s[i] == j + '0') {
                        if ((s[i + 1] == '*' && k != 0) || s[i + 1] == k + '0') {
                            ck(dp[i + 2], dp[i]);
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};