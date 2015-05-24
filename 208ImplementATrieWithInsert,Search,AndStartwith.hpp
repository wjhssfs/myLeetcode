// 208 Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

class TrieNode {
public:
	TrieNode() {}
	char c; // Char needed from parent node to current node
	vector<TrieNode *> children;
};

class Trie {
public:
	Trie() { root = new TrieNode(); }

	// Inserts a word into the trie.
	void insert(string s) {
		s.push_back('$'); // Special character to indicate end of a string in the trie.
		TrieNode *cur = root;
		for (auto && c : s)
		{
			auto it = find_if(cur->children.begin(), cur->children.end(), [c](TrieNode * child){ return child->c == c; });
			if (it == cur->children.end())
			{
				TrieNode * newTrieNode = new TrieNode();
				newTrieNode->c = c;
				cur->children.push_back(newTrieNode);
				cur = newTrieNode;
			}
			else cur = *it;
		}
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		key.push_back('$'); // Special character to indicate end of a string in the trie.
		return startsWith(key);
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *cur = root;
		for (char c : prefix)
		{
			bool found = false;
			auto it = find_if(cur->children.begin(), cur->children.end(), [c](TrieNode * child){return child->c == c; });
			if(it == cur->children.end()) return false;
			else cur = *it;
		}
		return true;
	}

private:
	TrieNode* root;
};
