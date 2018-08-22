// 429. N-ary Tree Level Order Traversal

// Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example, given a 3-ary tree:
 
// We should return its level order traversal:

// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]
 

// Note:

// The depth of the tree is at most 1000.
// The total number of nodes is at most 5000.

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
                vector<vector<int>> result;
        if (root == NULL) {
            return vector<vector<int>>{};
        }
            
        queue<Node*> q;
        q.push(root);
        
        while (q.size() > 0) {
            result.push_back(vector<int>(q.size()));
            for (int i = 0; i < result[result.size() - 1].size(); i++) {
                result[result.size() - 1][i] = q.front()->val;
                for (auto c : q.front()->children) {
                    q.push(c);
                }
                q.pop();
            }
        }
        
        return result;
    }
};