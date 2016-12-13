// 437. Path Sum III
// You are given a binary tree in which each node contains an integer value.
// Find the number of paths that sum to a given value.
// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
// Example:
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1
// Return 3. The paths that sum to 8 are:
// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11
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
    int pathSum(TreeNode* root, int sum) {
        vector<int> m;
        total = 0;
        this->sum = sum;
        dfs(root, m);
        return total;
    }
private:
    void dfs(TreeNode* root, vector<int> &m) {
        if (!root) return;
        for (auto && n : m) {
            n += root->val;
            if (n == sum) ++total;
        }
        m.push_back(root->val);
        if (root->val == sum) ++total;
        dfs(root->left, m);
        dfs(root->right, m);
        for (auto && n : m) {
            n -= root->val;
        }
        m.pop_back();
    }
    int total, sum;
};