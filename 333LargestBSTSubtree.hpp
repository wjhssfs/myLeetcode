// 333. Largest BST Subtree

// Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

// Note:
// A subtree must include all of its descendants.
// Here's an example:
//     10
//     / \
//    5  15
//   / \   \ 
//  1   8   7
// The Largest BST Subtree in this case is the highlighted one. 
// The return value is the subtree's size, which is 3.
// Hint:

// You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
// Follow up:
// Can you figure out ways to solve it with O(n) time complexity?

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
    int largestBSTSubtree(TreeNode* root) {
        int maxBST = 0, subMin = INT_MAX, subMax = INT_MIN;
        nSubtreeBST(root, subMin, subMax, maxBST);
        return maxBST;
    }
    
private:
    int nSubtreeBST(TreeNode *root, int &subMin, int &subMax, int &maxBST)
    {
        if(!root) {
            return 0;
        }
        int leftSubMin = INT_MAX, leftSubMax = INT_MIN;
        int nLeftSubBST = nSubtreeBST(root->left, leftSubMin, leftSubMax, maxBST);
        int rightSubMin = INT_MAX, rightSubMax = INT_MIN;
        int nRightSubBST = nSubtreeBST(root->right, rightSubMin, rightSubMax, maxBST);
        if(nLeftSubBST == -1 || nRightSubBST == -1 || leftSubMax >= root->val || rightSubMin <= root->val)
            return -1;
        subMin = min(leftSubMin, root->val); subMax = max(rightSubMax, root->val);
        int curN =  1 + nLeftSubBST + nRightSubBST;
        maxBST = max(maxBST, curN);
        return curN;
    }
};