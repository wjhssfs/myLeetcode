// 113 Path Sum II 
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
// 
// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        path.clear();  curSum = 0; targetSum = sum; result.clear();
        pathSumInner(root);
        return result;
    }

private:
    void pathSumInner(TreeNode *root)
    {
        if (!root) return;
        path.push_back(root->val);
        curSum += root->val;
        if (curSum == targetSum && !root->left && !root->right){
            result.push_back(path);
        }
        pathSumInner(root->left);
        pathSumInner(root->right);
        path.pop_back();
        curSum -= root->val;
    }

    vector<int> path;
    int curSum;
    vector<vector<int> > result;
    int targetSum;
};

class Solution2 {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        path.clear();  curSum = 0; targetSum = sum; result.clear();
        pathSumInner(root);
        return result;
    }

private:
    void pathSumInner(TreeNode *root)
    {
        if (!root) return;
        path.push_back(root->val);
        curSum += root->val;
        if (curSum == targetSum && !root->left && !root->right){
            result.push_back(path);
        }
        pathSumInner(root->left);
        pathSumInner(root->right);
        path.pop_back();
        curSum -= root->val;
    }

    vector<int> path;
    int curSum;
    vector<vector<int> > result;
    int targetSum;
};