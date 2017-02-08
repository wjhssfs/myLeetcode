// 407. Trapping Rain Water II
// Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

// Note:
// Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

// Example:

// Given the following 3x6 height map:
// [
//   [1,4,3,1,3,2],
//   [3,2,1,3,2,4],
//   [2,3,3,2,3,1]
// ]

// Return 4.

// The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.


// After the rain, water are trapped between the blocks. The total volume of water trapped is 4.

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m < 3) return 0;
        int n = heightMap[0].size();
        if (n < 3) return 0;
        vector<vector<char>> visited(m, vector<char>(n));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < m; ++i) {
            pq.emplace(heightMap[i][0], make_pair(i, 0));
            visited[i][0] = true;
            pq.emplace(heightMap[i][n-1], make_pair(i, n-1));
            visited[i][n-1] = true;
        }
        for (int i = 1; i < n - 1; ++i) {
            pq.emplace(heightMap[0][i], make_pair(0,i));
            visited[0][i] = true;
            pq.emplace(heightMap[m-1][i], make_pair(m-1, i));
            visited[m-1][i] = true;
        }
        
        int res = 0;
        while (pq.size()) {
            auto cur = pq.top(); pq.pop();
            //cout << cur.first << " " << cur.second.first << " " << cur.second.second << endl;
            int dir[] = {-1, 0, 1, 0, -1};
            for (int i = 0; i < 4; ++i) {
                int row = cur.second.first + dir[i];
                int col = cur.second.second + dir[i+1];
                if (row < 0 || row == m || col < 0 || col == n) continue;
                if (visited[row][col]) continue;
                visited[row][col] = true;
                res += max(0, cur.first - heightMap[row][col]);
                pq.emplace(max(cur.first, heightMap[row][col]), make_pair(row, col));
            }
        }
        return res;
    }
};