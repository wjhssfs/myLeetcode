// 51 N-Queens 
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
// 
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// 
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
// 
// For example,
// There exist two distinct solutions to the 4-queens puzzle:
// 
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
// 
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<string> board(n);
		vector<vector<string>> sols;
		if (!n) return sols;
		for (auto &row : board) row.resize(n,'.');
		placeQueen(n, 0, board, sols);
		return sols;
	}
private:
	void placeQueen(int n, int r, vector<string> &board, vector<vector<string>> &sols)
	{
		if (r == n){
			sols.push_back(board);
			return;
		}
		for (int c = 0; c < n; c++){
			if (valid(board,r,c)){
				board[r][c] = 'Q';
				placeQueen(n, r + 1, board,sols);
				board[r][c] = '.';
			}
		}
	}
	bool valid(vector<string> &board, int r, int c){
		for (int i = 0; i < r; i++){
			for (int j = 0; j < (int)board.size(); j++){
				if (board[i][j]=='Q'){
					if (j == c) return false;
					if (abs(r - i) == abs(c - j)) return false;
					break;
				}
			}
		}
		return true;
	}
};

class Solution2 {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> sol;
        solveNQueensRe(n, 0, 0, 0, sol, res);
        return res;
    }
    
    void solveNQueensRe(int n, int row, int ld, int rd, vector<string> &sol, vector<vector<string>> &res)
    {
        if (row == (1 << n) - 1)
        {
            res.push_back(sol);
            return;
        }
        int avail = ~(row | ld | rd);
        for (int i = n-1; i >= 0; --i)
        {
            int pos = 1 << i;
            if (avail & pos)
            {
                string s(n, '.');
                s[i] = 'Q';
                sol.push_back(s);
                solveNQueensRe(n, row | pos, (ld|pos) << 1, (rd|pos) >> 1, sol, res);
                sol.pop_back();
            }
        }
    }
};


