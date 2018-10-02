// 36 Valid Sudoku
// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
// http://sudoku.com.au/TheRules.aspx
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
// A partially filled sudoku which is valid.
// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        set<char>row, cloumn, square;
        for (int i = 0; i < 9; i++){
            row.clear(), cloumn.clear(), square.clear();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.'){
                    if (row.find(board[i][j]) != row.end()) 
                        return false;
                    else row.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (cloumn.find(board[j][i]) != cloumn.end())
                        return false;
                    else cloumn.insert(board[j][i]);
                }
                int ni = i % 3 * 3 + j / 3, nj = i / 3 * 3 + j % 3;
                if (board[ni][nj] != '.') {
                    if (square.find(board[ni][nj]) != square.end())
                        return false;
                    else square.insert(board[ni][nj]);
                }
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        bool rowUsed[9][9] = {0}, colUsed[9][9] = {0}, squareUsed[9][9] = {0};

        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(rowUsed[i][num] || colUsed[j][num] || squareUsed[k][num])
                        return false;
                    rowUsed[i][num] = colUsed[j][num] = squareUsed[k][num] = true;
                }

        return true;
    }
};