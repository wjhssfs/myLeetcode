// 140 Word Break II
// 
// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
// 
// Return all such possible sentences.
// 
// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
// 
// A solution is ["cats and dog", "cat sand dog"].

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int sz = s.size();
		vector<vector<bool>> matrix;
		matrix.resize(sz);
		for (auto &row : matrix) row.resize(sz);
		for (int n = 0; n < sz; n++){
			for (int i = 0; i < sz; i++){
				if (i+n < sz && dict.count(s.substr(i, n+1))>0){
					matrix[i][i + n] = true;
				}
			}
		}
		vector<string> results;

		buildResult(results, "", matrix, s, sz, sz-1);
		return results;
	}
	void buildResult(vector<string> &results, string currentResult, vector<vector<bool>>& matrix, string &s, int sz, int n){
		for (int i = 0; i <=n; i++){
			if (matrix[i][n]){
				string nextResult = n == sz-1? s.substr(i, n - i + 1): s.substr(i, n-i + 1) + " " + currentResult;
				if (i == 0) {
					results.push_back(nextResult);
				}
				else{
					buildResult(results, nextResult, matrix, s, sz, i -1);
				}
			}
		}
	}
};

class Solution2 {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (!wordBreakPossible(s, dict)) return res;
        wordBreakRe(s, dict, 0, "", res);
        return res;
    }
    
    void wordBreakRe(const string &s, const unordered_set<string> &dict, 
                     int start, string sentence, vector<string> &res) {
        if (start == s.size()) {
            res.push_back(sentence);
            return;
        }
        if (start != 0) sentence.push_back(' ');
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i-start+1);
            if (dict.find(word) == dict.end())
                continue;
            wordBreakRe(s, dict, i+1, sentence + word, res);
        }
    }
    
    bool wordBreakPossible(const string &s, const unordered_set<string> &dict) {
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
