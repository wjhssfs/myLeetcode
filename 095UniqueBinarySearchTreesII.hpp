// 95 Unique Binary Search Trees II 
// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

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
	vector<TreeNode *> generateTrees(int n) {
		return generateNode(1, n+1);
	}
	vector<TreeNode *> generateNode(int start, int end){
		vector<TreeNode *> results;
		for (int i = start; i != end; i++){
			vector<TreeNode *> resultsL = generateNode(start, i);
			vector<TreeNode *> resultsR = generateNode(i + 1, end);
			if (!resultsL.empty() && !resultsR.empty()){
				for (int j = 0; j != resultsL.size(); j++){
					for (int k = 0; k != resultsR.size(); k++){
						TreeNode *node = new TreeNode(i);
						node->left = resultsL[j];
						node->right = resultsR[k];
						results.push_back(node);
					}
				}

			}
		}
		if (!results.size()) results.push_back(nullptr);
		return results;
	}
};

class Solution2 {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees_1(n);
    }

    // solution 1
    vector<TreeNode *> generateTrees_1(int n) {
        return generateTreesRe(1, n);
    }

    vector<TreeNode*> generateTreesRe(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            res.push_back(NULL);
            return res;
        }
        for (int k = l; k <= r; k++) {
            vector<TreeNode*> leftTrees = generateTreesRe(l, k-1);
            vector<TreeNode*> rightTrees = generateTreesRe(k+1, r);
            for (size_t i = 0; i < leftTrees.size(); i++) {
                for (size_t j = 0; j < rightTrees.size(); j++) {
                    TreeNode* root = new TreeNode(k);
                    root->left = leftTrees[i];
                    root->right = rightTrees[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    // solution 2
    vector<TreeNode *> generateTrees_2(int n) {
        vector<TreeNode *> dp[n+1];
        dp[0] = vector<TreeNode *>(1, (TreeNode *)NULL);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                for (int m = 0; m < dp[j-1].size(); ++m)
                {
                    for (int k = 0; k < dp[i-j].size(); ++k)
                    {
                        TreeNode *root = new TreeNode(j);
                        CopyTree(dp[j-1][m], root->left, 0);
                        CopyTree(dp[i-j][k], root->right, j);
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

    void CopyTree(TreeNode *original, TreeNode *&newNode, int diff)
    {
        if (!original) return;
        newNode = new TreeNode(original->val + diff);
        CopyTree(original->left, newNode->left, diff);
        CopyTree(original->right, newNode->right, diff);
    }
};
