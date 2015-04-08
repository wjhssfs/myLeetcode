// 72 Edit Distance
// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
// 
// You have the following 3 operations permitted on a word:
// 
// a) Insert a character
// b) Delete a character
// c) Replace a character

class Solution {
public:
	int minDistance(string word1, string word2) {
		size_t s1 = word1.size(), s2 = word2.size();
		if (!s1 || !s2) return s1 ? s1 : s2;
		vector<vector<int>> m(s1);
		for (auto & row : m) row.resize(s2);
		m[0][0] = word1[0] == word2[0] ? 0 : 1;
		for (size_t i = 1; i != s1; i++)
		{
			m[i][0] = (word1[i] == word2[0] || m[i - 1][0] == i-1) ? i : i + 1;
		}
 		for (size_t i = 1; i != s2; i++){
			m[0][i] = (word1[0] == word2[i] || m[0][i-1] == i - 1) ? i : i + 1;
		}
		for (size_t i = 1; i != s1; i++){
			for (size_t j = 1; j != s2; j++){
				if (word1[i] == word2[j]) m[i][j] = m[i - 1][j - 1];//match
				else m[i][j] = min({
					1 + m[i - 1][j - 1],/*change*/
					1 + m[i - 1][j],/*delete*/
					1 + m[i][j - 1]/*add*/
				});
			}
		}
		return m[s1 - 1][s2 - 1];
	}
};


class Solution2 {
public:
    int minDistance(string word1, string word2) {
        return minDistance_2(word1, word2);
    }
    
    int minDistance_1(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        int dp[N+1][M+1];
        for (int j = 0; j <= M; j++)
            dp[0][j] = j;
        for (int i = 0; i <= N; i++)
            dp[i][0] = i;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (word2[i-1] == word1[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
        
        return dp[N][M];
    }
    
    int minDistance_2(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        int dp[N+1];
        for (int j = 0; j <= N; ++j)
            dp[j] = j;
        for (int i = 1; i <= M; ++i)
        {
            int upperLeftBackup = dp[0];
            dp[0] = i;
            for (int j = 1; j <= N; ++j)
            {
                int upperLeft = upperLeftBackup;
                upperLeftBackup = dp[j];
                if (word1[i-1] == word2[j-1])
                    dp[j] = upperLeft;
                else
                    dp[j] = min(min(dp[j-1], dp[j]), upperLeft) + 1;
            }
        }
        return dp[N];
    }
};