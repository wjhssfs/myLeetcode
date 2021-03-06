// 114 Flatten Binary Tree to Linked List 
// Given a binary tree, flatten it to a linked list in-place.
// For example,
// Given
// 
//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
// 
// Hints:
// If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
    void flatten(TreeNode *root) {
        TreeNode *pre = nullptr;
        flattenInner(root, pre);
    }

    void flattenInner(TreeNode *root, TreeNode *&pre)
    {
        if (!root) return;
        TreeNode *right = root->right;
        if (pre)
        {
            pre->left = nullptr;
            pre->right = root;
        }
        pre = root;
        flattenInner(root->left, pre);
        flattenInner(right, pre);
    }
};

class Solution2 {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        flatten(root->right);
        if (root->left)
        {
            flatten(root->left);
            TreeNode *cur = root->left;
            while (cur->right) cur = cur->right;
            cur->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode*now = root;
        while (now)
        {
            if(now->left)
            {
                //Find current node's prenode that links to current node's right subtree
                TreeNode* pre = now->left;
                while(pre->right)
                {
                    pre = pre->right;
                }
                pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right 
                //subtree is already linked by current node's prenode
                now->right = now->left;
                now->left = NULL;
            }
            now = now->right;
        }
    }
};

 public void flatten(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> stk = new Stack<TreeNode>();
        stk.push(root);
        while (!stk.isEmpty()){
            TreeNode curr = stk.pop();
            if (curr.right!=null)  
                 stk.push(curr.right);
            if (curr.left!=null)  
                 stk.push(curr.left);
            if (!stk.isEmpty()) 
                 curr.right = stk.peek();
            curr.left = null;  // dont forget this!! 
        }
    }