// 298 Binary Tree Longest Consecutive Sequence
// Given a binary tree, find the length of the longest consecutive sequence path.

// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

// For example,
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
// Longest consecutive sequence path is 3-4-5, so return 3.
//    2
//     \
//      3
//     / 
//    2    
//   / 
//  1
// Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

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
    int longestConsecutive(TreeNode* root) {
        int maxLen = 0;
        longestConsecutive(root, maxLen);
        return maxLen;
    }
private:
    int longestConsecutive(TreeNode* root, int &maxLen) {
        if(!root) return 0;
        int curLen = 1;
        int leftLen = longestConsecutive(root->left, maxLen);
        int rightLen = longestConsecutive(root->right, maxLen);
        if(leftLen && (root->val == root->left->val-1) &&
           ((leftLen >= rightLen) ||  (root->val != root->right->val-1)))
       {
            curLen += leftLen;
        }
        else if(rightLen && (root->val == root->right->val-1)){
            curLen += rightLen;
        }
        maxLen = max(maxLen, curLen);
        return curLen;
    }
};