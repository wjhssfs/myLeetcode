// 105 Construct Binary Tree from Preorder and Inorder Traversal
// 
// Given preorder and inorder traversal of a tree, construct the binary tree.
// 
// Note:
// You may assume that duplicates do not exist in the tree.


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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTreeInner(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}
	TreeNode *buildTreeInner(vector<int> &preorder, int preorderStart, int preorderEnd,
		vector<int>&inorder, int inorderStart, int inorderEnd) {
		if (inorderStart >= inorderEnd) return nullptr;
		int rootVal = preorder[preorderStart];
		int nLeft = 0;
		while (inorder[inorderStart + nLeft] != rootVal) ++nLeft;

		TreeNode *rootNode = new TreeNode(rootVal);
		TreeNode *leftNode = buildTreeInner(preorder, preorderStart+1, preorderStart + nLeft +1, inorder, inorderStart, inorderStart + nLeft);
		TreeNode *rightNode = buildTreeInner(preorder, preorderStart + nLeft + 1, preorderEnd, inorder, inorderStart + nLeft + 1, inorderEnd);
		rootNode->left = leftNode;
		rootNode->right = rightNode;
		return rootNode;
	}
};
