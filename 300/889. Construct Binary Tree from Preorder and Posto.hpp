// 889. Construct Binary Tree from Preorder and Postorder Traversal

// Return any binary tree that matches the given preorder and postorder traversals.

// Values in the traversals pre and post are distinct positive integers.

 

// Example 1:

// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
 

// Note:

// 1 <= pre.length == post.length <= 30
// pre[] and post[] are both permutations of 1, 2, ..., pre.length.
// It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161268/C++JavaPython-One-Pass-Real-O(N)
// preorder generate TreeNodes, push them to stack and postorder pop them out.
    TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) {
        vector<TreeNode*> s;
        s.push_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); ++i) {
            TreeNode* node = new TreeNode(pre[i]);
            while (s.back()->val == post[j])
                s.pop_back(), j++;
            if (s.back()->left == NULL) s.back()->left = node;
            else s.back()->right = node;
            s.push_back(node);
        }
        return s[0];
    }

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<int> m(post.size() + 1);
        for (int i = 0; i < post.size(); ++i) {
            m[post[i]] = i;
        }
        stack<TreeNode*> s;
        auto r = new TreeNode(pre[0]);
        s.push(r);
        for (int i = 1; i < pre.size(); ++i) {
            auto cur = new TreeNode(pre[i]);
            bool inserted = false;
            while (!inserted) {
                if (m[s.top()->val] > m[pre[i]]) {
                    if (!s.top()->left) s.top()->left = cur;
                    else s.top()->right = cur;
                    s.push(cur);
                    inserted = true;
                } else {
                    s.pop();
                }
            }
        }
        return r;
    }
};