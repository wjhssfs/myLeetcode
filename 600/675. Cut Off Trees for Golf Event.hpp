// 675. Cut Off Trees for Golf Event
// You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

// 0 represents the obstacle can't be reached.
// 1 represents the ground can be walked through.
// The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
// You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

// You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.

// You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

// Example 1:
// Input: 
// [
//  [1,2,3],
//  [0,0,4],
//  [7,6,5]
// ]
// Output: 6
// Example 2:
// Input: 
// [
//  [1,2,3],
//  [0,0,0],
//  [7,6,5]
// ]
// Output: -1
// Example 3:
// Input: 
// [
//  [2,3,4],
//  [0,0,5],
//  [8,7,6]
// ]
// Output: 6
// Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
// Hint: size of the given matrix will not exceed 50x50.

class Solution {
    int bfs(vector<vector<int>>& forest, pair<int, int> start, pair<int, int> target) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(forest.size(), vector<bool>(forest[0].size()));
        q.emplace(start);
        visited[start.first][start.second] = true;
        int step = 0;
        while (q.size()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto f = q.front();
                q.pop();
                if (f == target) return step;
                vector<int> d{0, 1, 0, -1, 0};
                for (int k = 0; k < 4; ++k) {
                    pair<int, int> cur = make_pair(f.first + d[k], f.second + d[k + 1]);
                    if (cur.first < 0 || cur.second < 0 ||
                        cur.first == forest.size() || cur.second == forest[0].size() ||
                        forest[cur.first][cur.second] == 0 ||
                       visited[cur.first][cur.second] == true) continue;
                    q.emplace(cur);
                    visited[cur.first][cur.second] = true;
                }
            }
            ++step;
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        map<int, pair<int, int>> trees;
        for (int i = 0; i < forest.size(); ++i) {
            for (int j = 0; j < forest[0].size(); ++j) {
                if (forest[i][j] > 1) {
                    trees[forest[i][j]] = make_pair(i, j);
                }
            }
        }
        int res = 0;
        pair<int, int> start{0, 0};
        for (auto&& tree : trees) {
            int cur = bfs(forest, start, tree.second);
            //cout << start.first << ":" << start.second << " " << tree.second.first << ":" << tree.second.second <<" " <<  cur << endl;
            if (cur == -1) return -1;
            forest[tree.second.first][tree.second.second] = 1;
            res += cur;
            start = tree.second;
        }
        return res;
    }
};