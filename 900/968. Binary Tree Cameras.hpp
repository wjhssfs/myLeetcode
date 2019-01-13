// 968. Binary Tree Cameras
// Given a binary tree, we install cameras on the nodes of the tree. 

// Each camera at a node can monitor its parent, itself, and its immediate children.

// Calculate the minimum number of cameras needed to monitor all nodes of the tree.

 

// Example 1:


// Input: [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.
// Example 2:


// Input: [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

// Note:

// The number of nodes in the given tree will be in the range [1, 1000].
// Every node has value 0.


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
	// p: parent has camera, y: current node has camera, n: neither parent or current node has camera
    struct Result {int p, y, n;};
    Result dfs(TreeNode* root) {
        if (!root) return {0, 0, 0};
        Result res {0, 1, 1};
        if (!root->left && !root->right) return res;
        auto resL = dfs(root->left);
        auto resR = dfs(root->right);
        res.y = 1 + resL.p + resR.p;
        res.n = min(resL.y == 0 ? INT_MAX : resL.y + min(resR.y, resR.n), resR.y == 0 ? INT_MAX : resR.y + min(resL.y, resL.n));
        res.p = min(res.y, min(resL.y, resL.n) + min(resR.y, resR.n));
        // cout << root->val << " " << res.p << " " << res.y << " " << res.n<< endl;
        return res;
    }
public:
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        auto r = dfs(root);
        return min(r.y, r.n);
    }
};