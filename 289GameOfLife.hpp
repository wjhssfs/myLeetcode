// 289 Game of Life

// According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population..
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// Write a function to compute the next state (after one update) of the board given its current state.

// Follow up: 
// Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
// In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		for (int i = 0; i < (int)board.size(); i++) {
			for (int j = 0; j < (int)board[0].size(); j++){
				calc(board, i, j);
			}
		}
		for (int i = 0; i < (int)board.size(); i++) {
			for (int j = 0; j < (int)board[0].size(); j++){
				if (board[i][j] > 0 && board[i][j] < 3) board[i][j] = 0;
				else if (board[i][j] == 3 || board[i][j] == 4) board[i][j] = 1;
				else if (board[i][j] > 4) board[i][j] = 0;
				else if (board[i][j] == -3) board[i][j] = 1;
				else board[i][j] = 0;
			}
		}
	}

    // calc # of 1's in 3X3 area centered at i,j
	void calc(vector<vector<int>>& board, int i, int j) {
		int total = 0;
		if (i > 0 && board[i - 1][j] > 0) ++total;
		if (i < board.size() - 1 && board[i + 1][j] > 0) ++total;
		if (j > 0 && board[i][j - 1] > 0) ++total;
		if (j < board[0].size() - 1 && board[i][j + 1] > 0) ++total;
		if (i > 0 && j > 0 && board[i - 1][j - 1] > 0) ++total;
		if (i > 0 && j < board[0].size() - 1 && board[i - 1][j + 1] > 0) ++total;
		if (i < board.size() - 1 && j > 0 && board[i + 1][j - 1] > 0) ++total;
		if (i < board.size() - 1 && j < board[0].size() - 1 && board[i + 1][j + 1] > 0) ++total;
		if (board[i][j] == 1) board[i][j] = total + 1;
		else board[i][j] = -total;
	}
};