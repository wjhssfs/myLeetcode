// 782. Transform to Chessboard
// An N x N board contains only 0s and 1s. In each move, you can swap any 2 rows with each other, or any 2 columns with each other.

// What is the minimum number of moves to transform the board into a "chessboard" - a board where no 0s and no 1s are 4-directionally adjacent? If the task is impossible, return -1.

// Examples:
// Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
// Output: 2
// Explanation:
// One potential sequence of moves is shown below, from left to right:

// 0110     1010     1010
// 0110 --> 1010 --> 0101
// 1001     0101     1010
// 1001     0101     0101

// The first move swaps the first and second column.
// The second move swaps the second and third row.


// Input: board = [[0, 1], [1, 0]]
// Output: 0
// Explanation:
// Also note that the board with 0 in the top left corner,
// 01
// 10

// is also a valid chessboard.

// Input: board = [[1, 0], [1, 0]]
// Output: -1
// Explanation:
// No matter what sequence of moves you make, you cannot end with a valid chessboard.
// Note:

// board will have the same number of rows and columns, a number in the range [2, 30].
// board[i][j] will be only 0s or 1s.


// https://leetcode.com/problems/transform-to-chessboard/discuss/114847/Easy-and-Concise-Solution-with-Explanation-C++JavaPython
// https://leetcode.com/problems/transform-to-chessboard/discuss/114843/Key-Observation-on-property-of-ChessBoard

// Check if the given board satisfy the validness property defined above.
// Find minimum row swap to make the first column valid. If not possible, return -1.
// Find minimum column swap to make the first row valid. If not possible, return -1.
// Return the sum of step 2 and 3.

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& b) {
        int N = b.size(), rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
            // (NW xor NE) == (SW xor SE)
                if (b[0][0]^b[i][0]^b[0][j]^b[i][j]) return -1;
        for (int i = 0; i < N; ++i) {
            rowSum += b[0][i];
            colSum += b[i][0];
            rowSwap += b[i][0] == i % 2;
            colSwap += b[0][i] == i % 2;
        }
        if (N / 2 > rowSum || rowSum > N / 2 + N % 2) return -1;
        if (N / 2 > colSum || colSum > N / 2 + N % 2) return -1;
        if (N % 2) {
            if (colSwap % 2) colSwap = N - colSwap;
            if (rowSwap % 2) rowSwap = N - rowSwap;
        }
        else {
            colSwap = min(N - colSwap, colSwap);
            rowSwap = min(N - rowSwap, rowSwap);
        }
        return (colSwap + rowSwap) / 2;
    }
};

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& b) {
        int N = b.size(), rowSum = 0, colSum = 0, rowSwap0 = 0, colSwap0 = 0, rowSwap1 = 0, colSwap1 = 0;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
                if (b[0][0]^b[i][0]^b[0][j]^b[i][j]) return -1;
        for (int i = 0; i < N; ++i) {
            rowSum += b[0][i];
            colSum += b[i][0];
            rowSwap0 += b[i][0] == i % 2;
            colSwap0 += b[0][i] == i % 2;
            rowSwap1 += b[i][0] != i % 2;
            colSwap1 += b[0][i] != i % 2;
        }
        if (N % 2 && (abs(2 * colSum - N) != 1 || abs(2 * rowSum - N) != 1)) return -1;
        if (!(N % 2) && (colSum * 2 != N || rowSum * 2 != N)) return -1;
        if (rowSwap0 % 2) rowSwap0 = INT_MAX;
        if (colSwap0 % 2) colSwap0 = INT_MAX;
        if (rowSwap1 % 2) rowSwap1 = INT_MAX;
        if (colSwap1 % 2) colSwap1 = INT_MAX;
        return (min(rowSwap0, rowSwap1) + min(colSwap0, colSwap1)) / 2;
    }
};