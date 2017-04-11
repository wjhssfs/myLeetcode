// 549. Binary Tree Longest Consecutive Sequence II
// Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

// Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

// Example 1:
// Input:
//         1
//        / \
//       2   3
// Output: 2
// Explanation: The longest consecutive path is [1, 2] or [2, 1].
// Example 2:
// Input:
//         2
//        / \
//       1   3
// Output: 3
// Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
// Note: All the values of tree nodes are in the range of [-1e7, 1e7].

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
    int longestConsecutive(TreeNode* root) {
        int s = 0, g = 0, res = 0;
        dfs(root, s, g, res);
        return res;
    }
private:
    void dfs(TreeNode *root, int &ns, int &ng, int &res) {
        if (!root) {
            ns = 0;
            ng = 0;
            return;
        }
        int lns = 0, lng = 0, rns = 0, rng = 0;
        dfs(root->left, lns, lng, res);
        dfs(root->right, rns, rng, res);
        if (root->left &&  root->left->val + 1 == root->val) ns = lns + 1;
        if (root->right && root->right->val + 1 == root->val) ns = max(ns, rns + 1);
        if (root->left && root->left->val - 1 == root->val) ng = lng + 1;
        if (root->right && root->right->val - 1 == root->val) ng = max(ng, rng + 1);
        res = max(res, ns + ng + 1);
    }
};