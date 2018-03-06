// 794. Valid Tic-Tac-Toe State
// A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

// The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

// Here are the rules of Tic-Tac-Toe:

// Players take turns placing characters into empty squares (" ").
// The first player always places "X" characters, while the second player always places "O" characters.
// "X" and "O" characters are always placed into empty squares, never filled ones.
// The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
// The game also ends if all squares are non-empty.
// No more moves can be played if the game is over.
// Example 1:
// Input: board = ["O  ", "   ", "   "]
// Output: false
// Explanation: The first player always plays "X".

// Example 2:
// Input: board = ["XOX", " X ", "   "]
// Output: false
// Explanation: Players take turns making moves.

// Example 3:
// Input: board = ["XXX", "   ", "OOO"]
// Output: false

// Example 4:
// Input: board = ["XOX", "O O", "XOX"]
// Output: true
// Note:

// board is a length-3 array of strings, where each string board[i] has length 3.
// Each board[i][j] is a character in the set {" ", "X", "O"}.

class Solution {
    bool hasThree(vector<string>& board, char c) { 
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
        }
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
        if (board[2][0] == c && board[1][1] == c && board[0][2] == c) return true;
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int nX = 0, nO = 0;
        for (auto&& row : board) {
            for (auto&& cell : row) {
                if (cell == 'X') nX++;
                if (cell == 'O') nO++;
            }
        }
        if (nO > nX || nX > nO + 1) return false;
        bool canXWin = hasThree(board, 'X'), canOWin = hasThree(board, 'O');
        if (canXWin && canOWin) return false;
        if (canXWin) return nX == nO + 1;
        if (canOWin) return nX == nO;
        return true;
    }
};  