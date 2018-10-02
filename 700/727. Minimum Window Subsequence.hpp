// 727. Minimum Window Subsequence
// Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

// If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

// Example 1:
// Input: 
// S = "abcdebdde", T = "bde"
// Output: "bcde"
// Explanation: 
// "bcde" is the answer because it occurs before "bdde" which has the same length.
// "deb" is not a smaller window because the elements of T in the window must occur in order.
// Note:

// All the strings in the input will only contain lowercase letters.
// The length of S will be in the range [1, 20000].
// The length of T will be in the range [1, 100].

class Solution {
public:
    string minWindow(string S, string T) {
        int i = 0, j = 0, left = -1, len = INT_MAX;
        while(i < S.size()) {
            if (S[i] != T[j]) {
                ++i;
                continue;
            }
            ++i; ++j;
            if (j == T.size()) {
                int ri = i - 2, rj = T.size() - 2;
                while (rj >= 0) {
                    if (S[ri] == T[rj]) --rj;
                    --ri;
                }
                ++ri;
                if (i - ri < len) {
                    len = i - ri;
                    left = ri;
                }
                j = 0;
                i = ri + 1;
            }
        }
        if (len == INT_MAX) return {};
        return S.substr(left, len);
    }
};

class Solution {
public:
   string minWindow(string S, string T) {
        int m = S.size(), n = T.size(), res = INT_MAX, tail;
        // minLen with i characters from S and j characters from T.
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX)); 
        for(int i = 0; i <= m; i++) dp[i][0] = 0;
       
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= i && j <= n; ++j){
                dp[i][j] = S[i-1] == T[j-1] ? dp[i-1][j-1] : dp[i-1][j];
                if(dp[i][j] != INT_MAX) dp[i][j]++;
            }// for j
        }// for i
        
        for(int i = m; i >= 0; --i){
            if(dp[i][n] <= res){
                res = dp[i][n];
                tail = i;
            }
        }
        return res == INT_MAX ? "" : S.substr(tail - res, res);
    }
};

// For substring S[0, i] and T[0, j], 
// dp[i][j] is starting index k of the shortest postfix of S[0, i], such that T[0, j] is a subsequence of S[k, i]. 
// Here T[0] = S[k], T[j] = S[i]. Otherwise, dp[i][j] = -1.

// The goal is the substring with length of min(i-dp[i][n-1]) for all i < m,  where m is S.size() and n is T.size() 
// Initial condition: dp[i][0] = i if S[i] = T[0], else -1
// Equations: If S[i] = T[j], dp[i][j] = max(dp[k][j-1]) for all k < i; else dp[i][j] = -1;

// O(mn) space 82 ms
class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++) 
            if (S[i] == T[0]) dp[0][i] = i;
        for (int j = 1; j < n; j++) {
            int k = -1;
            for (int i = 0; i < m; i++) {
                dp[j][i] =  S[i] == T[j] ? k : -1;
                if (dp[j-1][i] != -1) k = dp[j-1][i];
            }
        }
        int st = -1, len = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (dp[n-1][i] != -1 && i-dp[n-1][i]+1 < len) {
                st = dp[n-1][i];
                len = i-dp[n-1][i]+1;
            }    
        }
        return st == -1? "":S.substr(st, len);
    }
};

// O(m) space 53 ms
class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        vector<int> dp(m, -1);
        for (int i = 0; i < m; i++) 
            if (S[i] == T[0]) dp[i] = i;
        for (int j = 1; j < n; j++) {
            int k = -1;
            for (int i = 0; i < m; i++) {
                auto t = dp[i];
                dp[i] = S[i] == T[j] ? k : -1;
                if (t != -1) k = t;
            }
        }
        int st = -1, len = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (dp[i] != -1 && i-dp[i]+1 < len) {
                st = dp[i];
                len = i-dp[i]+1;
            }    
        }
        return st == -1? "":S.substr(st, len);
    }
};