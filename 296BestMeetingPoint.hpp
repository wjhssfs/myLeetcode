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


int minTotalDistance(vector<vector<int>>& grid) {
    const int row = grid.size();
    if (0 == row) return 0;
    const int col = grid[0].size();
    int total = 0;
    vector<int> posR, posC;
    for (int i = 0; i < row; ++i) 
     for (int j = 0; j < col; ++j) {
         if (grid[i][j] == 1) {
             posR.emplace_back(i);
             posC.emplace_back(j);
         }
     }
    int med1 = posR[posR.size() / 2];
    nth_element(posC.begin(), posC.begin() +  posC.size() / 2, posC.end());
    int med2 = posC[posC.size() / 2];
    for (auto pos1 : posR) total += abs(pos1 - med1);
    for (auto pos2 : posC) total += abs(pos2 - med2);
    return total;
}

public int minTotalDistance(int[][] grid) {
    int m = grid.length;
    int n = grid[0].length;

    List<Integer> I = new ArrayList<>(m);
    List<Integer> J = new ArrayList<>(n);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                I.add(i);
                J.add(j);
            }
        }
    }

    return getMin(I) + getMin(J);
}

private int getMin(List<Integer> list){
    int ret = 0;

    Collections.sort(list);

    int i = 0;
    int j = list.size() - 1;
    while(i < j){
        ret += list.get(j--) - list.get(i++);
    }

    return ret;
}


//https://leetcode.com/discuss/65366/o-mn-java-2ms
public int minTotalDistance(int[][] grid) {
    int m = grid.length, n = grid[0].length;
    int[] I = new int[m], J = new int[n];
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            if (grid[i][j] == 1) {
                ++I[i];
                ++J[j];
            }
    int total = 0;
    for (int[] K : new int[][]{ I, J }) {
        int i = 0, j = K.length - 1;
        while (i < j) {
            int k = Math.min(K[i], K[j]);
            total += k * (j - i);
            if ((K[i] -= k) == 0) ++i;
            if ((K[j] -= k) == 0) --j;
        }
    }
    return total;
}