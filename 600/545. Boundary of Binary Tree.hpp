// 545. Boundary of Binary Tree

// Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

// Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

// The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

// The right-most node is also defined by the same way with left and right exchanged.

// Example 1
// Input:
//   1
//    \
//     2
//    / \
//   3   4

// Ouput:
// [1, 3, 4, 2]

// Explanation:
// The root doesn't have left subtree, so the root itself is left boundary.
// The leaves are node 3 and 4.
// The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
// So order them in anti-clockwise without duplicates and we have [1,3,4,2].
// Example 2
// Input:
//     ____1_____
//    /          \
//   2            3
//  / \          / 
// 4   5        6   
//    / \      / \
//   7   8    9  10  
       
// Ouput:
// [1,2,4,7,8,9,10,6,3]

// Explanation:
// The left boundary are node 1,2,4. (4 is the left-most node according to definition)
// The leaves are node 4,7,8,9,10.
// The right boundary are node 1,3,6,10. (10 is the right-most node).
// So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].

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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        res.push_back(root->val);
        if (root->left) addLeftBound(root->left, res);
        // instead of addLeaves(root, res), do below two to handle single level tree
        addLeaves(root->left, res);
        addLeaves(root->right, res);
        if (root->right) addRightBound(root->right, res);
        return res;
    }
private:
    void addLeftBound(TreeNode *root, vector<int> &res) {
        if (!root->left && !root->right) return; // not adding leave
        res.push_back(root->val);
        root->left ? addLeftBound(root->left, res) :  addLeftBound(root->right, res);
    }
    void addRightBound(TreeNode *root, vector<int> &res) {
        if (!root->left && !root->right) return;
        root->right ? addRightBound(root->right, res) : addRightBound(root->left, res); 
        res.push_back(root->val); // reverse order
    }
    void addLeaves(TreeNode* root, vector<int> &res) {
        if (!root) return;
        if (!root->left && !root->right) res.push_back(root->val);
        else {
            addLeaves(root->left, res);
            addLeaves(root->right, res);
        }
    }
};


// One pass
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> bounds;
        if (root) {
            bounds.push_back(root->val);
            getBounds(root->left, bounds, true, false);
            getBounds(root->right, bounds, false, true);
        }
        return bounds;
    }

private:
    void getBounds(TreeNode* node, vector<int>& res, bool lb, bool rb) {
        if (!node)  return;
        if (lb) res.push_back(node->val);
        if (!lb && !rb && !node->left && !node->right)  res.push_back(node->val);
        getBounds(node->left, res, lb, rb && !node->right);
        getBounds(node->right, res, lb && !node->left, rb);
        if (rb) res.push_back(node->val);
    }
};
