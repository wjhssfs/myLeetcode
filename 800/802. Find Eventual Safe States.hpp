// 802. Find Eventual Safe States
// In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

// Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

// Which nodes are eventually safe?  Return them as an array in sorted order.

// The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

// Example:
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Here is a diagram of the above graph.

// Illustration of graph

// Note:

// graph will have length at most 10000.
// The number of edges in the graph will not exceed 32000.
// Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].

class Solution {
    enum class State {visiting = 0, hasCircle = 1, terminal = 2, unKnown = 3};
    bool dfs(vector<vector<int>>& graph, vector<State>& states, int i) {
        if (states[i] == State::visiting || states[i] == State::hasCircle) {
            states[i] = State::hasCircle;
            return true;
        } else if (states[i] == State::terminal) {
            return false;
        }
        states[i] = State::visiting;
        for (int j = 0; j < graph[i].size(); ++j) {
            if (dfs(graph, states, graph[i][j])) {
                states[i] = State::hasCircle;
                return true;
            }
        }
        states[i] = State::terminal;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = (int)graph.size();
        vector<State> states(n, State::unKnown);
        for (int i = 0; i < n; ++i) {
            dfs(graph, states, i);
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) if (states[i] == State::terminal) res.push_back(i);
        return res;
    }
};