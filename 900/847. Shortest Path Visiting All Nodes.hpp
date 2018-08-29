// 847. Shortest Path Visiting All Nodes
// An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

// graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

// Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

// Example 1:

// Input: [[1,2,3],[0],[0],[0]]
// Output: 4
// Explanation: One possible path is [1,0,2,0,3]
// Example 2:

// Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
// Output: 4
// Explanation: One possible path is [0,1,4,2,3]
 

// Note:

// 1 <= graph.length <= 12
// 0 <= graph[i].length < graph.length

// https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/135686/Java-DP-Solution

class Solution {
    struct State {
        unsigned mask;
        int source;
    };
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        vector<vector<int>> dp(graph.size(), vector<int>(1 << graph.size(), INT_MAX));
        queue<State> q;
        for (int i = 0; i < graph.size(); ++i) {
            dp[i][1<<i] = 0;
            q.push({1 << i, i});
        }
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            for (int next : graph[s.source]) {
                unsigned nextMask = s.mask | (1 << next);
                if (dp[next][nextMask] > dp[s.source][s.mask] + 1) {
                    dp[next][nextMask] = dp[s.source][s.mask] + 1;
                    q.push({nextMask, next});
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < graph.size(); ++i) {
            res = min(res, dp[i][(1 << graph.size()) - 1]);
        }
        
        return res;
    }
};