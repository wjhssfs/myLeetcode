// 913. Cat and Mouse

// A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.

// The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.

// Mouse starts at node 1 and goes first, Cat starts at node 2 and goes second, and there is a Hole at node 0.

// During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].

// Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)

// Then, the game can end in 3 ways:

// If ever the Cat occupies the same node as the Mouse, the Cat wins.
// If ever the Mouse reaches the Hole, the Mouse wins.
// If ever a position is repeated (ie. the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
// Given a graph, and assuming both players play optimally, return 1 if the game is won by Mouse, 2 if the game is won by Cat, and 0 if the game is a draw.

 

// Example 1:

// Input: [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
// Output: 0
// Explanation:
// 4---3---1
// |   |
// 2---5
//  \ /
//   0
 

// Note:

// 3 <= graph.length <= 50
// It is guaranteed that graph[1] is non-empty.
// It is guaranteed that graph[2] contains a non-zero element. 

// https://leetcode.com/problems/cat-and-mouse/solution/
// minmax
class Solution {
    const int DRAW = 0, MOUSE = 1, CAT = 2;
    // What nodes could play their turn to arrive at node (m, c, t) ?
    vector<vector<int>> parents(vector<vector<int>>& graph, int m, int c, int t) {
        vector<vector<int>> ans;
        if (t == CAT) {
            for (int m2: graph[m])
                ans.push_back({m2, c, MOUSE});
        } else {
            for (int c2: graph[c]) if (c2 > 0)
                ans.push_back({m, c2, CAT});
        }
        return ans;
    }
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int N = graph.size();
        int color[50][50][3] = {};
        int degree[50][50][3] = {};

        // degree[node] : the number of DRAW children of this node
        for (int m = 0; m < N; ++m)
            for (int c = 0; c < N; ++c) {
                degree[m][c][MOUSE] = graph[m].size();
                degree[m][c][CAT] = graph[c].size();
                for (int x : graph[c]) if (x == 0) { // Cat can't be at the hole
                    degree[m][c][CAT]--;
                    break;
                }
            }

        // enqueued : all nodes that are colored
        queue<vector<int>> q;
        for (int i = 0; i < N; ++i)
            for (int t = 1; t <= 2; ++t) {
                color[0][i][t] = MOUSE;
                q.push({0, i, t, MOUSE});
                if (i > 0) {
                    color[i][i][t] = CAT;
                    q.push({i, i, t, CAT});
                }
            }

        // percolate
        while (!q.empty()) {
            // for nodes that are colored :
            auto node = q.front(); q.pop();
            int i = node[0], j = node[1], t = node[2], c = node[3];
            // for every parent of this node i, j, t :
            for (auto&& parent: parents(graph, i, j, t)) {
                int i2 = parent[0], j2 = parent[1], t2 = parent[2];
                // if this parent is not colored :
                if (color[i2][j2][t2] == DRAW) {
                    // if the parent can make a winning move (ie. mouse to MOUSE), do so
                    if (t2 == c) {
                        color[i2][j2][t2] = c;
                        q.push({i2, j2, t2, c});
                    } else {
                        // else, this parent has degree[parent]--, and enqueue
                        // if all children of this parent are colored as losing moves
                        degree[i2][j2][t2]--;
                        if (degree[i2][j2][t2] == 0) {
                            color[i2][j2][t2] = 3 - t2;
                            q.push({i2, j2, t2, 3 - t2});
                        }
                    }
                }
            }
        }

        return color[1][2][1];
    }
};