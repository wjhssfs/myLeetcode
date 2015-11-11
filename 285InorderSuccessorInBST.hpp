// 285 Inorder Successor in BST

// Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

// Note: If the given node has no in-order successor in the tree, return null.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right) 
        {
            p = p->right;
            while(p->left) p = p->left;
            return p;
        }
        
        TreeNode* s = nullptr;
        while(root!=p){
            if(root->val < p->val) root = root->right;
            else {
                s = root;
                root = root->left;
            }
        }
        return s;
    }
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* candidate = NULL;
    while (root)
        root = (root->val > p->val) ? (candidate = root)->left : root->right;
    return candidate;
}