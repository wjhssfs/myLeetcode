// 366. Find Leaves of Binary Tree

// Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

// Example:
// Given binary tree 
//           1
//          / \
//         2   3
//        / \     
//       4   5    
// Returns [4, 5, 3], [2], [1].

// Explanation:
// 1. Removing the leaves [4, 5, 3] would result in this tree:

//           1
//          / 
//         2          
// 2. Now removing the leaf [2] would result in this tree:

//           1          
// 3. Now removing the leaf [1] would result in the empty tree:

//           []         
// Returns [4, 5, 3], [2], [1].

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
    int postOrder(TreeNode* root, vector<vector<int>> & results) {
       if (!root) return 0;
       int levelLeft = postOrder(root->left, results);
       int levelRight = postOrder(root->right, results);
       int level = max(levelLeft, levelRight) + 1;
       results.resize(max(results.size(), (size_t)level));
       results[level-1].push_back(root->val);
       return level;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> results;
        postOrder(root, results);
        return results;
    }
};