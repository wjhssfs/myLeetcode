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