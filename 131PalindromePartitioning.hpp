// 131 Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome.
// 
// Return all possible palindrome partitioning of s.
// 
// For example, given s = "aab",
// Return
// 
//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> results;
		vector<string> result;
		vector<vector<bool>> m(s.size());
		for (auto &e : m) e.resize(s.size());

		buildM(m, s);
		buildResults(results, result, s, m, 0);
		return results;
	}

	void buildResults(vector<vector<string>> &results, vector<string> &result, string &s,
		vector<vector<bool>> &m, int start){
		if (start == s.size()){
			results.push_back(result);
		}
		for (int i = start; i < s.size(); i++){
			if (m[start][i]){
				result.push_back(s.substr(start, i - start + 1));
				buildResults(results, result, s, m, i + 1);
				result.pop_back();
			}
		}
	}
	void buildM(vector<vector<bool>> &m, string &s){
		int sz = s.size();
		for (int n = 1; n <= sz; n++){
			for (int i = 0; i < sz; i++){
				if (n == 1){
					m[i][i] = true;
				}
				else if (n == 2 && i < sz - 1){
					m[i][i + 1] = s[i] == s[i + 1];
				}
				else if (i + n - 1 < sz){
					m[i][i + n - 1] = m[i + 1][i + n - 2] && s[i] == s[i + n - 1];
				}
			}
		}
	}
};

class Solution2 {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        res.clear();
        vector<string> part;
        partitionRe(s, 0, part);
        return res;
    }

    void partitionRe(const string &s, int start, vector<string> &part) {
        if (start == s.size())
        {
            res.push_back(part);
            return;
        }
        string palindrom;
        for (int i = start; i < s.size(); ++i) {
            palindrom.push_back(s[i]);
            if (!isPalindrome(palindrom)) continue;
            part.push_back(palindrom);
            partitionRe(s, i + 1, part);
            part.pop_back();
        }
    }

    bool isPalindrome(const string &s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};