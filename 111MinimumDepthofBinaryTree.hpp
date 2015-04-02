// 111 Minimum Depth of Binary Tree
// 
// Given a binary tree, find its minimum depth.
// 
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int depth = 1;
        if(root->left && !root->right)
            depth += minDepth(root->left);
        else if (!root->left && root->right)
            depth += minDepth(root->right);
        else if(root->left && root->right)
            depth += min(minDepth(root->left), minDepth(root->right));
        return depth;
    }
};

class Solution2 {
public:
    int minDepth(TreeNode *root) {
        return minDepth_1(root);
    }
    
    int minDepth_1(TreeNode *root) {
        if (!root)
            return 0;
        
        if (!root->left && !root->right)
            return 1;
        else if (!root->left)
            return 1 + minDepth_1(root->right);
        else if (!root->right)
            return 1 + minDepth_1(root->left);
        else
            return 1 + min(minDepth_1(root->left), minDepth_1(root->right));
    }
    
    int minDepth_2(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int depth = 1;
        while (true)
        {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                depth++;
                q.push(NULL);
            } else {
                if (!node->left && !node->right) return depth;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
};

