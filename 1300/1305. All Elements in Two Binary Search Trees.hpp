// 1305. All Elements in Two Binary Search Trees

// Given two binary search trees root1 and root2.

// Return a list containing all the integers from both trees sorted in ascending order.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1, s2;
        auto pushLeft = [](stack<TreeNode*> &s, TreeNode* n) { while (n) s.push(exchange(n, n->left)); };
        pushLeft(s1, root1); pushLeft(s2, root2);
        while (!s1.empty() || !s2.empty()) {
            auto&& s = s1.empty() ? s2 : s2.empty() ? s1 : s1.top()->val < s2.top()->val ? s1 : s2;
            auto n = s.top(); s.pop();
            res.push_back(n->val);
            pushLeft(s, n->right);
        }
        return res;
    }
};