// 105 Construct Binary Tree from Preorder and Inorder Traversal
// Given preorder and inorder traversal of a tree, construct the binary tree.
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


// 1) Keep pushing the nodes from the preorder into a stack (and keep making the
// tree by adding nodes to the left of the previous node) until the top of the stack matches the inorder.
// 2) At this point, pop the top of the stack until the top does not equal inorder
// (keep a flag to note that you have made a pop).
// 3) Repeat 1 and 2 until preorder is empty. The key point is that whenever the flag is set,
// insert a node to the right and reset the flag.
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size()==0)
            return NULL;

        stack<int> s;
        stack<TreeNode *> st;
        TreeNode *t,*r,*root;
        int i,j,f;

        f=i=j=0;
        s.push(preorder[i]);

        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root;
        i++;

        while(i<preorder.size())
        {
            if(!st.empty() && st.top()->val==inorder[j])
            {
                t = st.top();
                st.pop();
                s.pop();
                f = 1;
                j++;
            }
            else
            {
                if(f==0)
                {
                    s.push(preorder[i]);
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);
                    i++;
                }
                else 
                {
                    f = 0;
                    s.push(preorder[i]);
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }

        return root;
    }
};
