// 472. Concatenated Words

// Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

// Example:
// Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
//  "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
// Note:
// The number of elements of the given array will not exceed 10,000
// The length sum of elements in the given array will not exceed 600,000.
// All the input string will only include lower case letters.
// The returned elements order does not matter.

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> result;
		if (words.empty()) return result;
		auto mycomp = [&](const string& str1, const string& str2) {return str1.size() < str2.size(); };
		sort(words.begin(), words.end(), mycomp);
		unordered_set<string> mp;
		for (auto& word : words) {
			if (wordBreak(word, mp)) result.push_back(word); // We don't need to insert this word, because it can be concatenated from other words.
			else mp.insert(word);
		}
		return result;
	}

private:
	bool wordBreak(string& s, unordered_set<string>& wordDict) {
		if (s.empty() || wordDict.empty()) return false;
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++) {
			for (int k = i - 1; k >= 0; k--) {
				if (dp[k] && wordDict.find(s.substr(k, i - k)) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.size()];
	}
};

	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        for (auto w : words) {
            int n = w.size();
            vector<int> dp(n+1);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (dp[i] == 0) continue;
                for (int j = i+1; j <= n; j++) {
                    if (j - i < n && s.count(w.substr(i, j-i))) dp[j] = 1;
                }
                if (dp[n]) { res.push_back(w); break; }
            }
        }
        return res;
    }

class Solution {
public:
	struct TrieNode {
		bool isWord;
		map<char, TrieNode*> children;
		TrieNode() : isWord(false) {};
	};

	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> result;
		if (words.empty()) return result;
		auto mycomp = [&](const string& str1, const string& str2) {return str1.size() < str2.size(); };
		sort(words.begin(), words.end(), mycomp);

		root = new TrieNode();
		for (auto& word : words) {
			if (dfs(word, 0, root, 0)) result.push_back(word);
			else insert(word);
		}
		return result;
	}

private:
	TrieNode* root;

	void insert(string& word) {
		auto run = root;
		for (char c : word) {
			if (run->children.find(c) == run->children.end()) {
				TrieNode* newnode = new TrieNode();
				run->children[c] = newnode;
			}
			run = run->children[c];
		}
		run->isWord = true;
	}

	bool dfs(string& word, int pos, TrieNode* node, int nb) {
		if (pos == word.size()) {
			if (node->isWord && nb > 0) return true;
			else return false;
		}

		if (node->children.find(word[pos]) == node->children.end()) return false;
		auto next = node->children[word[pos]];
		if (next->isWord) {
			if (dfs(word, pos + 1, root, nb + 1)) return true;
		}
		if (dfs(word, pos + 1, next, nb)) return true;
		else return false;
	}
};