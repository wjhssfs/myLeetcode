// 212 Word Search II 
// Given a 2D board and a list of words from the dictionary, find all words in the board.
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
// For example,
// Given words = ["oath","pea","eat","rain"] and board =
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// Return ["eat","oath"].
class Solution {
    struct Trie{
        struct TrieNode{
            int ref;
            bool isKey;
            vector<TrieNode *> children;
            TrieNode() : ref(0), isKey(false){ children.resize(26); }
        };

        Trie() : root(new TrieNode()){}

        TrieNode *root;

        // this method assumes there is no duplicated words in input list
        void addWord(const string &word){
            if (word.empty()) return;
            auto node = root;
            for (auto c : word){
                ++node->ref;
                if (!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            ++node->ref; node->isKey = true;
        }

        // this method assumes there is no duplicated words in input list
        void removeWord(const string &word){
            if (word.empty()) return;
            auto node = root;
            for (auto c : word){
                --node->ref;
                node = node->children[c - 'a'];
            }
            --node->ref;
            node->isKey = false;
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> results;
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
        auto it = find(words.begin(), words.end(), "");
        if (it != words.end()) words.erase(it);
        if (!board.size() || !board[0].size() || !words.size()) return results;
        Trie trie;
        for (auto word : words) trie.addWord(word);
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++)
            {
                string word;
                findWords(board, i, j, word, trie.root, trie, results);
            }
        }
        return results;
    }

    void findWords(vector<vector<char>>& board, int i, int j, string word, Trie::TrieNode *node, Trie &trie, vector<string> & results) {
        if (!node || i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#') return;
        auto child = node->children[board[i][j] - 'a'];
        word += board[i][j];
        //cout << "searching: " << i << ", " << j << ", word=" << word << endl;
        if (child && child->ref){
            if (child->isKey) {
                results.push_back(word);
                trie.removeWord(word);
            }
            if (!child->ref) return;
            auto temp = board[i][j];
            board[i][j] = '#';
            findWords(board, i - 1, j, word, child, trie, results);
            findWords(board, i, j-1, word, child, trie, results);
            findWords(board, i+1, j, word, child, trie, results);
            findWords(board, i, j+1, word, child, trie, results);
            board[i][j] = temp;
        }
    }
};

// ==============================================

class TrieNode{
public:
    bool is_end;
    vector<TrieNode*> children;
    TrieNode(){
        is_end=false;
        children=vector<TrieNode*>(26, NULL);
    }   
};

class Trie{
public:
    TrieNode* getRoot(){return root;}
    Trie(vector<string>& words){
        root=new TrieNode();
        for(int i=0; i<words.size(); ++i)
            addWord(words[i]);
    }
    void addWord(const string& word){
        TrieNode* cur=root;
        for(int i=0; i<word.size(); ++i){
            int index=word[i]-'a';
            if(cur->children[index]==NULL)   
               cur->children[index]=new TrieNode();
            cur=cur->children[index];    
        }
        cur->is_end=true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root=trie->getRoot();
        set<string> result_set;
        for(int x=0; x<board.size(); ++x)
            for(int y=0; y<board[0].size(); ++y)
                findWords(board, x, y, root, "", result_set);

        vector<string> result;
        for(auto it:result_set)    result.push_back(it);
        return result;        
    }
private:
    void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result){
        if(x<0||x>=board.size()||y<0||y>=board[0].size() || board[x][y]==' ') return;

        if(root->children[board[x][y]-'a'] != NULL){
            word=word+board[x][y];
            root=root->children[board[x][y]-'a']; 
            if(root->is_end) result.insert(word);
            char c=board[x][y];
            board[x][y]=' ';
            findWords(board, x+1, y, root, word, result);
            findWords(board, x-1, y, root, word, result);
            findWords(board, x, y+1, root, word, result);
            findWords(board, x, y-1, root, word, result);
            board[x][y]=c;        
        }
    }
};

// https://leetcode.com/discuss/77851/java-15ms-easiest-solution-100-00%25