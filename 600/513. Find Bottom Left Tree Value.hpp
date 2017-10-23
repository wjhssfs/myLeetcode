// 513. Find Bottom Left Tree Value

// Given a binary tree, find the leftmost value in the last row of the tree.

// Example 1:
// Input:

//     2
//    / \
//   1   3

// Output:
// 1
// Example 2: 
// Input:

//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7

// Output:
// 7
// Note: You may assume the tree (i.e., the given root node) is not NULL.

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
    int findBottomLeftValue(TreeNode* root) {
        maxD = -1, res = -1;
        dfs(root, 0);
        return res;
    }
private:
    void dfs(TreeNode* root, int d) {
        if (!root) return;
        if (d > maxD) {
            res = root->val;
            maxD = d;
        }
        dfs(root->left, d+1);
        dfs(root->right, d+1);
    }
    int maxD, res;
};


// Doing BFS right-to-left means we can simply return the last node's value and don't have to keep track of the first node in the current row or even care about rows at all.
public int findLeftMostNode(TreeNode root) {
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root);
    while (!queue.isEmpty()) {
        root = queue.poll();
        if (root.right != null)
            queue.add(root.right);
        if (root.left != null)
            queue.add(root.left);
    }
    return root.val;
}