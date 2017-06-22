// 336. Palindrome Pairs
// Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list,
// so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
// Example 1:
// Given words = ["bat", "tab", "cat"]
// Return [[0, 1], [1, 0]]
// The palindromes are ["battab", "tabbat"]
// Example 2:
// Given words = ["abcd", "dcba", "lls", "s", "sssll"]
// Return [[0, 1], [1, 0], [3, 2], [2, 4]]
// The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> m;
		vector<vector<int>> res;
		for (size_t i = 0; i < words.size(); ++i) {
			m[words[i]] = i;
		}

		for (int i = 0; i < words.size(); ++i) {
			string &word = words[i];
			for (int j = 0; j <= word.size(); ++j)
			{
				string left = word.substr(0, j), right = word.substr(j);
				if (isPalindrome(left)) {
					string rightRev(right.rbegin(), right.rend());
					if (m.count(rightRev) && m[rightRev] != i) {
						res.push_back({ m[rightRev], i });
					}
				}
				if (isPalindrome(right)) {
					string leftRev(left.rbegin(), left.rend());
					if (m.count(leftRev) && m[leftRev] != i && !right.empty()) { // !right.empty() avoids whole word reversed case being processed twice.
						res.push_back({ i, m[leftRev] });
					}
				}
			}
		}
		return res;
	}
private:
	bool isPalindrome(const string &str)
	{
		int i = 0, j = str.size() - 1;
		while (i < j) {
			if (str[i++] != str[j--]) 
				return false;
		}
		return true;
	}
};