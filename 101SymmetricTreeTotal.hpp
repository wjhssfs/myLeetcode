// 101 Symmetric Tree Total
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// 
// For example, this binary tree is symmetric:
// 
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if (!root) return true;
		stack<TreeNode*> st1;
		stack<TreeNode*> st2;
		st1.push(root->left); st2.push(root->right);
		while (!st1.empty()){
			if (st2.empty()) return false;
			TreeNode *st1Top = st1.top();
			TreeNode *st2Top = st2.top();
			st1.pop(); st2.pop();
			if (!st1Top && !st2Top) continue;
			if (st1Top && st2Top){
				if (st1Top->val != st2Top->val) return false;
				st1.push(st1Top->left); st1.push(st1Top->right);
				st2.push(st2Top->right); st2.push(st2Top->left);
				continue;
			}
			return false;
		}
		return st2.empty();
	}
};

class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {
        return isSymmetric_1(root);
    }
    
    bool isSymmetric_1(TreeNode *root) {
        if (!root) return true;
        return isSymmetricRe(root->left, root->right);
    }

    bool isSymmetricRe(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && !t2) return true;
        if (!t1 || !t2 || t1->val != t2->val) return false;
        return isSymmetricRe(t1->left, t2->right) &&
               isSymmetricRe(t1->right, t2->left);
    }

    bool isSymmetric_2(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            TreeNode *t1 = q.front(); q.pop();
            TreeNode *t2 = q.front(); q.pop();
            if (!t1 && !t2) continue;
            if (!t1 || !t2 || t1->val != t2->val)
                return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};
