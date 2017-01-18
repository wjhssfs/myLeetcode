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

// https://leetcode.com/discuss/77805/java-5ms-short-code-with-explanations
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* candidate = NULL;
    while (root)
        root = (root->val > p->val) ? (candidate = root)->left : root->right;
    return candidate;
}

public TreeNode successor(TreeNode root, TreeNode p) {
  if (root == null)
    return null;

  if (root.val <= p.val) {
    return successor(root.right, p);
  } else {
    TreeNode left = successor(root.left, p);
    return (left != null) ? left : root;
  }
}

public TreeNode predecessor(TreeNode root, TreeNode p) {
  if (root == null)
    return null;

  if (root.val >= p.val) {
    return predecessor(root.left, p);
  } else {
    TreeNode right = predecessor(root.right, p);
    return (right != null) ? right : root;
  }
}


public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
    while (root != null && root.val <= p.val)
        root = root.right;
    if (root == null)
        return null;
    TreeNode left = inorderSuccessor(root.left, p);
    return (left != null && left.val > p.val) ? left : root;
}
public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
    while (root != null && root.val <= p.val)
        root = root.right;
    TreeNode left = root == null ? null : inorderSuccessor(root.left, p);
    return (left != null && left.val > p.val) ? left : root;
}