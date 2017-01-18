// 314 Binary Tree Vertical Order Traversal

// Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

// If two nodes are in the same row and column, the order should be from left to right.

// Examples:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its vertical order traversal as:
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]
// Given binary tree [3,9,20,4,5,2,7],
//     _3_
//    /   \
//   9    20
//  / \   / \
// 4   5 2   7
// return its vertical order traversal as:
// [
//   [4],
//   [9],
//   [3,5,2],
//   [20],
//   [7]
// ]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 vector<vector<int>> verticalOrder(TreeNode* root) {
    map<int, vector<int>> cols;
    queue<pair<TreeNode*, int>> q;
    if (root)
        q.emplace(root, 0);
    while (q.size()) {
        auto node = q.front().first;
        int x = q.front().second;
        q.pop();
        cols[x].push_back(node->val);
        if (node->left)
            q.emplace(node->left, x-1);
        if (node->right)
            q.emplace(node->right, x+1);
    }
    vector<vector<int>> result;
    for (auto col : cols)
        result.push_back(col.second);
    return result;
}

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<map<int,vector<int>>>left, right;
        voHelper(root, left, right, 0, 0);
        vector<vector<int>> combined;
        for(int i = (int)left.size() - 1; i >=0; i--){
            combined.push_back({});
            for(auto &&heightArray :left[i]){
                for(auto &&val : heightArray.second){
                    combined.back().push_back(val);
                }
            }
        }
        for(int i = 0; i < right.size(); i++){
            combined.push_back({});
            for(auto &&heightArray :right[i]){
                for(auto &&val : heightArray.second){
                    combined.back().push_back(val);
                }
            }
        }
        return combined;
    }
    void voHelper(TreeNode*root, vector<map<int,vector<int>>> &left, vector<map<int,vector<int>>> &right, int index, int height){
        if(!root) return;
        if(index >= 0){
            if(index+1 > right.size()) right.push_back({});
            right[index][height].push_back(root->val);
        }else {
            if(-index > left.size()) left.push_back({});
            left[-index-1][height].push_back(root->val);
        }
        voHelper(root->left, left, right, index-1, height+1);
        voHelper(root->right, left, right, index+1, height+1);
    }
};


class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        int minIndex = 0, maxIndex = 0;
        voHelper(root, m, 0, minIndex, maxIndex);
        if(!root) return {};
        vector<vector<int>> result(maxIndex-minIndex+1);
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int curIndex = m[cur] - minIndex;
            result[curIndex].push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return result;
    }
    void voHelper(TreeNode*root, unordered_map<TreeNode *, int> &m, int index, int& minIndex, int& maxIndex){
        if(!root) return;
        m[root] = index;
        minIndex = min(minIndex, index); maxIndex = max(maxIndex, index);
        voHelper(root->left, m, index-1, minIndex, maxIndex);
        voHelper(root->right, m, index+1, minIndex, maxIndex);
    }
};