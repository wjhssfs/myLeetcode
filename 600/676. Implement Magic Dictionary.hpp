// 676. Implement Magic Dictionary
// Implement a magic directory with buildDict, and search methods.

// For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

// For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

// Example 1:
// Input: buildDict(["hello", "leetcode"]), Output: Null
// Input: search("hello"), Output: False
// Input: search("hhllo"), Output: True
// Input: search("hell"), Output: False
// Input: search("leetcoded"), Output: False
// Note:
// You may assume that all the inputs are consist of lowercase letters a-z.
// For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
// Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.

class MagicDictionary {
    struct TrieNode {
        bool isWord;
        vector<TrieNode*> children;
        TrieNode(): isWord(false), children(26, nullptr){}
    };
    TrieNode* root;
    void insert(const string& word) {
        auto cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->children[word[i] - 'a'] == nullptr) cur->children[word[i] - 'a'] = new TrieNode();
            cur = cur->children[word[i] - 'a'];
        }
        cur->isWord = true;
    }
    bool search(TrieNode* cur, const string &word, int start) {
        for (int i = start; i < word.size() && cur != nullptr; ++i) cur = cur->children[word[i] - 'a'];
        return cur != nullptr && cur->isWord;
    }
    
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto&& word : dict) insert(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        auto cur = root;
        for (int i = 0; i < word.size() && cur != nullptr; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (j == word[i] - 'a') continue;
                if (search(cur->children[j], word, i + 1)) return true;
            }
            cur = cur->children[word[i] - 'a'];
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */


class MagicDictionary(object):
    def _candidates(self, word):
        for i in xrange(len(word)):
            yield word[:i] + '*' + word[i+1:]
            
    def buildDict(self, words):
        self.words = set(words)
        self.near = collections.Counter(cand for word in words
                                        for cand in self._candidates(word))

    def search(self, word):
        return any(self.near[cand] > 1 or 
                   self.near[cand] == 1 and word not in self.words
                   for cand in self._candidates(word))