// 44 Wildcard Matching 
// Implement wildcard pattern matching with support for '?' and '*'.
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *sBackup = NULL, *pBackup = NULL;
        while (*s != '\0') {
            if (*p == '?' || *s == *p) {
                s++;
                p++;
            } else if (*p == '*') {
                while (*p == '*') p++;
                if (*p == '\0') return true;
                sBackup = s;
                pBackup = p;
            } else {
                if (!sBackup) return false;
                s = ++sBackup;
                p = pBackup;
            }
        }
        while (*p == '*') p++;
        return *s == '\0' && *p == '\0';
    }
};

// https://leetcode.com/discuss/10133/linear-runtime-and-constant-space-solution
 bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p=='?')||(*p==*s)){s++;p++;continue;} 

            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p=='*'){star=p++; ss=s;continue;} 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;} 

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;  
    }

// https://leetcode.com/discuss/43966/accepted-c-dp-solution-with-a-trick
class Solution {
public:
    bool isMatch(string s, string p) { 
        int m = s.length(), n = p.length();
        vector<bool> cur(m + 1, false); 
        cur[0] = true;
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // use the value before update
            cur[0] = cur[0] && p[j - 1] == '*'; 
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; // record the value before update
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m]; 
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
        dp[0][0] = true;
        for (int i = 0; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j-1] == '*')  dp[i][j] = (i && dp[i-1][j]) || dp[i][j-1];
                else if (i && (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1]) dp[i][j] = true;   
            }
        }
        return dp[s.size()][p.size()];
    }
};