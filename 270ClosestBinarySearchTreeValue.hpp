// 270 Closest Binary Search Tree Value
// Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

// Note:
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.

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
    int closestValue(TreeNode* root, double target) {
        if(!root) return 0;
        if(root->val == target) return root->val;
        else if(root->val > target) {
            if(!root->left) return root->val;
            int leftVal = closestValue(root->left, target);
            double leftDiff =  leftVal - target;
            if(leftDiff < 0) leftDiff = -leftDiff;
            return root->val - target < leftDiff ? root->val : leftVal;
        } 
        else {
            if(!root->right) return root->val;
            int rightVal = closestValue(root->right, target);
            double rightDiff =  rightVal - target;
            if(rightDiff < 0) rightDiff = - rightDiff;
            return target - root->val < rightDiff ? root->val : rightVal;
        }
    }
};