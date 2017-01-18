// 131 Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.
// For example, given s = "aab",
// Return
//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> results;
		vector<string> result;
		vector<vector<bool>> m(s.size(), vector<bool>(s.size()));
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

public class Solution {
    public static List<List<String>> partition(String s) {
        int len = s.length();
        List<List<String>>[] result = new List[len + 1];
        result[0] = new ArrayList<List<String>>();
        result[0].add(new ArrayList<String>());

        boolean[][] pair = new boolean[len][len];
        for (int i = 0; i < s.length(); i++) {
            result[i + 1] = new ArrayList<List<String>>();
            for (int left = 0; left <= i; left++) {
                if (s.charAt(left) == s.charAt(i) && (i-left <= 1 || pair[left + 1][i - 1])) {
                    pair[left][i] = true;
                    String str = s.substring(left, i + 1);
                    for (List<String> r : result[left]) {
                        List<String> ri = new ArrayList<String>(r);
                        ri.add(str);
                        result[i + 1].add(ri);
                    }
                }
            }
        }
        return result[len];
    }
}