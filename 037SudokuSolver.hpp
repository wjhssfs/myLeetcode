// 37 Sudoku Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.'.
// You may assume that there will be only one unique solution.

class Solution {
public:
    typedef vector<vector<char> > BOARDTYPE;
    
    void solveSudoku(BOARDTYPE &board) {
        solveSudokuRe(board, 0, 0);
    }
    
    bool solveSudokuRe(BOARDTYPE &board, int row, int col) {
        getNextEmpty(board, row, col);
        if (row == 9) return true;
        vector<bool> avail(9, true);
        getAvailable(board, avail, row, col);
        for (int i = 0; i < 9; ++i)
        {
            if (!avail[i]) continue;
            board[row][col] = i + '1';
            if (solveSudokuRe(board, row, col)) return true;
        }
        board[row][col] = '.';
        return false;
    }
    
    void getNextEmpty(BOARDTYPE &board, int &row, int &col) {
        do {
            if (board[row][col] == '.') return;
            row = (col == 8) ? row + 1 : row;
            col = (col + 1) % 9;
        } while (row < 9);
    }
    
    void getAvailable(BOARDTYPE &board, vector<bool> &avail, int row, int col) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] != '.') avail[board[row][i]-'1'] = false;
            if (board[i][col] != '.') avail[board[i][col]-'1'] = false;
            int box_i = row/3*3 + i/3, box_j = col/3*3 + i%3;
            if (board[box_i][box_j] != '.') avail[board[box_i][box_j]-'1'] = false;
        }
    }
};

class Solution2 {
public:
    void solveSudoku(vector<vector<char> > &board) {
        int solved = 0;
        array<array<set<char>, 9>, 9> searchSpace;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.') solved++;
                else for (int k = 0; k < 9; k++) searchSpace[i][j].insert('1' + k);
            }
        }

        bool advanced = true;
        while (advanced)
        {
            advanced = false;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    char cr = board[i][j];
                    if (cr == '.') continue;
                    else{
                        int mi = i / 3 * 3;
                        int mj = j / 3 * 3;
                        for (int si = 0; si < 3; si++)
                        {
                            for (int sj = 0; sj < 3; sj++)
                            {
                                searchSpace[mi + si][mj + sj].erase(cr);
                            }
                        }
                        for (int k = 0; k < 9; k++)
                        {
                            searchSpace[i][k].erase(cr);
                            searchSpace[k][j].erase(cr);
                        }
                        for (int ni = 0; ni < 9; ni++)
                        {
                            for (int nj = 0; nj < 9; nj++)
                            {
                                if (searchSpace[ni][nj].size() == 0 && board[ni][nj] == '.')
                                {
                                    return false;
                                }
                                else if (searchSpace[ni][nj].size() == 1)
                                {
                                    advanced = true;
                                    assert(board[ni][nj] == '.');
                                    char c = *searchSpace[ni][nj].begin();
                                    int mi = ni / 3 * 3;
                                    int mj = nj / 3 * 3;
                                    for (int si = 0; si < 3; si++)
                                    {
                                        for (int sj = 0; sj < 3; sj++)
                                        {
                                            if (board[mi+si][mj+sj] == c)
                                            {
                                                return false;
                                            }
                                        }
                                    }
                                    for (int k = 0; k < 9; k++)
                                    {
                                        if (board[ni][k] == c || board[k][nj] == c)
                                        {
                                            return false;
                                        }
                                    }
                                    board[ni][nj] = c;
                                    searchSpace[ni][nj].clear();
                                    solved++;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (solved == 81) return;

        int mini = -1;
        int minj = -1;
        int minSize = 10;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (searchSpace[i][j].size() != 0 && searchSpace[i][j].size() < minSize)
                {
                    minSize = searchSpace[i][j].size();
                    mini = i;
                    minj = j;
                }
            }
        }

        for (auto & o : searchSpace[mini][minj])
        {
            board[mini][minj] = o;
            printSudoku(board);
            if (solveSudokuInternal(board)){
                return true;
            }
        }
    }
};