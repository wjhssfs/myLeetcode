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
		bool done = false;
		TreeNode *current = root;
		while (!done)
		{
			if (current){
				s.push(current);
				current = current->left;
			}
			else{
				if (s.empty()){
					done = true;
				}
				else{
					current = s.top();
					s.pop();
					result.push_back(current->val);
					current = current->right;
				}
			}
		}
		return result;
	}
};

class Solution2 {
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

class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        return inorderTraversal_1(root);
    }
    
    vector<int> inorderTraversal_1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            if (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else if (!stk.empty())
            {
                res.push_back(stk.top()->val);
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return res;
    }
    
    vector<int> inorderTraversal_2(TreeNode *root) {
        vector<int> res;
        inorderTraversalRe(root, res);
        return res;
    }

    void inorderTraversalRe(TreeNode *node, vector<int> &res) {
        if (!node) return;
        inorderTraversalRe(node->left, res);
        res.push_back(node->val);
        inorderTraversalRe(node->right, res);
    }
    
    vector<int> inorderTraversal_3(TreeNode *root) {
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
