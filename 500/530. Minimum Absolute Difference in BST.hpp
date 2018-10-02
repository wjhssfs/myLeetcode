// 530. Minimum Absolute Difference in BST
// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

// Example:

// Input:

//    1
//     \
//      3
//     /
//    2

// Output:
// 1

// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
// Note: There are at least two nodes in this BST.

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
    int getMinimumDifference(TreeNode* root) {
        pre = nullptr; minDiff = INT_MAX;
        dfs(root);
        return minDiff;
    }
private:
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (pre) {
            minDiff = min(minDiff, abs(root->val - pre->val));
        }
        pre = root;
        dfs(root->right);
        
    }
    TreeNode *pre;
    int minDiff;
};