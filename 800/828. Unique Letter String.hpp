// 828. Unique Letter String

// A character is unique in string S if it occurs exactly once in it.

// For example, in string S = "LETTER", the only unique characters are "L" and "R".

// Let's define UNIQ(S) as the number of unique characters in string S.

// For example, UNIQ("LETTER") =  2.

// Given a string S with only uppercases, calculate the sum of UNIQ(substring) over all non-empty substrings of S.

// If there are two or more equal substrings at different positions in S, we consider them different.

// Since the answer can be very large, retrun the answer modulo 10 ^ 9 + 7.

 

// Example 1:

// Input: "ABC"
// Output: 10
// Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
// Evey substring is composed with only unique letters.
// Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
// Example 2:

// Input: "ABA"
// Output: 8
// Explanation: The same as example 1, except uni("ABA") = 1.
 

// Note: 0 <= S.length <= 10000.

    int uniqueLetterString(string S) {
        int index[26][2], res = 0, N = S.length(), mod = pow(10, 9) + 7;
        memset(index, -1, sizeof(int) * 52);
        for (int i = 0; i < N; ++i) {
            int c = S[i] - 'A';
            res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for (int c = 0; c < 26; ++c)
            res = (res + (N - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
        return res;
    }


class Solution {
public:
    int uniqueLetterString(string S) {
        int MOD = 1000000007;
        if (S.empty()) return 0;
        int sz = S.size();
        vector<int> left(sz), right(sz);
        unordered_map<char, int> m;
        for (int i = 0; i < sz; ++i) {
            left[i] = m.count(S[i]) ? m[S[i]] : -1;
            m[S[i]] = i;
        }
        m.clear();
        for (int i = sz - 1; i >= 0; --i) {
            right[i] = m.count(S[i]) ? m[S[i]] : sz;
            m[S[i]] = i;
        }
        
        long result = 0;
        for (int i = 0; i < sz; ++i) {
            result += (i - left[i]) * (right[i] - i);
            result %= MOD;
        }
        return result;
    }
};

// https://leetcode.com/problems/unique-letter-string/discuss/129021/O(N)-Java-Solution-DP-Clear-and-easy-to-Understand
 public int uniqueLetterString(String S) {
        
        int res = 0;
        if (S == null || S.length() == 0)
            return res;    
        int[] showLastPosition = new int[128];
        int[] contribution = new int[128];
        int cur = 0;
        // cur[i], represent the sum of Uniq() for all substrings whose last char is S.charAt(i).
        for (int i = 0; i < S.length(); i++) {
            char x = S.charAt(i);
            cur -= contribution[x]; 
            contribution[x] = (i - (showLastPosition[x] - 1));
            cur += contribution[x]; 
            showLastPosition[x] = i + 1; // initial last position is -1, shift by 1
            res += cur; // DP
        }   
        return res;
    }