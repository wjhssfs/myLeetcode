// 723. Candy Crush
// This question is about implementing a basic elimination algorithm for Candy Crush.

// Given a 2D integer array board representing the grid of candy, different positive integers board[i][j] represent different types of candies. A value of board[i][j] = 0 represents that the cell at position (i, j) is empty. The given board represents the state of the game following the player's move. Now, you need to restore the board to a stable state by crushing candies according to the following rules:

// If three or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the same time - these positions become empty.
// After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)
// After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
// If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
// You need to perform the above rules until the board becomes stable, then return the current board.

// Example 1:
// Input:
// board = 
// [[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]
// Output:
// [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]
// Explanation: 

// Note:
// The length of board will be in the range [3, 50].
// The length of board[i] will be in the range [3, 50].
// Each board[i][j] will initially start as an integer in the range [1, 2000].

class Solution {
    bool crush(vector<vector<int>>& board) {
        vector<vector<int>> nLeft(board.size(), vector<int>(board[0].size(), 1));
        auto nTop = nLeft;
        bool crushed = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 0) continue;
                if (i > 0 && board[i][j] == board[i - 1][j]) nTop[i][j] = nTop[i - 1][j] + 1;
                if (j > 0 && board[i][j] == board[i][j - 1]) nLeft[i][j] = nLeft[i][j - 1] + 1;
            }
        }
        for (int i = board.size() - 1; i >= 0; --i) {
            for (int j = board[0].size() - 1; j >= 0; --j) {
                if (nTop[i][j] >= 3) {
                    int t = nTop[i][j];
                    for (int k = 0; k < t; ++k) {
                        board[i - k][j] = 0;
                        nTop[i - k][j] = 0;
                        crushed = true;
                    }
                }
                if (nLeft[i][j] >= 3) {
                    int t = nLeft[i][j];
                    for (int k = 0; k < t; ++k) {
                        board[i][j - k] = 0;
                        nLeft[i][j - k] = 0;
                        crushed = true;
                    }
                }
            }
        }
        if (crushed) drop(board);
        return crushed;
    }
    
    void drop(vector<vector<int>>& board) {
        for (int j = 0; j < board[0].size(); ++j) {
            for (int p1 = board.size() - 1, p2 = p1; p1 >= 0; p1--) {
                while(p2 >= 0 && board[p2][j] == 0) --p2;
                board[p1][j] = p2 < 0 ? 0 : board[p2--][j];
            }
        }
    }
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while(crush(board));
        return board;
    }
};

class Solution {
    bool crush(vector<vector<int>>& board) {
        auto boardN = board;
        bool crushed = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int v = board[i][j], u = boardN[i][j];
                if (i > 1 && v != 0 && board[i-2][j] == v && board[i-1][j] == v) {
                    crushed = true;
                    for (int ii = i - 2; ii < board.size() && board[ii][j] == v; ++ii)
                        board[ii][j] = 0;
                }
                if (j > 1 && u != 0 && boardN[i][j-2] == u && boardN[i][j-1] == u) {
                    crushed = true;
                    for (int jj = j - 2; jj < boardN[0].size() && boardN[i][jj] == u; ++jj)
                        boardN[i][jj] = 0;
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (boardN[i][j] == 0) board[i][j] = 0;
            }
        }
        if (crushed) drop(board);
        return crushed;
    }
    
    void drop(vector<vector<int>>& board) {
        for (int j = 0; j < board[0].size(); ++j) {
            for (int p1 = board.size() - 1, p2 = p1; p1 >= 0; p1--) {
                while(p2 >= 0 && board[p2][j] == 0) --p2;
                board[p1][j] = p2 < 0 ? 0 : board[p2--][j];
            }
        }
    }
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while(crush(board));
        return board;
    }
};