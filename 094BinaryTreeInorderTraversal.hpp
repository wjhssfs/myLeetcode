// 94 Binary Tree Inorder Traversal
// Given a binary tree, return the inorder traversal of its nodes' values.
// 
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].
// 
// Note: Recursive solution is trivial, could you do it iteratively?

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
vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		if (!root) return result;
		stack<TreeNode *> s;
		TreeNode *current = root;
		while (!s.empty() || current)
		{
			if (current){
				s.push(current);
				current = current->left;
			}
			else{
				current = s.top();
				s.pop();
				result.push_back(current->val);
				current = current->right;
			}
		}
		return result;
	}
};

class Solution2 {
public:    
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                    prev = prev->right;
                    
                if (prev->right == cur)
                {
                    res.push_back(cur->val);
                    cur = cur->right;
                    prev->right = NULL;
                }
                else
                {
                    prev->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
