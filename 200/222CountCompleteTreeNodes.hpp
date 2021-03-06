// 222 Count Complete Tree Nodes
// Given a complete binary tree, count the number of nodes.
// Definition of a complete binary tree from Wikipedia:
// https://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = 0, rightHeight = 0;
        auto running = root->left;
        while(running){running = running->left; ++leftHeight;}
        running = root->right;
        while(running){running = running->right; ++rightHeight;}
        if(leftHeight && leftHeight == rightHeight){
            //if pow(2,hl) is changed to be (1<<hl), the run time would decline from 360ms to 170 ms approximately.
            return pow(2, leftHeight + 1) - 1; 
        }
        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        return leftCount + rightCount + 1;
    }
};

int getLeftHeight(TreeNode* root) {
    int height = 0;
    while(root) { 
        root = root->left;
        height++;
    }
    return height;
}

int countNodes(TreeNode* root) {
    if(!root) return 0;

    int left_height = getLeftHeight(root->left);
    int right_height = getLeftHeight(root->right);

    if(left_height == right_height) 
        return pow(2, left_height) + countNodes(root->right);

    return pow(2, right_height) + countNodes(root->left);
}

// ==============================================
// calculate height of right tree, if the same as height, go to right tree(append 1 to binary result), otherwise go to left tree (Append 0 to binary result)
int countNodes(TreeNode* root)
{
    int result,height,RTreeHeight;
    TreeNode* visit,*p;

    if (root==NULL) return 0;

    p = visit = root;
    height = 0;
    for(;p;p = p -> left) height++;
    result = 1;

    while(--height)
    {
        // at the end of current loop, this will become 2^heigh
        result <<= 1;

        RTreeHeight = 0;
        p = visit->right;
        for(;p;p = p -> left) RTreeHeight++;
        if (RTreeHeight < height) visit = visit->left;
        else
        {
            result |= 1;
            visit = visit->right;
        }
    }
    return result;
} 

class Solution {
    int height(TreeNode root) {
        return root == null ? -1 : 1 + height(root.left);
    }
    public int countNodes(TreeNode root) {
        int h = height(root);
        return h < 0 ? 0 :
               height(root.right) == h-1 ? (1 << h) + countNodes(root.right)
                                         : (1 << h-1) + countNodes(root.left);
    }
}