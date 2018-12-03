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

// https://leetcode.com/discuss/77851/java-15ms-easiest-solution-100-00%25https://ccfbits.org/details.php?id=148003&hit=1

class Solution {
    void dfs(vector<vector<char>>& board, int i, int j, string& word, int p, unordered_set<string>& res) {
        char c = board[i][j];
        board[i][j] = 0;
        if (p == word.size() - 1) {
            res.insert(word);
        } else {
            vector<int> d = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int ni = i + d[k], nj = j + d[k + 1];
                if (ni < 0 || nj < 0 || ni == board.size() || nj == board[0].size() || board[ni][nj] != word[p + 1]) continue;
                dfs(board, ni, nj, word, p + 1, res);
            }
        }
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        for (auto&& word : words) {
            if (word.empty()) continue;
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[0].size(); ++j) {
                    if (board[i][j] == word[0]) dfs(board, i, j, word, 0, res);
                }
            }
        }
        
        return vector<string>(res.begin(), res.end());
    }
};
