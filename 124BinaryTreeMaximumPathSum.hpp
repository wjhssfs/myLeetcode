// 124 Binary Tree Maximum Path Sum 
// Given a binary tree, find the maximum path sum.
// 
// The path may start and end at any node in the tree.
// 
// For example:
// Given the below binary tree,
// 
//        1
//       / \
//      2   3
// Return 6.


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
	int maxPathSum(TreeNode *root)
	{
		int result = INT_MIN;
		maxPathSumInner(root, result);
		return result;
	}
	int maxPathSumInner(TreeNode *root, int &maxSum) {
		if (!root) return 0;
		int leftMax = maxPathSumInner(root->left, maxSum);
		int rightMax = maxPathSumInner(root->right, maxSum);
		maxSum = max(leftMax + rightMax + root->val, maxSum);
		int result = max(root->val, root->val + max(leftMax, rightMax));
		maxSum = max(maxSum, result);
		return result;
	}
};