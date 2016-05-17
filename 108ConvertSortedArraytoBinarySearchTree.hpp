// 108 Convert Sorted Array to Binary Search Tree
// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		int n = num.size();
		if (n == 0) return NULL;
		int mid = n / 2;
		TreeNode *root = new TreeNode(num[mid]);
		vector<int> leftArray(num.begin(), num.begin() + mid);
		vector<int> rightArray(num.begin() + mid + 1, num.end());
		TreeNode *left = sortedArrayToBST(leftArray);
		TreeNode *right = sortedArrayToBST(rightArray);
		root->left = left;
		root->right = right;
		return root;
	}
};

public TreeNode sortedArrayToBST(int[] num) {
    if (num.length == 0) {
        return null;
    }
    TreeNode head = helper(num, 0, num.length - 1);
    return head;
}

public TreeNode helper(int[] num, int low, int high) {
    if (low > high) { // Done
        return null;
    }
    int mid = (low + high) / 2;
    TreeNode node = new TreeNode(num[mid]);
    node.left = helper(num, low, mid - 1);
    node.right = helper(num, mid + 1, high);
    return node;
}