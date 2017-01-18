// 98 Validate Binary Search Tree 
// Given a binary tree, determine if it is a valid binary search tree (BST).
// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int cur = INT_MIN;
        return inOrder(root, cur);
    }

    bool inOrder(TreeNode *root, int &cur) {
        if (!root) return true;
        if (inOrder(root->left, cur) && root->val > cur) {
            cur = root->val;
            return inOrder(root->right, cur);
        }
        return false;
    }
};

class Solution2 {
public:
    // solution: lower bound + higher bound
    bool isValidBST(TreeNode *root) {
        return isValidBSTRe_1(root, INT_MIN, INT_MAX);
    }

    bool isValidBSTRe_1(TreeNode *node, int lower, int upper){
        if (!node) return true;
        if (node->val <= lower || node->val >= upper) return false;

        return isValidBSTRe_1(node->left, lower, node->val) && 
               isValidBSTRe_1(node->right, node->val, upper);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};
