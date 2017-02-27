// 501. Find Mode in Binary Search Tree

// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
// For example:
// Given BST [1,null,2,2],
//    1
//     \
//      2
//     /
//    2
// return [2].

// Note: If a tree has more than one mode, you can return them in any order.

// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).


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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int maxCount = 0;
        dfs(root, maxCount, res);
        return res;
    }
private:
    int countRoot(TreeNode* root, int val) {
           if (!root) return 0;
           int t = 0;
           if (root->val == val) ++t;
           if (root->val >= val) t += countRoot(root->left, val);
           if (root->val <= val) t += countRoot(root->right, val);
           return t;
    }
    void dfs(TreeNode* root, int& maxCount, vector<int> &res) {
        if (!root) return;
        int rootCount = countRoot(root, root->val);
        if (rootCount > maxCount) {
            maxCount = rootCount;
            res.clear();
            res.push_back(root->val);
        } else if (rootCount == maxCount) {
            res.push_back(root->val);
        }
        dfs(root->left, maxCount, res);
        dfs(root->right, maxCount, res);
    }
};

// Two pass
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        res.clear();
        maxCount = -1, mode = 0, count = 0;
        inorder(root);
        mode = 1, count = 0;
        inorder(root);
        return res;
    }
private:
    void process(int val) {
        if (maxCount == -1 || val != preVal) {
            count = 0;
        }
        ++count;
        preVal = val;
        if (mode == 0) {
            maxCount = max(maxCount, count);
        } else if (count == maxCount) res.push_back(val);
    }
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        process(root->val);
        inorder(root->right);
    }
    int maxCount, mode, preVal, count;
    vector<int> res;
};

// OnePass
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        res.clear();
        maxCount = -1, count = 0;
        inorder(root);
        return res;
    }
private:
    void process(int val) {
        if (maxCount == -1 || val != preVal) {
            count = 0;
        }
        ++count;
        preVal = val;
        if (count > maxCount) {
            res = {val};
            maxCount = count;
        } else if (count == maxCount) res.push_back(val);
    }
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        process(root->val);
        inorder(root->right);
    }
    int maxCount, preVal, count;
    vector<int> res;
};