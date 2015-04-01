// 144 Binary Tree Preorder Traversal 
// Given a binary tree, return the preorder traversal of its nodes' values.
// 
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode*> s;
		if (root) s.push(root);
		while (!s.empty())
		{
			TreeNode *cur = s.top();
			s.pop();
			result.push_back(cur->val);
			if (cur->right)s.push(cur->right);
			if (cur->left) s.push(cur->left);
		}
		return result;
	}
};