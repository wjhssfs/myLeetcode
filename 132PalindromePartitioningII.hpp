// 132 Palindrome Partitioning II
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s.
// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        bool isP[N];
        int dp[N];
        dp[0] = 0;
        for (int i = 1; i < N; ++i) 
        {
            isP[i] = true;
            dp[i] = dp[i-1] + 1;
            for (int j = 0; j < i; ++j) 
            {
                isP[j] = (s[i] == s[j]) ? isP[j+1] : false; // isP[j] == true   -> [j...i] is a palindrome
                                                            // isP[j+1] == true -> [j+1...i-1] is a palindrome
                if (isP[j])
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1] + 1);  // dp[i] -> minCount for [0...i]
            }
        }
        return dp[N-1];
    }
};


// cut[i] is the minimum of cut[j - 1] + 1 (j <= i), if [j, i] is palindrome.
// If [j, i] is palindrome, [j + 1, i - 1] is palindrome, and c[j] == c[i].

public int minCut(String s) {
    char[] c = s.toCharArray();
    int n = c.length;
    int[] cut = new int[n];
    boolean[][] pal = new boolean[n][n];

    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = 0; j <= i; j++) {
            if(c[j] == c[i] && (j + 1 > i - 1 || pal[j + 1][i - 1])) {
                pal[j][i] = true;  
                min = j == 0 ? 0 : Math.min(min, cut[j - 1] + 1);
            }
        }
        cut[i] = min;
    }
    return cut[n - 1];
}

// https://leetcode.com/discuss/47140/two-versions-given-one-28ms-one-manancher-like-algorithm-10
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};