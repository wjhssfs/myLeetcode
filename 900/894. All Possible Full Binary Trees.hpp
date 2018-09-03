// 894. All Possible Full Binary Trees

// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

// Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

// Each node of each tree in the answer must have node.val = 0.

// You may return the final list of trees in any order.


// Example 1:

// Input: 7
// Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
// Explanation: 

// Note:

// 1 <= N <= 20

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
    unordered_map<int, vector<TreeNode*>> m;
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if (m.count(N)) return m[N];
        if (N == 1) {
            m[1] =  {new TreeNode(0)};
            return m[1];
        }
        vector<TreeNode*> r;
        for (int i = 1; i <= N - 2; ++i) {
            auto lefts = allPossibleFBT(i);
            auto rights = allPossibleFBT(N - 1 - i);
            for (auto left : lefts) for (auto right : rights) {
                auto root = new TreeNode(0);
                root->left = left;
                root->right = right;
                r.push_back(root);
            }
        }
        m[N] = r;
        return r;
    }
};