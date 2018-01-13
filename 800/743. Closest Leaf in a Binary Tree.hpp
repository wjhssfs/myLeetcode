// 743. Closest Leaf in a Binary Tree
// Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

// Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

// In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

// Example 1:

// Input:
// root = [1, 3, 2], k = 1
// Diagram of binary tree:
//           1
//          / \
//         3   2

// Output: 2 (or 3)

// Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
// Example 2:

// Input:
// root = [1], k = 1
// Output: 1

// Explanation: The nearest leaf node is the root node itself.
// Example 3:

// Input:
// root = [1,2,3,4,null,null,null,5,null,6], k = 2
// Diagram of binary tree:
//              1
//             / \
//            2   3
//           /
//          4
//         /
//        5
//       /
//      6

// Output: 3
// Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
// Note:
// root represents a binary tree with at least 1 node and at most 1000 nodes.
// Every node has a unique node.val in range [1, 1000].
// There exists some node in the given binary tree for which node.val == k.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int dfs(TreeNode* root,
            int k,
            int& dK, /* distance to decendant k */
            int &vLeave, /* value of leave that is closest to root */
            int& res,
            int& minD) {
        if (!root) return INT_MAX;
        
        int dLeftK = INT_MAX, dRightK = INT_MAX, vLeftLeave = INT_MAX, vRightLeave = INT_MAX;
        int dLeftLeave = dfs(root->left, k, dLeftK, vLeftLeave, res, minD);
        int dRightLeave = dfs(root->right, k, dRightK, vRightLeave, res, minD);
        int dLeave = INT_MAX;
        if (!root->left && !root->right) {
            dLeave = 0;
            vLeave = root->val;
        } else {
            dLeave = min(dLeftLeave, dRightLeave) + 1;
            vLeave = dLeftLeave < dRightLeave ? vLeftLeave : vRightLeave;
        }
        
        dK = dLeftK == INT_MAX ? dK : dLeftK + 1;
        dK = dRightK == INT_MAX ? dK : dRightK + 1;
        if (root->val == k) dK = 0;
        if (dK != INT_MAX && dLeave + dK < minD) {
            minD = dLeave + dK;
            res = vLeave;
        }
        return dLeave;
    }
public:
    int findClosestLeaf(TreeNode* root, int k) {
        int res = INT_MAX, dK = INT_MAX, vLeave = INT_MAX, minD = INT_MAX;
        dfs(root, k, dK, vLeave, res, minD);
        return res;
    }
};


// first run traverse function to convert the tree into an undirected graph and keep track of the leaf nodes in a set.
// Then we perform a BFS on the graph from node K, terminating as soon as we find a leaf node.
class Solution(object):
    def findClosestLeaf(self, root, k):
        # Time: O(n)
        # Space: O(n)
        from collections import defaultdict
        graph, leaves = defaultdict(list), set()
        # Graph construction
        def traverse(node):
            if not node:
                return
            if not node.left and not node.right:
                leaves.add(node.val)
                return
            if node.left:
                graph[node.val].append(node.left.val)
                graph[node.left.val].append(node.val)
                traverse(node.left)
            if node.right:
                graph[node.val].append(node.right.val)
                graph[node.right.val].append(node.val)
                traverse(node.right)
        traverse(root)
        # Graph traversal - BFS
        queue = [k]
        while len(queue):
            next_queue = []
            for node in queue:
                if node in leaves:
                    return node
                next_queue += graph.pop(node, [])
            queue = next_queue



