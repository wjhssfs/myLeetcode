// 145 Binary Tree Postorder Traversal 
// Given a binary tree, return the postorder traversal of its nodes' values.
// 
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode *root) {
    	TreeNode *cur = root, *last = nullptr;
    	vector<int> res;
    	stack<TreeNode *> s;
    	while(cur || !s.empty())
    	{
    		if(cur)
    		{
    			s.push(cur);
    			cur = cur->left;
    		}
    		else
    		{
    			TreeNode *peek = s.top();
    			if(peek->right && last != peek->right)
    			{	
    			    cur = peek->right;
    			}
    			else 
    			{
    				res.push_back(peek->val);
    				s.pop();
    				last = peek;	
    		    }
    		}
	    }
	    return res;
    }
};