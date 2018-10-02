// 515. Find Largest Value in Each Tree Row

// You need to find the largest value in each row of a binary tree.

// Example:
// Input: 

//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 

// Output: [1, 3, 9]

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
    vector<int> largestValues(TreeNode* root) {
        res.clear();
        dfs(root, 0);
        return res;
    }
private:
    void dfs(TreeNode* root, int d) {
        if (!root) return;
        if (res.size() <= d) res.push_back(root->val);
        else res[d]= max(res[d], root->val);
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
    vector<int> res;
};

// BFS
public class Solution {
    public int findLeftMostNode(TreeNode root) {
        if (root == null) return 0;
        
        int result = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if (i == 0) result = node.val;
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
        }
        
        return result;
    }
}