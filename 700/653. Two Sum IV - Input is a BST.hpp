// 653. Two Sum IV - Input is a BST

// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

// Example 1:
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 9

// Output: True
// Example 2:
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 28

// Output: False

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
    bool dfs(TreeNode* root, int k, unordered_set<int>& m)
    {
        if (!root) return false;
        if (m.count(root->val)) return true;
        m.insert(k - root->val);
        return dfs(root->left, k, m) || dfs(root->right, k, m);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> m;
        return dfs(root, k, m);
    }
};

bool findTarget(TreeNode* root, int k) {
    return dfs(root, root,  k);
}

bool dfs(TreeNode* root,  TreeNode* cur, int k){
    if(cur == NULL)return false;
    return search(root, cur, k - cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
}

bool search(TreeNode* root, TreeNode *cur, int value){
    if(root == NULL)return false;
    return (root->val == value) && (root != cur) 
        || (root->val < value) && search(root->right, cur, value) 
            || (root->val > value) && search(root->left, cur, value);
}