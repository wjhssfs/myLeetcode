// 236 Lowest Common Ancestor of a Binary Tree 
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
// between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//         _______3______
//        /              \
//     ___5__          ___1__
//    /      \        /      \
//    6      _2       0       8
//          /  \
//          7   4
// For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, 
// since a node can be a descendant of itself according to the LCA definition.
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
       if(!root) return nullptr;
       if(root == p || root == q) return root;
       auto leftResult = lowestCommonAncestor(root->left, p, q);
       auto rightResult = lowestCommonAncestor(root->right, p, q);
       if(leftResult && rightResult) return root;
       return leftResult ? leftResult : rightResult;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}

// https://discuss.leetcode.com/topic/18652/iterative-solutions-in-python-c
class Solution {
    struct Frame {
        TreeNode* node;
        Frame* parent;
        vector<TreeNode*> subs;
    };
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Frame answer;
        stack<Frame> stack;
        stack.push({root, &answer});
        while (stack.size()) {
            Frame *top = &stack.top(), *parent = top->parent;
            TreeNode *node = top->node;
            if (!node || node == p || node == q) {
                parent->subs.push_back(node);
                stack.pop();
            } else if (top->subs.empty()) {
                stack.push({node->right, top});
                stack.push({node->left, top});
            } else {
                TreeNode *left = top->subs[0], *right = top->subs[1];
                parent->subs.push_back(!left ? right : !right ? left : node);
                stack.pop();
            }
        }
        return answer.subs[0];
    }
};