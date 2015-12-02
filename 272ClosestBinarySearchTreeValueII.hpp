// 272 Closest Binary Search Tree Value II

// Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

// Note:
// Given target value is a floating point.
// You may assume k is always valid, that is: k ≤ total nodes.
// You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
// Follow up:
// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

// Hint:

// Consider implement these two helper functions:
// getPredecessor(N), which returns the next smaller node to N.
// getSuccessor(N), which returns the next larger node to N.
// Try to assume that each node has a parent pointer, it makes the problem much easier.
// Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
// You would need two stacks to track the path in finding predecessor and successor node separately.

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> result;
        int closestVal = findClosest(root, target);
        result.push_back(closestVal);
        --k;
        stack<TreeNode *> forward, backward;
        TreeNode *prev = buildStacks(root, closestVal, forward, backward);
        TreeNode *next = prev;
        prev = getPrev(backward, prev);
        next = getNext(forward, next);
        
        while(k--)
        {
            if(prev && next){
                int prevVal = prev->val, nextVal = next->val;
                double prevDiff = prev->val - target, nextDiff = next->val - target;
                if(prevDiff < 0) prevDiff = -prevDiff;
                if(nextDiff < 0) nextDiff = -nextDiff;
                
                if(prevDiff < nextDiff){
                    result.push_back(prevVal);
                    prev = getPrev(backward, prev);
                }
                else{
                    result.push_back(nextVal);
                    next = getNext(forward, next);
                }
            }
            else if(prev){
                int prevVal = prev->val;
                result.push_back(prevVal);
                prev = getPrev(backward, prev);
            }
            else {
                int nextVal = next->val;
                result.push_back(nextVal);
                next = getNext(forward, next);
            }
        }
        return result;
    }
    
private:
    int findClosest(TreeNode *root, double target){
        if(!root) return target;
        double minDiff = root->val - target;
        int closest = root->val;
        if(minDiff < 0) minDiff = -minDiff;
        while(root && root->val != target){
            double curDiff = root->val - target;
            if(curDiff < 0) curDiff = -curDiff;
            if(curDiff < minDiff){
                minDiff = curDiff;
                closest = root->val;
            }
            if(root->val > target) root = root -> left;
            else root = root -> right;
        }
        if(root && root->val == target) closest = target;
        return closest;
    }
    
    TreeNode *buildStacks(TreeNode *root, int target, stack<TreeNode *> &f, stack<TreeNode *> &b){
        while(root->val != target){
            f.push(root); b.push(root);
            if(root->val < target) {
                f.pop();
                root = root->right;
            }
            else {
                b.pop();
                root = root->left;
            }
        }
        return root;
    }
    
    TreeNode *getNext(stack<TreeNode *> &s, TreeNode *cur){
        if(!cur->right){
            if(s.empty()) return nullptr;
            cur = s.top();
            s.pop();
        }
        else {
            cur = cur->right;
            while(cur->left){
                s.push(cur);
                cur = cur->left;
            }
        }
        return cur;
    }
    
    TreeNode *getPrev(stack<TreeNode *> &s, TreeNode *cur){
        if(!cur->left){
            if(s.empty()) return nullptr;
            cur = s.top();
            s.pop();
        }
        else {
            cur = cur->left;
            while(cur->right){
                s.push(cur);
                cur = cur->right;
            }
        }
        return cur;
    }
};