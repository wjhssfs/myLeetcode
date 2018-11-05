// 687. Longest Univalue Path

// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

// Note: The length of path between two nodes is represented by the number of edges between them.

// Example 1:

// Input:

//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
// Output:

// 2
// Example 2:

// Input:

//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
// Output:

// 2
// Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

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
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int lr = dfs(root->left);
        int rr = dfs(root->right);
        if (root->left && root->left->val != root->val) lr = 0;
        if (root->right && root->right->val != root->val) rr = 0;
        r = max(r, lr + rr + 1);
        return max(lr, rr) + 1;
    }
    int r;
public:
    int longestUnivaluePath(TreeNode* root) {
        r = 1;
        dfs(root);
        return r - 1;
    }
};

int len = 0; // global variable
public int longestUnivaluePath(TreeNode root) {
    if (root == null) return 0;
    len = 0;
    getLen(root, root.val);
    return len;
}

private int getLen(TreeNode node, int val) {
    if (node == null) return 0;
    int left = getLen(node.left, node.val);
    int right = getLen(node.right, node.val);
    len = Math.max(len, left + right);
    if (val == node.val)  return Math.max(left, right) + 1;
    return 0;
}