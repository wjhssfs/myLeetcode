// 863. All Nodes Distance K in Binary Tree

// We are given a binary tree (with root node root), a target node, and an integer value K.

// Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

// Output: [7,4,1]

// Explanation: 
// The nodes that are a distance 2 from the target node (with value 5)
// have values 7, 4, and 1.



// Note that the inputs "root" and "target" are actually TreeNodes.
// The descriptions of the inputs above are just serializations of these objects.
 

// Note:

// The given tree is non-empty.
// Each node in the tree has unique values 0 <= node.val <= 500.
// The target node is a node in the tree.
// 0 <= K <= 1000.

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
    int K;
    TreeNode* target;
    vector<int> res;
    int dfs(TreeNode* root, int down) {
        if (!root) return INT_MIN;
        if (!down) { res.push_back(root->val); return INT_MIN;}
        if (down > 0) {
            dfs(root->left, down - 1);
            dfs(root->right, down - 1);
            return INT_MIN;
        }
        if (root == target) {
            dfs(root->left, K - 1);
            dfs(root->right, K - 1);
            if (K == 0) res.push_back(root->val);
            return 0;
        }
        else {
            int l = dfs(root->left, down);
            int r = dfs(root->right, down);
            if (l == INT_MIN && r == INT_MIN) return INT_MIN;
            if (l != INT_MIN && K > l) dfs(root->right, K - l - 2);
            if (r != INT_MIN && K > r) dfs(root->left, K - r - 2);
            if (l == K - 1 || r == K - 1) res.push_back(root->val);
            return max(l, r) + 1;
        }
        return INT_MIN;
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target_, int K_) {
        target = target_;
        K = K_;
        dfs(root, -1);
        return res;
    }
};


// Using recursion to find all of the son=>parent pair into a map.
// Using dfs to find K distance node, visited nodes will be recorded.
class Solution {
public:
    vector<int> ans;   
    map<TreeNode*, TreeNode*> parent;  // son=>parent  
    set<TreeNode*> visit;    //record visied node
    
    void findParent(TreeNode* node){
        if(!node ) return;
        if( node->left ){
            parent[node->left] = node;
            findParent(node->left);
        }
        if( node->right){
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if( !root ) return {};
        
        findParent(root);
        dfs(target, K );
        return ans;
    }
    void dfs( TreeNode* node, int K){
        if( visit.find(node) != visit.end() )
            return;
        visit.insert(node);
        if( K == 0 ){
            ans.push_back(node->val);
            return;
        }
        if( node->left ){
            dfs(node->left, K-1);
        }
        if( node->right){
            dfs(node->right, K-1);
        }
        TreeNode* p = parent[node];
        if( p )
            dfs(p, K-1);
    }
};

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143752/JAVA-Graph-+-BFS