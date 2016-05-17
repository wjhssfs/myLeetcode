// 103 Binary Tree Zigzag Level Order Traversal 
// Given a binary tree, return the zigzag level order traversal of its nodes' values.
// (ie, from left to right, then right to left for the next level and alternate between). 
// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > result;
		list<TreeNode *> lst1, lst2;
		if (!root) return result;
		lst2.push_back(root);
		bool reverse = true;
		while (!lst2.empty()){
			vector<int> subResult;
			reverse = !reverse;
			swap(lst1, lst2);//lst1 is current level, lst2 is next level

			for (auto n : lst1){
				if (n->left) lst2.push_back(n->left);
				if (n->right) lst2.push_back(n->right);
			}
			if (reverse){
				for (auto rIt = lst1.rbegin(); rIt != lst1.rend(); rIt++){
					subResult.push_back((*rIt)->val);
				}
			}
			else{
				for (auto it = lst1.begin(); it != lst1.end(); it++){
					subResult.push_back((*it)->val);
				}
			}
			lst1.clear();
			result.push_back(subResult);
		}
		return result;
	}
};