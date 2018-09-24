// 865. Smallest Subtree with all the Deepest Nodes

// Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

// A node is deepest if it has the largest depth possible among any node in the entire tree.

// The subtree of a node is that node, plus the set of all descendants of that node.

// Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

 

// Example 1:

// Input: [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation:



// We return the node with value 2, colored in yellow in the diagram.
// The nodes colored in blue are the deepest nodes of the tree.
// The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
// The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
// Both the input and output have TreeNode type.
 

// Note:

// The number of nodes in the tree will be between 1 and 500.
// The values of each node are unique.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// top down
class Solution {
    TreeNode* res;
    int maxDepth;
    int dfs(TreeNode* root, int depth) {
        if (!root) return -1;
        int leftDepth = dfs(root->left, depth + 1);
        int rightDepth = dfs(root->right, depth + 1);
        if (leftDepth != -1 && leftDepth == rightDepth && leftDepth == maxDepth) {
            res = root;
            return maxDepth;
        }
        int ret = depth;
        ret = max(ret, leftDepth);
        ret = max(ret, rightDepth);
        if (ret > maxDepth) res = root;
        maxDepth = max(ret, maxDepth);
        return ret;
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        res = nullptr;
        maxDepth = -1;
        dfs(root, 0);
        return res;
    }
};

// bottom to up
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return deep(root).second;
    }

    pair<int, TreeNode*> deep(TreeNode* root) {
        if (!root) return {0, NULL};
        pair<int, TreeNode*> l = deep(root->left), r = deep(root->right);

        int d1 = l.first, d2 = r.first;
        return {max(d1, d2) + 1, d1 == d2 ? root : d1 > d2 ? l.second : r.second};
    }