// 257 Binary Tree Paths

// Given a binary tree, return all root-to-leaf paths.

// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]


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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return result;
        buildTreePaths(root, "");
        return result;
    }
    
    void buildTreePaths(TreeNode *root, string curPath) {
        curPath += "->" + to_string(root->val);
        if(!root->left && !root->right){
            result.push_back(curPath.substr(2));
            return;
        }
        if(root->left) buildTreePaths(root->left, curPath);
        if(root->right) buildTreePaths(root->right, curPath);
    }
    
    vector<string> result;
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        string rootVStr = to_string(root->val);
        if (!root->left && !root->right) {
            return {rootVStr};
        }
        for (auto &&result : binaryTreePaths(root->left)) {
            res.push_back(rootVStr + "->" + result);
        }
        for (auto &&result : binaryTreePaths(root->right)) {
            res.push_back(rootVStr + "->" + result);
        }
        return res;
    }
};

// https://leetcode.com/problems/binary-tree-paths/discuss/68272/Python-solutions-(dfs+stack-bfs+queue-dfs-recursively).
// return shortest path first
# bfs + queue
def binaryTreePaths2(self, root):
    if not root:
        return []
    res, queue = [], collections.deque([(root, "")])
    while queue:
        node, ls = queue.popleft()
        if not node.left and not node.right:
            res.append(ls+str(node.val))
        if node.left:
            queue.append((node.left, ls+str(node.val)+"->"))
        if node.right:
            queue.append((node.right, ls+str(node.val)+"->"))
    return res
