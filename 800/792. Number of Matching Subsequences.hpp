// 792. Number of Matching Subsequences

// Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

// Example :
// Input: 
// S = "abcde"
// words = ["a", "bb", "acd", "ace"]
// Output: 3
// Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
// Note:

// All words in words and S will only consists of lowercase letters.
// The length of S will be in the range of [1, 50000].
// The length of words will be in the range of [1, 5000].
// The length of words[i] will be in the range of [1, 50].

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        vector<vector<pair<int, int>>> m(128);
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].size()) m[words[i][0]].emplace_back(i, 1);
        }
        for (auto c : S) {
            vector<pair<int, int>> temp;
            swap(temp, m[c]);
            for (auto&& t : temp) {
                if (words[t.first].size() == t.second) ++res;
                else {
                    m[words[t.first][t.second]].emplace_back(t.first, t.second + 1);
                }
            }
        }
        return res;
    }
};

class Solution {
    struct TrieNode {
        TrieNode() : count(0), counted(false), next(26) {}
        int count;
        bool counted;
        vector<TrieNode*> next;
    };
    
    void insert(TrieNode* root, string& word) {
        int i = 0;
        while(i != word.size()) {
            int index = word[i] - 'a';
            if (root->next[index] == nullptr) {
                root->next[index] = new TrieNode();
            }
            root = root->next[index];
            ++i;
        }
        root->count++;
    }
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        TrieNode root;
        root.counted = true;
        for (auto&& word : words) insert(&root, word);
        vector<TrieNode*> activeNodes {&root};
        for (auto c : S) {
            int sz = activeNodes.size();
            for (int i = 0; i < sz; ++i) {
                auto node = activeNodes[i]->next[c-'a'];
                if (node != nullptr && !node->counted) {
                    res += node->count;
                    node->counted = true;
                    activeNodes.push_back(node);
                }
            }
        }
        return res;
    }
};