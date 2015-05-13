// 87 Scramble String
// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
// 
// Below is one possible representation of s1 = "great":
// 
//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two children.
// 
// For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
// 
//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that "rgeat" is a scrambled string of "great".
// 
// Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
// 
//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that "rgtae" is a scrambled string of "great".
// 
// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;
        for (int i = 1; i < s1.size(); i++)
        {
            if (
                (isScramble(s1.substr(0,i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                ||
                (isScramble(s1.substr(0,i), s2.substr(s2.size() - i)) && isScramble(s1.substr(i), s2.substr(0, s2.size()-i)))
            )
            return true;
        }
        return false;
    }
};


/*
 Solution: 3-dimensional dp. Contributed by yinlinglin. I really appreciate it!
              'dp[k][i][j] == true' means string s1(start from i, length k) is a scrambled string of 
              string s2(start from j, length k).
*/

class Solution2 {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int N = s1.size();
        bool dp[N+1][N][N];
        for (int k = 1; k <= N; ++k)
            for (int i = 0; i <= N-k; ++i)
                for (int j = 0; j <= N-k; ++j)
                {
                    dp[k][i][j] = false;
                    if (k == 1) 
                        dp[1][i][j] = (s1[i] == s2[j]);
                    for (int p = 1; p < k && !dp[k][i][j]; ++p)
                        if (dp[p][i][j] && dp[k-p][i+p][j+p] || dp[p][i][j+k-p] && dp[k-p][i+p][j])
                            dp[k][i][j] = true;
                }
        return dp[N][0][0];
    }
};

