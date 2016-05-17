// 107 Binary Tree Level Order Traversal II 
// Given a binary tree, return the bottom-up level order traversal of its nodes' values.
// (ie, from left to right, level by level from leaf to root). 
// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]
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
   	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > result;
		if (!root) return result;
		queue<TreeNode *> q1, q2;
		q2.push(root);
		while (!q2.empty()){
			swap(q1, q2);
			vector<int> subResult;
			while (!q1.empty())
			{
				TreeNode *cur = q1.front();
				subResult.push_back(cur->val);
				if (cur->left)q2.push(cur->left);
				if (cur->right)q2.push(cur->right);
				q1.pop();
			}
			result.insert(result.begin(), subResult);
		}
		return result;
	}
};