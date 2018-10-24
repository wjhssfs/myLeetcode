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
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int jBase = -1, iBase = -1;
        while (i < s.size()) {
            if (j < p.size() && (s[i] == p[j] || p[j] == '?')) { ++i; ++j; continue;}
            if (j < p.size() && p[j] == '*') {jBase = j++; iBase = i; continue;}
            if (jBase != -1) { j = jBase + 1; i = ++iBase; continue;}
            return false;
        }
        while (j < p.size() && p[j] == '*') ++j;
        return j == p.size();
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

// http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
// if *p == '*'
// isMatch(s, p) = isMatch(s, p + 1) || isMatch(s + 1, p + 1) || ... || isMatch(s + n, p+1)
// = isMatch(s, p + 1) || isMatch(s + 1, p)
// else
// 只有一个分叉 = isMatch(s+1, p+1)

// 这个算法的关键是当左子树再遇到＊的时候，上次遇到＊分裂出来的右子树就不用搜索了。
// 例如：s = aab... p = *a*b...
// aab..., *a*b...
// aab..., a*b... ab..., *a*b...
// ab..., *b...

// 第二次遇到＊的时候 s = ab... p = *b...
// 如果s和p不匹配，那么上次遇到＊的右子树ab..., *a*b...也肯定不匹配（可以用反证法来证明）。
// 如果匹配，搜索左子树就能找到结果。 

// 假设ab...和*a*b...匹配，那么ab...和*b...肯定匹配，和条件相反。

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

// times out because it has un neccessary backtrack. if p has x*xx*x, no need to backtrack to first *.
class Solution {
    bool isMatch(const char* s, const char* p) {
        while (*s != 0 && *p != 0 && (*s == *p || *p == '?')) {
            ++s; ++p;
        }
        if (*s == 0 && *p == 0) return true;
        if (*p == 0 && *s != 0) return false;
        if (*s == 0 && *p != 0) {
            while (*p == '*') ++p;
            return *p == 0;
        }
        if (*p == '*') while (*(p + 1) == '*') ++p;
        else return false;
        return isMatch(s, p + 1) || isMatch(s + 1, p);
        
    }
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
};