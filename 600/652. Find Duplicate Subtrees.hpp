// 652. Find Duplicate Subtrees

// Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

// Two trees are duplicate if they have the same structure with same node values.

// Example 1: 
//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
// The following are two duplicate subtrees:
//       2
//      /
//     4
// and
//     4
// Therefore, you need to return above trees' root in the form of a list.

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> m;
        dfs(root, m);
        vector<TreeNode*> result;
        for (auto&& r : m) {
            if (r.second.size() < 2) continue;
            if (r.first == "n") continue;
            result.push_back(r.second.front());
        }
        return result;
    }
    
    string dfs(TreeNode* root, unordered_map<string, vector<TreeNode*>> &m) {
        if (!root) return "n";
        string left = dfs(root->left, m);
        string right = dfs(root->right, m);
        string result = to_string(root->val) + "," + left + "," + right;
        m[result].push_back(root);
        return result;
    }
};