// 404. Sum of Left Leaves

// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int result = 0;
        if (root->left && !root->left->left && !root->left->right) result = root->left->val;
        else result += sumOfLeftLeaves(root->left);
        result += sumOfLeftLeaves(root->right);
        return result;
    }
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return sumOfLeftLeaves(root->left, true) +  sumOfLeftLeaves(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root, bool isLeft) {
        if (!root) return 0;
        if (!root->left && !root->right && isLeft) return root->val;
        return sumOfLeftLeaves(root->left, true) +  sumOfLeftLeaves(root->right, false);
    }
};