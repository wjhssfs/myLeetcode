// 250 Count Univalue Subtrees

// Given a binary tree, count the number of uni-value subtrees.

// A Uni-value subtree means all nodes of the subtree have the same value.

// For example:
// Given binary tree,
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
// return 4.

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
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        total = 0;
        PostOrder(root);
        return total;
    }
    
private:
    bool PostOrder(TreeNode *root){
        if (!root) return true;
        bool leftIsUni = PostOrder(root->left);
        bool rightIsUni = PostOrder(root->right);
        if(leftIsUni && rightIsUni && 
            (!root->left || root->left->val == root->val) && 
            (!root->right || root->right->val == root->val)){
            ++total;
            return true;
        }
        return false;
    }
    int total;
};