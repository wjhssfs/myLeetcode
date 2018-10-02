// 685. Redundant Connection II

// In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

// The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

// The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

// Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

// Example 1:
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: The given directed graph will be like this:
//   1
//  / \
// v   v
// 2-->3
// Example 2:
// Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
// Output: [4,1]
// Explanation: The given directed graph will be like this:
// 5 <- 1 -> 2
//      ^    |
//      |    v
//      4 <- 3
// Note:
// The size of the input 2D-array will be between 3 and 1000.
// Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.


class Solution {
    bool isValid(vector<int>& inD, unordered_map<int, unordered_set<int>>& g) {
        unordered_set<int> connected;
        for (int i = 0; i < inD.size(); ++i) {
            if(inD[i] == 0) connected.insert(i + 1);
        }
        if (connected.size() != 1) return false;
        queue<int> q;
        q.push(*connected.begin());
        while (q.size()) {
            for (int i = 0; i < q.size(); ++i) {
                for (auto next : g[q.front()]) {
                    if (connected.insert(next).second) q.push(next);
                }
                q.pop();
            }
        }
        return connected.size() == inD.size();
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> inD(edges.size());
        unordered_map<int, unordered_set<int>> g;
        for (auto&& edge : edges) {
            ++inD[edge[1] - 1];
            g[edge[0]].insert(edge[1]);
        }
        for (int i = (int)edges.size() - 1; i >= 0; --i) {
            --inD[edges[i][1] - 1];
            g[edges[i][0]].erase(edges[i][1]);
            if (isValid(inD, g)) return edges[i];
            ++inD[edges[i][1] - 1];
            g[edges[i][0]].insert(edges[i][1]);
        }
        return {};
    }
};


class Solution {
    bool isValid(vector<int>& inD, vector<vector<int>>& edges, int cur) {
        unordered_set<int> connected;
        for (int i = 0; i < inD.size(); ++i) {
            if(inD[i] == 0) connected.insert(i + 1);
        }
        if (connected.size() != 1) return false;
        size_t lastSize = 0;
        while (connected.size() != lastSize) {
            lastSize = connected.size();
            for (int i = 0; i < edges.size(); ++i) {
                if (i == cur) continue;
                if (connected.count(edges[i][0])) connected.insert(edges[i][1]);
            }
        }
        return lastSize == inD.size();
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> inD(edges.size());
        for (auto&& edge : edges) ++inD[edge[1] - 1];
        for (int i = (int)edges.size() - 1; i >= 0; --i) {
            --inD[edges[i][1] - 1];
            if (isValid(inD, edges, i)) return edges[i];
            ++inD[edges[i][1] - 1];
        }
        return {};
    }
};


// https://discuss.leetcode.com/topic/105108/c-java-really-working-solution-union-find-with-explanation
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0]; 
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        } 
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge:edges) {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1], pu = root(parent, u);
            // Now every node only has 1 parent, so root of v is implicitly v
            if (pu == v) {
                if (candA.empty()) return edge;
                return candA;
            }
            parent[v] = pu;
        }
        return candB;
    }
private:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k) 
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
};