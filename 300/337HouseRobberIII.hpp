// 337. House Robber III
// The thief has found himself a new place for his thievery again. There is only one entrance to this area,
// called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart
// thief realized that "all houses in this place forms a binary tree". It will automatically contact the police
// if two directly-linked houses were broken into on the same night.
// Determine the maximum amount of money the thief can rob tonight without alerting the police.
// Example 1:
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:
//      3 
//     / \
//    4   5
//   / \   \ 
//  1   3   1
// Maximum amount of money the thief can rob = 4 + 5 = 9.

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
    int rob(TreeNode* root) {
        int doRob = 0, dontRob = 0;
        rob(root, doRob, dontRob);
        return max(doRob, dontRob);
    }

    void rob(TreeNode *root, int &doRob, int &dontRob) {
        if(!root) {
            doRob = dontRob = 0;
            return;
        }
        int lDoRob = 0, lDontRob = 0, rDoRob = 0, rDontRob = 0;
        rob(root->left, lDoRob, lDontRob);
        rob(root->right, rDoRob, rDontRob);
        doRob = root->val + lDontRob + rDontRob;
        dontRob = max(lDoRob, lDontRob) + max(rDoRob, rDontRob);
    }
};

// slow recursive
public int rob(TreeNode root) {
    if (root == null) {
        return 0;
    }

    int val = 0;

    if (root.left != null) {
        val += rob(root.left.left) + rob(root.left.right);
    }

    if (root.right != null) {
        val += rob(root.right.left) + rob(root.right.right);
    }

    return Math.max(val + root.val, rob(root.left) + rob(root.right));
}