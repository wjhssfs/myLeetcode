// 463. Island Perimeter
// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Example:

// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]

// Answer: 16

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        int total = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    if (i == 0 || !grid[i-1][j]) ++total;
                    if (j == 0 || !grid[i][j-1]) ++total;
                    if (i == m - 1 || !grid[i+1][j]) ++total;
                    if (j == n - 1 || !grid[i][j+1]) ++total;
                }
            }
        }
        return total;
    }
};

// loop over the matrix and count the number of islands;
// if the current dot is an island, count if it has any right neighbour or down neighbour;
// the result is islands * 4 - neighbours * 2
public class Solution {
    public int islandPerimeter(int[][] grid) {
        int islands = 0, neighbours = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    islands++; // count islands
                    if (i < grid.length - 1 && grid[i + 1][j] == 1) neighbours++; // count down neighbours
                    if (j < grid[i].length - 1 && grid[i][j + 1] == 1) neighbours++; // count right neighbours
                }
            }
        }

        return islands * 4 - neighbours * 2;
    }
}

public static int islandPerimeter(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) return 0;
        int result = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    result += 4;
                    if (i > 0 && grid[i-1][j] == 1) result -= 2;
                    if (j > 0 && grid[i][j-1] == 1) result -= 2;
                }
            }
        }
        return result;
    }


def islandPerimeter(self, grid):
    return sum(sum(map(operator.ne, [0] + row, row + [0]))
               for row in grid + map(list, zip(*grid)))

for row in... is list comprehension a generator expression, where row is a row or column of the map. Second, the + map(list, zip(*grid))) 
is appending the transposition of the map, so columns become rows. The resulting extended grid looks like

[0, 1, 0, 0]
[1, 1, 1, 0]
[0, 1, 0, 0]
[1, 1, 0, 0]
[0, 1, 0, 1]
[1, 1, 1, 1]
[0, 1, 0, 0]
[0, 0, 0, 0]

[0] + [1,2,3,4,5,6,7,8] = [0,1,2,3,4,5,6,7,8]
[1,2,3,4,5,6,7,8] + [0] = [1,2,3,4,5,6,7,8,0]

basically, operator.ne compares 1 with 0 and 2, and compares 2 with 1 and 3...... It compares every element with its two neighbors.