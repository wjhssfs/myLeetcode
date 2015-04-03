// 117 Populating Next Right Pointers in Each Node II
// Follow up for problem "Populating Next Right Pointers in Each Node".
// 
// What if the given tree could be any binary tree? Would your previous solution still work?
// 
// Note:
// 
// You may only use constant extra space.
// For example,
// Given the following binary tree,
//          1
//        /  \
//       2    3
//      / \    \
//     4   5    7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \    \
//     4-> 5 -> 7 -> NULL

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
void connect(TreeLinkNode *root) {
		while (root){
			TreeLinkNode *curNode = root;
			while (curNode)
			{
				if (curNode->left) 
				    curNode->right? curNode->left->next = curNode->right:curNode->left->next = firstLeftChild(curNode->next);
				if (curNode->right) curNode->right->next = firstLeftChild(curNode->next);
				curNode = curNode->next;
			}
			root = firstLeftChild(root);
		}
	}

	TreeLinkNode* firstLeftChild(TreeLinkNode *root)
	{
		while (root && !root->left && !root->right){
			root = root->next;
		}
		if (!root) return root;
		return root->left ? root->left : root->right;
	}
};


class Solution2 {
public:
    void connect(TreeLinkNode *root) {
        connect_1(root);
    }
    
    // solution 1
    void connect_1(TreeLinkNode *root) {
        TreeLinkNode *cur = root;
        while (cur)
        {
            TreeLinkNode *node = cur, *last = NULL;
            cur = NULL;
            while (node)
            {
                TreeLinkNode *left = node->left, *right = node->right;
                if (left || right) {
                    if (last) last->next = left ? left : right;
                    if (left) left->next = right;
                    if (!cur) cur = left ? left : right;
                    last = right ? right : left;
                }
                node = node->next;
            }
        }
    }
    
    // solution 2
    void connect_2(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);
        TreeLinkNode *last = NULL;
        while (true)
        {
            TreeLinkNode *node = q.front();
            q.pop();
            if (!node) {
                last = NULL;
                if (q.empty()) break;
                q.push(NULL);
            } else {
                if (last) last->next = node;
                last = node;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
    
    // solution 3
    void connect_3(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *node = root;
        TreeLinkNode *last = NULL;
        TreeLinkNode *first = NULL;
        while (node)
        {
            if (node->left || node->right) {
                if (last) 
                    last->next = node->left ? node->left : node->right;
                if (node->left && node->right)
                    node->left->next = node->right;
                if (!first) 
                    first = node->left ? node->left : node->right;
                last = node->right ? node->right : node->left;
                
            }
            node = node->next;
        }
        connect_3(first);
    }
};
