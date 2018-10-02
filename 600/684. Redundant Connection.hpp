// 684. Redundant Connection
// We are given a "tree" in the form of a 2D-array, with distinct values for each node.

// In the given 2D-array, each element pair [u, v] represents that v is a child of u in the tree.

// We can remove exactly one redundant pair in this "tree" to make the result a tree.

// You need to find and output such a pair. If there are multiple answers for this question, output the one appearing last in the 2D-array. There is always at least one answer.

// Example 1:
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: Original tree will be like this:
//   1
//  / \
// 2 - 3
// Example 2:
// Input: [[1,2], [1,3], [3,1]]
// Output: [3,1]
// Explanation: Original tree will be like this:
//   1
//  / \\
// 2   3
// Note:
// The size of the input 2D-array will be between 1 and 1000.
// Every integer represented in the 2D-array will be between 1 and 2000.

// There is a wrong test case, Input: [[2,3],[5,2],[1,5],[4,2],[4,1]] Output: [4,2].
// in this test case, it is not a tree. The problem should have been acyclic connected graph
// and [u, v] just means u, v connected
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(2001);
        iota(p.begin(), p.end(), 0);
        for (auto&& edge : edges) {
            if (p[edge[0]] == p[edge[1]]) return edge;
            int oldP = p[edge[1]];
            for (int i = 1; i < p.size(); ++i) {
                if (p[i] == oldP) p[i] = p[edge[0]];
            }    
            p[edge[1]] = p[edge[0]];
        }
        return {};
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(2001);
        iota(p.begin(), p.end(), 0);
        for (auto&& edge : edges) {
            if (p[edge[0]] == p[edge[1]]) return edge;
            replace(p.begin(), p.end(), int(p[edge[1]]) /* get rid of ref param side effect*/, p[edge[0]]);
        }
        return {};
    }
};