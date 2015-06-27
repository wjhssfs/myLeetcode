// 211 Add and Search Word - Data structure design
// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

// For example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
// Note:
// You may assume that all words are consist of lowercase letters a-z.

class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode() :isKey(false){ memset(children, 0, sizeof(children)); };
};

class WordDictionary {
public:
    WordDictionary() :root(new TrieNode()){}

    // Adds a word into the data structure.
    void addWord(const string &word) {
        TrieNode* node = root;
        for (auto c: word) {
            if (!(node->children[c - 'a']))
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    // to char * to speed up
    bool search(const string &word) {
        return searchHelper(word.c_str(), root);
    }
private:
    TrieNode* root;

    // Helper function for search()
    bool searchHelper(const char* word, TrieNode* node) {
        if (!node) return false;
        if (!*word) return node->isKey;
        if (*word == '.'){
            for (auto c : node->children){
                if (searchHelper(word + 1, c)) return true;
            }
            return false;
        }
        else
            return searchHelper(word + 1, node->children[*word - 'a']);
    }
};


// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");