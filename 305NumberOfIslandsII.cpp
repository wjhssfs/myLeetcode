// 305 Number of Islands II

// A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example:

// Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
// Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

// 0 0 0
// 0 0 0
// 0 0 0
// Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

// 1 0 0
// 0 0 0   Number of islands = 1
// 0 0 0
// Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

// 1 1 0
// 0 0 0   Number of islands = 1
// 0 0 0
// Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

// 1 1 0
// 0 0 1   Number of islands = 2
// 0 0 0
// Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

// 1 1 0
// 0 0 1   Number of islands = 3
// 0 1 0
// We return the result as an array: [1, 1, 2, 3]

// Challenge:

// Can you do it in time complexity O(k log mn), where k is the length of the positions?

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<vector<int>> grid(m, vector<int>(n));
        map<int, set<pair<int,int>>> islands;
        int islandID = 0;
        vector<int> result;
        for(auto && land : positions) {
            if(grid[land.first][land.second] != 0) continue;
            ++islandID;
            islands[islandID] = set<pair<int,int>>({land});
            vector<int> toBeComBined;
            if(land.first > 0 && grid[land.first -1][land.second])
                toBeComBined.push_back(grid[land.first -1][land.second]);
            if(land.second > 0 && grid[land.first][land.second - 1])
                toBeComBined.push_back(grid[land.first][land.second - 1]);
            if(land.first < m - 1 && grid[land.first + 1][land.second])
                toBeComBined.push_back(grid[land.first+1][land.second]);
            if(land.second < n - 1 && grid[land.first][land.second + 1])
                toBeComBined.push_back(grid[land.first][land.second + 1]);
            for(int i = 0; i < toBeComBined.size(); i++){
                islands[islandID].insert(islands[toBeComBined[i]].begin(), islands[toBeComBined[i]].end());
                islands.erase(toBeComBined[i]);
            }
            for(auto &&cordinate : islands[islandID]){
                grid[cordinate.first][cordinate.second] = islandID;
            }
            result.push_back((int)islands.size());
        }
        return result;
    }
};