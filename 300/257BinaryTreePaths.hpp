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

public List<String> binaryTreePaths(TreeNode root) {

        List<String> paths = new LinkedList<>();

        if(root == null) return paths;

        if(root.left == null && root.right == null){
            paths.add(root.val+"");
            return paths;
        }

         for (String path : binaryTreePaths(root.left)) {
             paths.add(root.val + "->" + path);
         }

         for (String path : binaryTreePaths(root.right)) {
             paths.add(root.val + "->" + path);
         }

         return paths;

    }