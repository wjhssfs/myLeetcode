// 97 Interleaving String 
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",

// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
	    if (s1.size() + s2.size() != s3.size())
	        return false;
	    if (s1.size() < s2.size())
	        s1.swap(s2);
	    vector<bool>  dp(s1.size() + 1);
	    dp[0] = true;
	    for (size_t j = 0; j <= s2.size(); ++j)
	        for (size_t i = 1; i <= s1.size(); ++i)
	            dp[i] = ((dp[i - 1] && s1[i - 1] == s3[i + j - 1])
	                    || (j > 0 && dp[i] && s2[j - 1] == s3[i + j - 1]));
	    return dp[s1.size()];
	}
};

class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> m(s1.size() + 1);
        for (auto &r : m) r.resize(s2.size() + 1);
        m[0][0] = true;
        for (int i = 1; i <= s1.size(); i++) m[i][0] &= s1[i - 1] == s3[i - 1];
        for (int j = 1; j <= s2.size(); j++) m[0][j] &= s2[j - 1] == s3[j - 1];
        for (int i = 1; i <= s1.size(); i++){
            for (int j = 1; j <= s2.size(); j++){
                m[i][j] = m[i - 1][j] && s1[i - 1] == s3[i + j - 1]
                    || m[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            }
        }
        return m[s1.size()][s2.size()];
    }
};

/*
 Solution: 1. dp. O(MN) time & space. 'dp[i][j] == true' means that there is at least one way to construct 
              the string s3[0...i+j-1] by interleaving s1[0...j-1] and s2[0...i-1].
           2. Recursion. Okay for Small but TLE for Large Test data.
 */
class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleave_1(s1, s2, s3);
    }

    bool isInterleave_1(string s1, string s2, string s3) {
        int M = s1.size(), N = s2.size(), K = s3.size();
        if (M + N != K) return false;
        
        bool dp[N+1][M+1];
        dp[0][0] = true;
        for (int i = 1; i <= N; ++i)
            dp[i][0] = dp[i-1][0] && s2[i-1] == s3[i-1];
        for (int j = 1; j <= M; ++j)
            dp[0][j] = dp[0][j-1] && s1[j-1] == s3[j-1];

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                dp[i][j] = dp[i-1][j] && s2[i-1] == s3[i+j-1] ||
                           dp[i][j-1] && s1[j-1] == s3[i+j-1];

        return dp[N][M];
    }
    
    bool isInterleave_2(string s1, string s2, string s3) {
        return isInterleaveRe(s1.c_str(), s2.c_str(), s3.c_str());
    }

    bool isInterleaveRe(const char *s1, const char *s2, const char *s3)
    {
        if (*s1 == '\0' && *s2 == '\0' && *s3 == '\0') return true;
        if (*s3 == '\0') return false;
        if (*s1 == '\0') return strcmp(s2, s3) == 0;
        if (*s2 == '\0') return strcmp(s1, s3) == 0;

        return *s1 == *s3 && isInterleaveRe(s1+1, s2, s3+1) || 
               *s2 == *s3 && isInterleaveRe(s1, s2+1, s3+1);
    }
};
