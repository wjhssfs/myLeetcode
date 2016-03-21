// 272 Closest Binary Search Tree Value II

 

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

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode *> fPath, bPath;
        vector<int> result;
        result.push_back(closestValue(root, target, fPath));
        bPath = fPath;
        TreeNode *next = getNext(fPath, false), *pre = getNext(bPath, true);
        while(--k > 0) {
            if(!pre || (next && abs(next->val, target) <= abs(pre->val, target){
                result.push_back(next->val);
                next = getNext(fPath, false);
            } else {
                result.push_back(pre->val);
                pre = getNext(bPath, true);
            }
        }
        return result;
    }
    
    int closestValue(TreeNode* root, double target, stack<TreeNode*> &path) {
        int a = root->val;
        path.push(root);
        auto kid = target < a ? root->left : root->right;
        if (!kid) return a;
        int b = closestValue(kid, target);
        if (abs(a - target) < abs(b - target))
        {
            while(path.top()!=root) path.pop();
            return a;
        } else return b;
    }

    TreeNode *getNext(stack<TreeNode *> &s, bool reverse){
        if(s.empty()) return nullptr;
        TreeNode *cur = s.top();
        auto forward = [](TreeNode * n){ return reverse ? n->left : n->right;};
        auto backward = [](TreeNode * n){ return reverse ? n->right : n->left;};
        if(forward(cur)) {
            s.push(forward(cur));
            cur = forward(cur);
            while(backward(cur)){
                s.push(backward(cur));
                cur = backward(cur);
            }
            return cur;
        } else if (s.size()){
            s.pop();
            while(s.size() && forward(s.top()) == cur){
                cur = s.top(); s.pop();
            }
            return getNext(s);
        } else return nullptr;
    }
};

// O(n). do a single inorder traversal, and maintain a window size K.

/// https://leetcode.com/discuss/55682/o-logn-java-solution-with-two-stacks-following-hint
public class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> ret = new LinkedList<>();
        Stack<TreeNode> succ = new Stack<>();
        Stack<TreeNode> pred = new Stack<>();
        initializePredecessorStack(root, target, pred);
        initializeSuccessorStack(root, target, succ);
        if(!succ.isEmpty() && !pred.isEmpty() && succ.peek().val == pred.peek().val) {
            getNextPredecessor(pred);
        }
        while(k-- > 0) {
            if(succ.isEmpty()) {
                ret.add(getNextPredecessor(pred));
            } else if(pred.isEmpty()) {
                ret.add(getNextSuccessor(succ));
            } else {
                double succ_diff = Math.abs((double)succ.peek().val - target);
                double pred_diff = Math.abs((double)pred.peek().val - target);
                if(succ_diff < pred_diff) {
                    ret.add(getNextSuccessor(succ));
                } else {
                    ret.add(getNextPredecessor(pred));
                }
            }
        }
        return ret;
    }

    private void initializeSuccessorStack(TreeNode root, double target, Stack<TreeNode> succ) {
        while(root != null) {
            if(root.val == target) {
                succ.push(root);
                break;
            } else if(root.val > target) {
                succ.push(root);
                root = root.left;
            } else {
                root = root.right;
            }
        }
    }

    private void initializePredecessorStack(TreeNode root, double target, Stack<TreeNode> pred) {
        while(root != null){
            if(root.val == target){
                pred.push(root);
                break;
            } else if(root.val < target){
                pred.push(root);
                root = root.right;
            } else{
                root = root.left;
            }
        }
    }

    private int getNextSuccessor(Stack<TreeNode> succ) {
        TreeNode curr = succ.pop();
        int ret = curr.val;
        curr = curr.right;
        while(curr != null) {
            succ.push(curr);
            curr = curr.left;
        }
        return ret;
    }

    private int getNextPredecessor(Stack<TreeNode> pred) {
        TreeNode curr = pred.pop();
        int ret = curr.val;
        curr = curr.left;
        while(curr != null) {
            pred.push(curr);
            curr = curr.right;
        }
        return ret;
    }
}