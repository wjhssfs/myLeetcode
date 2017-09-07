// 663. Equal Tree Partition

// Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

// Example 1:
// Input:     
//     5
//    / \
//   10 10
//     /  \
//    2   3

// Output: True
// Explanation: 
//     5
//    / 
//   10
      
// Sum: 15

//    10
//   /  \
//  2    3

// Sum: 15
// Example 2:
// Input:     
//     1
//    / \
//   2  10
//     /  \
//    2   20

// Output: False
// Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
// Note:
// The range of tree node value is in the range of [-100000, 100000].
// 1 <= n <= 10000

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
    int getSum(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
    
    bool findSum(TreeNode* root, int sum, int &subSum) {
        if (!root) {
            subSum = 0;
            return false;
        }
        int leftSum = 0, rightSum = 0;
        if (findSum(root->left, sum, leftSum)) return true;
        if (root->left && leftSum == sum) return true;
        if (findSum(root->right, sum, rightSum)) return true;
        if (root->right && rightSum == sum) return true;
        subSum = root->val + leftSum + rightSum;
        return false;
    }
    
public:
    bool checkEqualTree(TreeNode* root) {
        int sum = getSum(root);
        if (sum % 2 != 0) return false;
        int rootSum = 0;
        return findSum(root, sum / 2, rootSum);
    }
};

 bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> map;
        int sum = getsum(root, map);
        if(sum == 0)return map[sum] > 1;
        return sum%2 == 0 && map.count(sum/2);
    }
    
    int getsum(TreeNode* root,  unordered_map<int, int>& map){
        if(root == NULL)return 0;
        int cur = root->val + getsum(root->left, map) + getsum(root->right, map);
        map[cur]++;
        return cur;
    }