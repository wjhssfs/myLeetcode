// 235 Lowest Common Ancestor of a Binary Search Tree

// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

//         _______6______
//        /              \
//     ___2__          ___8__
//    /      \        /      \
//    0      _4       7       9
//          /  \
//          3   5
// For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        vector<TreeNode *> pPath, tempp, qPath, tempq;
        if (findNode(root, p, tempp, pPath) && findNode(root, q, tempq, qPath)){
            TreeNode* result = pPath[0];
            for (int i = 0; i < pPath.size() && i < qPath.size() && pPath[i] == qPath[i]; i++){
                result = pPath[i];
            }
            return result;
        }
        else
        {
            return nullptr;
        }
    }

    bool findNode(TreeNode *root, TreeNode *p, vector<TreeNode*> &temp, vector<TreeNode*> &path){
        if (!root) return false;
        bool result = false;
        temp.push_back(root);
        if (root == p) {
            path = temp;
            result = true;
        }
        else
        {
           result = findNode(root->left, p, temp, path) ||
                findNode(root->right, p, temp, path);
        }
        temp.pop_back();
        return result;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(!root) return nullptr;
       if(root == p || root == q) return root;
       auto leftResult = lowestCommonAncestor(root->left, p, q);
       auto rightResult = lowestCommonAncestor(root->right, p, q);
       if(leftResult && rightResult) return root;
       return leftResult ? leftResult : rightResult;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) return nullptr;
        if(root == p || root == q) return root;
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root; // diverge
    }
};