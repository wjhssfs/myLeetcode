// 958. Check Completeness of a Binary Tree
// Given a binary tree, determine if it is a complete binary tree.

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

// Example 1:



// Input: [1,2,3,4,5,6]
// Output: true
// Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
// Example 2:



// Input: [1,2,3,4,5,null,7]
// Output: false
// Explanation: The node with value 7 isn't as far left as possible.
 
// Note:

// The tree will have between 1 and 100 nodes.

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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        vector<TreeNode*> curLevel, nextLevel;
        curLevel.push_back(root);
        bool isEnd = false;
        while (curLevel.size()) {
            nextLevel.clear();
            for (int i = 0; i < curLevel.size(); ++i) {
                if (!curLevel[i]->left) isEnd = true;
                else if (!isEnd) nextLevel.push_back(curLevel[i]->left);
                else return false;
                if (!curLevel[i]->right) isEnd = true;
                else if (!isEnd) nextLevel.push_back(curLevel[i]->right);
                else return false;
            }
            swap(curLevel, nextLevel);
        }
        return true;
    }
};

// https://leetcode.com/articles/check-completeness-of-a-binary-tree/
class Solution {
    public boolean isCompleteTree(TreeNode root) {
        List<ANode> nodes = new ArrayList();
        nodes.add(new ANode(root, 1));
        int i = 0;
        while (i < nodes.size()) {
            ANode anode = nodes.get(i++);
            if (anode.node != null) {
                nodes.add(new ANode(anode.node.left, anode.code * 2));
                nodes.add(new ANode(anode.node.right, anode.code * 2 + 1));
            }
        }

        return nodes.get(i-1).code == nodes.size();
    }
}

class ANode {  // Annotated Node
    TreeNode node;
    int code;
    ANode(TreeNode node, int code) {
        this.node = node;
        this.code = code;
    }
}