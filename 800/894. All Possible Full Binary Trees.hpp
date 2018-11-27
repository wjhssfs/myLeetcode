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


// https://leetcode.com/problems/all-possible-full-binary-trees/discuss/167402/c++-recursive-and-iterative-solutions.-Doesn't-create-Frankenstein-trees-or-leak-memory
    TreeNode* clone(TreeNode* root) {
      TreeNode* new_root = new TreeNode(0);
      new_root->left = (root->left) ? clone(root->left) : nullptr;
      new_root->right = (root->right) ? clone(root->right) : nullptr; 
      return new_root;
    } 

    vector<TreeNode*> allPossibleFBT(int N) {
      std::vector<TreeNode*> ret;
      if (1 == N) {
        ret.emplace_back(new TreeNode(0));
      } else if (N % 2) {
        for (int i = 2; i <= N; i += 2) {
          auto left = allPossibleFBT(i - 1);
          auto right = allPossibleFBT(N - i);
          for (int l_idx = 0; l_idx < left.size(); ++l_idx) {
            for (int r_idx = 0; r_idx < right.size(); ++r_idx) {
              ret.emplace_back(new TreeNode(0));
              
              // If we're using the last right branch, then this will be the last time this left branch is used and can hence
              // be shallow copied, otherwise the tree will have to be cloned
              ret.back()->left = (r_idx == right.size() - 1) ? left[l_idx] : clone(left[l_idx]);
              
              // If we're using the last left branch, then this will be the last time this right branch is uesd and can hence
              // be shallow copied, otherwise the tree will have to be cloned
              ret.back()->right = (l_idx == left.size() - 1) ? right[r_idx] : clone(right[r_idx]);
            }
          }
        }
      }
      return ret;
    }