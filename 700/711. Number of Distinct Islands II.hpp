// 711. Number of Distinct Islands II
// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// Count the number of distinct islands. An island is considered to be the same as another if they have the same shape, or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).

// Example 1:
// 11000
// 10000
// 00001
// 00011
// Given the above grid map, return 1. 

// Notice that:
// 11
// 1
// and
//  1
// 11
// are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.
// Example 2:
// 11100
// 10001
// 01001
// 01110
// Given the above grid map, return 2.

// Here are the two distinct islands:
// 111
// 1
// and
// 1
// 1

// Notice that:
// 111
// 1
// and
// 1
// 111
// are considered same island shapes. Because if we flip the first array in the up/down direction, then they have the same shapes.
// Note: The length of each dimension in the given grid does not exceed 50.
// 711. Number of Distinct Islands II.hpp
// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// Count the number of distinct islands. An island is considered to be the same as another if they have the same shape, or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).

// Example 1:
// 11000
// 10000
// 00001
// 00011
// Given the above grid map, return 1. 

// Notice that:
// 11
// 1
// and
//  1
// 11
// are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.
// Example 2:
// 11100
// 10001
// 01001
// 01110
// Given the above grid map, return 2.

// Here are the two distinct islands:
// 111
// 1
// and
// 1
// 1

// Notice that:
// 111
// 1
// and
// 1
// 111
// are considered same island shapes. Because if we flip the first array in the up/down direction, then they have the same shapes.
// Note: The length of each dimension in the given grid does not exceed 50.

// https://discuss.leetcode.com/topic/107494/consise-c-solution-using-dfs-sorting-to-find-canonical-representation-for-each-island
// https://en.wikipedia.org/wiki/Dihedral_group
class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &g, vector<pair<int,int>>& mp) {
        if ( r < 0 || c < 0 || r >= g.size() || c >= g[0].size()) return;
        if (g[r][c] != 1) return;
        g[r][c] = 2; // mark as used
        mp.push_back({r,c});
        dfs(r+1,c,g,mp);
        dfs(r-1,c,g,mp);
        dfs(r,c+1,g,mp);
        dfs(r,c-1,g,mp);
    }
    
    vector<pair<int,int>> norm(vector<pair<int,int>>& v) {
        vector<vector<pair<int,int>>> s(8);
        // compute rotations/reflections.
        for (auto p:v) {
            int x = p.first, y = p.second;
            s[0].push_back({x,y}); // org
            s[1].push_back({x,-y}); // up/down
            s[2].push_back({-x,y}); // left/right
            s[3].push_back({-x,-y}); // r180
            s[4].push_back({y,-x}); // r90
            s[5].push_back({-y,x});  // r270
            s[6].push_back({-y,-x}); // r270 + up/down
            s[7].push_back({y,x}); // r90 + up/down
        }
        for (auto &l:s) sort(l.begin(),l.end());
        for (auto &l:s) {
            for (int i = 1; i < v.size(); ++i) 
                l[i] = {l[i].first-l[0].first, l[i].second - l[0].second};
            l[0] = {0,0};
        }
        sort(s.begin(),s.end());
        return s[0];
    }
    
    int numDistinctIslands2(vector<vector<int>>& g) {
        set<vector<pair<int,int>>> s;
        for (int i = 0; i < g.size(); ++i) 
            for (int j = 0; j < g[i].size(); ++j) 
                if (g[i][j] == 1) {
                    vector<pair<int,int>> mp;
                    dfs(i,j,g, mp);
                    s.insert(norm(mp));
                }
        
        return s.size();
    }
};