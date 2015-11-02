// 296 Best Meeting Point
// A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

// For example, given three people living at (0,0), (0,4), and (2,2):

// 1 - 0 - 0 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
// The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

// Hint:

// Try to solve it in one dimension first. How can this solution apply to the two dimension case?

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int nRow = grid.size();
        if(!nRow) return 0;
        int nColumn = grid[0].size();
        if(!nColumn) return 0;
        vector<int> row(nRow), column(nColumn);
        for(int i = 0; i < nRow; i++) {
            for(int j = 0; j < nColumn; j++) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    column[j]++;
                }
            }
        }
        
        int rowMin = INT_MAX;
        for(int i = 0; i < nRow; i++) {
            int curSum = 0;
            for(int j = 0; j < nRow; j++) {
                curSum += abs(i-j) * row[j];
            }
            rowMin = min(rowMin, curSum);
        }
        
        int columnMin = INT_MAX;
        for(int i = 0; i < nColumn; i++) {
            int curSum = 0;
            for(int j = 0; j < nColumn; j++) {
                curSum += abs(i-j) * column[j];
            }
            columnMin = min(columnMin, curSum);
        }
        
        return rowMin + columnMin;
    }
};