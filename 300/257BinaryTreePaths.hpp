// 257 Binary Tree Paths

// Given a binary tree, return all root-to-leaf paths.

// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]


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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return result;
        buildTreePaths(root, "");
        return result;
    }
    
    void buildTreePaths(TreeNode *root, string curPath) {
        curPath += "->" + to_string(root->val);
        if(!root->left && !root->right){
            result.push_back(curPath.substr(2));
            return;
        }
        if(root->left) buildTreePaths(root->left, curPath);
        if(root->right) buildTreePaths(root->right, curPath);
    }
    
    vector<string> result;
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        string rootVStr = to_string(root->val);
        if (!root->left && !root->right) {
            return {rootVStr};
        }
        for (auto &&result : binaryTreePaths(root->left)) {
            res.push_back(rootVStr + "->" + result);
        }
        for (auto &&result : binaryTreePaths(root->right)) {
            res.push_back(rootVStr + "->" + result);
        }
        return res;
    }
};