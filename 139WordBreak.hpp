// 139 Word Break
// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
// 
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
// 
// Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		int n = s.size();
		bool *table = new bool[n + 1];
		fill(table + 1, table + n + 1, false);
		table[0] = true;
		vector<string> words(dict.begin(), dict.end());
		int m = words.size();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++){
				int wordLen = words[j].length();
				if (i + 1 < wordLen) continue;
				if (!table[i + 1 - wordLen]) continue;
				if (words[j] == s.substr(i + 1 - wordLen, wordLen)) {
					table[i+1] = true;
					break;
				}
			}
		}
		bool result = table[n];
		delete [] table;
		return result;
	}
};

class Solution2 {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        bool canBreak[N+1];
        memset(canBreak, false, sizeof(canBreak));
        canBreak[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (canBreak[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[N];
    }
};
