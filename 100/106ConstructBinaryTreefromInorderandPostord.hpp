// 106 Construct Binary Tree from Inorder and Postorder Traversal 
// Given inorder and postorder traversal of a tree, construct the binary tree. 
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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTreeInner(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
	TreeNode *buildTreeInner(vector<int> &inorder, int inorderStart, int inorderEnd, 
		vector<int>&postorder, int postorderStart, int postorderEnd) {
		if (postorderStart >= postorderEnd) return nullptr;
		int rootVal = postorder[postorderEnd - 1];
		int nLeft = 0;
		while (inorder[inorderStart + nLeft] != rootVal) ++nLeft;

		TreeNode *rootNode = new TreeNode(rootVal);
		TreeNode *leftNode = buildTreeInner(inorder, inorderStart, inorderStart + nLeft, postorder, postorderStart, postorderStart +nLeft);
		TreeNode *rightNode = buildTreeInner(inorder, inorderStart + nLeft + 1, inorderEnd, postorder, postorderStart + nLeft, postorderEnd-1);
		rootNode->left = leftNode;
		rootNode->right = rightNode;
		return rootNode;
	}
};

// https://leetcode.com/discuss/15115/my-comprehension-of-o-n-solution-from-%40hongzhi
// Only nodes whoes left side hasn't been handled will be pushed into stn.
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;

        root = new TreeNode(postorder.back()); 
        stn.push(root); 
        postorder.pop_back(); 

        while(true)
        {
            if(inorder.back() == stn.top()->val) 
            {
                p = stn.top();
                stn.pop(); 
                inorder.pop_back(); 
                if(inorder.size() == 0) break;
                if(stn.size() && inorder.back() == stn.top()->val)
                    continue;
                p->left = new TreeNode(postorder.back()); 
                postorder.pop_back();
                stn.push(p->left);
            }
            else 
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p; 
                stn.push(p); 
            }
        }
        return root;
    }
};