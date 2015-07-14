// 230 Kth Smallest Element in a BST 

// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

// Hint:

// Try to utilize the property of a BST.
// What if you could modify the BST node's structure?
// The optimal runtime complexity is O(height of BST).

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
    int kthSmallest(TreeNode* root, int k) {
        int tempk = k, result = 0;
        kthSmallestHelper(root, tempk, result);
        return result;
    }
private:
    void kthSmallestHelper(TreeNode *root, int &k, int &result){
        if(root->left) kthSmallestHelper(root->left, k, result);
        --k;
        if(k==0) {
            result = root->val; 
            return;
        }
        if(root->right) kthSmallestHelper(root->right, k, result);
    }
};