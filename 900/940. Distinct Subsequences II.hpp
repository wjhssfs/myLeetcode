// 940. Distinct Subsequences II
// Given a string S, count the number of distinct, non-empty subsequences of S .

// Since the result may be large, return the answer modulo 10^9 + 7.

 

// Example 1:

// Input: "abc"
// Output: 7
// Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
// Example 2:

// Input: "aba"
// Output: 6
// Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".
// Example 3:

// Input: "aaa"
// Output: 3
// Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
 

// Note:

// S contains only lowercase letters.
// 1 <= S.length <= 2000


class Solution {
public:
    int distinctSubseqII(string S) {
        vector<int> nchar(128);
        long long curS = 0, mod = 1e9 + 7;
        for (auto c : S) {
            long long newN = (curS - nchar[c] + 1 + mod) % mod;
            curS = (curS + newN) % mod;
            nchar[c] = (nchar[c] + newN) % mod;
        }
        return curS;
    }
};