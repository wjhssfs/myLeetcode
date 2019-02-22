// 993. Cousins in Binary Tree
// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

// Return true if and only if the nodes corresponding to the values x and y are cousins.

 

// Example 1:


// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
// Example 2:


// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
// Example 3:



// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false
 

// Note:

// The number of nodes in the tree will be between 2 and 100.
// Each node has a unique integer value from 1 to 100.



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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        bool hasX = false, hasY = false;
        while(q.size()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto f = q.front(); q.pop();
                if (f->left && f->left->val == x && f->right && f->right->val == y) return false;
                if (f->left && f->left->val == y && f->right && f->right->val == x) return false;
                if (f->left && f->left->val == x || f->right && f->right->val == x) hasX = true;
                if (f->left && f->left->val == y || f->right && f->right->val == y) hasY = true;
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            if (hasX && hasY) return true;
            if (hasX || hasY) return false;
        }
        return false;
    }
};

bool isCousins(TreeNode* root, int x, int y, bool siblings = false, bool cousin = false) {
  queue<TreeNode*> q, q1;
  q.push(root);
  while (!q.empty() && !cousin) {
    while (!q.empty()) {
      auto n = q.front();
      q.pop();
      if (n == nullptr) siblings = false;
      else {
        if (n->val == x || n->val == y) {
          if (!cousin) cousin = siblings = true;
          else return !siblings;
        }
        // insert nullptr into q1 after inserting each node's children (to separate siblings froum cousins).
        q1.push(n->left), q1.push(n->right), q1.push(nullptr);
      }
    }
    swap(q, q1);
  }
  return false;
}