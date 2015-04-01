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
        vector<int> result;
        if (!root) return result;
        stack<TreeNode *> s;
        set<TreeNode *> visited;
        s.push(root);
        while (!s.empty())
        {
            TreeNode * cur = s.top();
            if(cur->right && visited.end() == visited.find(cur->right)) s.push(cur->right);
            if(cur->left && visited.end() == visited.find(cur->left)) s.push(cur->left);
            if(
                (!cur->right || visited.end() != visited.find(cur->right))
                &&
                (!cur->left || visited.end() != visited.find(cur->left))
            ){
            s.pop();
            result.push_back(cur->val);
            visited.insert(cur);
            }
        }
        return result;
    }
};

class Solution2 {
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