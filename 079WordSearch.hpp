// 79 Word Search
// Given a 2D board and a word, find if the word exists in the grid.
// 
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
// 
// For example,
// Given board =
// 
// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

 class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (!board.size() || !board[0].size()) return false;
        m = board.size(), n = board[0].size();
		used.resize(m);
        for (auto&r : used) r.resize(n);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (board[i][j] == word[0]){
                    used[i][j] = true;
                    s.push({ i, j,0 });
                    while (s.size() && s.size() < word.size())
                    {
                        if (!findNext(board, word,0)){
                            while (s.size()){//retro
                                used[s.top().x][s.top().y] = false;
                                int start = s.top().d;
                                s.pop();
                                if (s.size()&&findNext(board, word, start)) break;
                            }
                        }
                    }
					if (s.size() == word.size()) return true;
				}
			}
		}
        return false;
	}

private:
    bool findNext(vector<vector<char> > &board, string & word, int start){
        int x = s.top().x, y = s.top().y;
        char cNext = word[s.size()];
        if (start < 1 &&x < m - 1 && board[x + 1][y] == cNext && !used[x + 1][y]) {
            s.push({ x + 1, y,1 }); 
            used[x + 1][y] = true;
            return true;
        }
        else if ( start < 2 && x > 0 && board[x - 1][y] == cNext && !used[x - 1][y]) {
            s.push({ x - 1, y,2 });
            used[x - 1][y] = true;
            return true;
        }
        else if (start < 3 && y < n - 1 && board[x][y + 1] == cNext && !used[x][y + 1]) {
            s.push({ x, y + 1,3 });
            used[x][y + 1] = true;
            return true;
        }
        else if (start < 4 && y>0 && board[x][y - 1] == cNext && !used[x][y - 1]) {
            s.push({ x, y - 1,4 });
            used[x][y - 1] = true;
            return true;
        }
        return false;
    }
    vector<vector<bool>> used;
    struct record{
        int x; int y; int d;
    };
    stack<record> s;
    int m, n;
};

class Solution2 {
public:
    typedef vector<vector<char> > VECTOR2D;
    
    bool exist(VECTOR2D &board, string word) {
        int N = board.size(), M = board[0].size();
        VECTOR2D avail(N, vector<char>(M, 'o'));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (existRe(board, word, 0, i, j, avail))
                    return true;
        return false;
    }

    bool existRe(const VECTOR2D &board, const string &word, int deep, int i, int j, VECTOR2D &avail)
    {
        int N = board.size(), M = board[0].size();
        if (deep == word.size()) return true;
        if (i < 0 || i >= N || j < 0 || j >= M) return false;
        if (board[i][j] != word[deep] || avail[i][j] == 'x') return false;
        
        avail[i][j] = 'x';
        if (existRe(board, word, deep + 1, i-1, j, avail)) return true;
        if (existRe(board, word, deep + 1, i+1, j, avail)) return true;
        if (existRe(board, word, deep + 1, i, j-1, avail)) return true;
        if (existRe(board, word, deep + 1, i, j+1, avail)) return true;
        avail[i][j] = 'o';
        
        return false;
    }
};