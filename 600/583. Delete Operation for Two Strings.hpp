// 583. Delete Operation for Two Strings
// Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

// Example 1:
// Input: "sea", "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Note:
// The length of given words won't exceed 500.
// Characters in given words can only be lower-case letters.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int maxD = word1.size() + word2. size();
        if (word1.empty() || word2.empty()) return maxD;
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, maxD));
        dp[0][0] = 0;
        for (int i = 1; i <= word1.size(); ++i) dp[i][0] = i;
        for (int j = 1; j <= word2.size(); ++j) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

// find the longest common subsequence and delete the rest characters.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int maxD = word1.size() + word2. size();
        if (word1.empty() || word2.empty()) return maxD;
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
        return maxD - 2 * dp[word1.size()][word2.size()];
    }
};