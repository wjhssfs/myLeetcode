// 130 Surrounded Regions
// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
// 
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
// 
// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:
// 
// X X X X
// X X X X
// X X X X
// X O X X

class Solution {
public:
	void solve(vector<vector<char>> &board) {
		int m = board.size();
		if (!m) return;
		int n = board[0].size();
		if (!n) return;
		bool changed = true;
		while (changed){
			changed = false;
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					if (board[i][j] == 'X' || board[i][j] == 'S')continue;
					if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
						board[i][j] = 'S';
						changed = true;
					}
					else if (i>0 && board[i - 1][j] == 'S'){
						board[i][j] = 'S';
						changed = true;
					}
					else if (j > 0 && board[i][j - 1] == 'S'){
						board[i][j] = 'S';
						changed = true;
					}
				}
			}
			for (int i = m - 1; i >= 0; i--){
				for (int j = n - 1; j >= 0; j--){
					if (board[i][j] == 'X' || board[i][j] == 'S')continue;
					else if (i < m - 1 && board[i + 1][j] == 'S'){
						board[i][j] = 'S'; changed = true;
					}
					else if (j < n - 1 && board[i][j + 1] == 'S'){
						board[i][j] = 'S'; changed = true;
					}
				}
			}
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (board[i][j] == 'X') continue;
				else if (board[i][j] == 'S') board[i][j] = 'O';
				else board[i][j] = 'X';
			}
		}
	}
};




class Solution {
public:
    typedef vector<vector<char> > BOARDTYPE;
    
    void solve(BOARDTYPE &board) {
        if (board.empty() || board[0].empty()) return;
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (i == 0 || j == 0 || i == N-1 || j == M-1)
                    bfs(board, i, j); // you may call dfs or bfs here!
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
    }
    
    void dfs(BOARDTYPE &board, int row, int col) {
        int N = board.size(), M = board[0].size();
        if (row < 0 || row >= N || col < 0 || col >= M) return;
        if (board[row][col] != 'O') return;
        board[row][col] = 'V';
        dfs(board, row+1, col);
        dfs(board, row-1, col);
        dfs(board, row, col+1);
        dfs(board, row, col-1);
    }

    void bfs(BOARDTYPE &board, int row, int col) {
        if (board[row][col] != 'O') return;
        int N = board.size(), M = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while (!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i < 0 || i >= N || j < 0 || j >= M) continue;
            if (board[i][j] != 'O') continue;// important to recheck!
            board[i][j] = 'V';
            q.push(make_pair(i-1, j));
            q.push(make_pair(i+1, j));
            q.push(make_pair(i, j-1));
            q.push(make_pair(i, j+1));
        }
    }
};
