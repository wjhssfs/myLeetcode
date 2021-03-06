// 840. Magic Squares In Grid
// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

// Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

 

// Example 1:

// Input: [[4,3,8,4],
//         [9,5,1,9],
//         [2,7,6,2]]
// Output: 1
// Explanation: 
// The following subgrid is a 3 x 3 magic square:
// 438
// 951
// 276

// while this one is not:
// 384
// 519
// 762

// In total, there is only one magic square inside the given grid.
// Note:

// 1 <= grid.length <= 10
// 1 <= grid[0].length <= 10
// 0 <= grid[i][j] <= 15

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;
        int res = 0;
        for (int i = 0; i < grid.size() - 2; i++) {
            for (int j = 0; j < grid[0].size() - 2; j++) {
                if (helper(grid, i, j))
                    res++;
            }
        }
        return res;
    }
    bool helper(vector<vector<int>>& grid, int row, int col) {
        unordered_set<int> m;
        //judge rows
        int sum = 0;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9)
                    return false;
                sum += grid[i][j];
                if (m.count(grid[i][j]) != 0) return false;
                m.insert(grid[i][j]);
            }
            if (sum != 15)
                return false;
            else 
                sum = 0;
        }
        //judge cols
        for (int i = col; i < col + 3; i++) {
            for (int j = row; j < row + 3; j++) {
                if (grid[j][i] < 1 || grid[j][i] > 9)
                    return false;
                sum += grid[j][i];   
            }
            if (sum != 15)
                return false;
            else
                sum = 0;
        }  
        //judge diagonal1
        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != 15)
            return false;
        
        //judge diagonal2
        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != 15)
            return false;
        
        return true;
    }
};

// The center of magic square must be 5.
// Another observation for other 8 numbers:
// The even must be in the corner, and the odd must be on the edge.
// And it must be in a order like "43816729" （clockwise or anticlockwise)
// https://leetcode.com/problems/magic-squares-in-grid/discuss/133874/Python-5-and-43816729
 def numMagicSquaresInside(self, g):
        def isMagic(i, j):
            s = "".join(str(g[i + x / 3][j + x % 3]) for x in [0, 1, 2, 5, 8, 7, 6, 3])
            return g[i][j] % 2 == 0 and (s in "43816729" * 2 or s in "43816729"[::-1] * 2)
        return sum(isMagic(i, j) for i in range(len(g) - 2) for j in range(len(g[0]) - 2) if g[i + 1][j + 1] == 5)