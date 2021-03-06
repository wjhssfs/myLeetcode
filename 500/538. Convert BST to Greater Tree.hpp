// 538. Convert BST to Greater Tree
// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

// Example:

// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13

// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13

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
public:
    TreeNode* convertBST(TreeNode* root) {
        int s = 0;
        dfs(root, s);
        return root;
    }
private:
    void dfs(TreeNode* root, int &s) {
        if (!root) return;
        dfs(root->right, s);
        s += root->val;
        root->val = s;
        dfs(root->left, s);
    }
};

public TreeNode convertBST(TreeNode root) {
    dfs(root, 0);
    return root;
}
public int dfs(TreeNode root, int val) {
    if(root == null) return val;
    int right = dfs(root.right, val);
    int left = dfs(root.left, root.val + right);
    root.val = root.val + right;
    return left;
}