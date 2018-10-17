// 919. Complete Binary Tree Inserter

// A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

// Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

// CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
// CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
// CBTInserter.get_root() will return the head node of the tree.
 

// Example 1:

// Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
// Output: [null,1,[1,2]]
// Example 2:

// Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
// Output: [null,3,4,[1,2,3,4,5,6,7,8]]
 

// Note:

// The initial given tree is complete and contains between 1 and 1000 nodes.
// CBTInserter.insert is called at most 10000 times per test case.
// Every value of a given or inserted node is between 0 and 5000.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
    vector<TreeNode*> parents, children;
    TreeNode* root;
public:
    CBTInserter(TreeNode* root_) : root(root_) {
        parents.push_back(root);
        if (root->left)children.push_back(root->left);
        if (root->right)children.push_back(root->right);
        while (children.size() == parents.size() * 2) {
            swap(parents, children);
            children.clear();
            for (auto p : parents) {
                if (p->left)children.push_back(p->left);
                if (p->right)children.push_back(p->right);
            }
        }
    }
    
    int insert(int v) {
        children.push_back(new TreeNode(v));
        auto p = parents[(children.size() - 1) / 2];
        p->left ? p->right = children.back() : p->left = children.back();
        if (children.size() == parents.size() * 2) {
            swap(parents, children);
            children.clear();
        }
        return p->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};


    vector<TreeNode*> tree;
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for(int i = 0; i < tree.size();++i) {
            if (tree[i]->left) tree.push_back(tree[i]->left);
            if (tree[i]->right) tree.push_back(tree[i]->right);
        }
    }

    int insert(int v) {
        int N = tree.size();
        TreeNode* node = new TreeNode(v);
        tree.push_back(node);
        if (N % 2)
            tree[(N - 1) / 2]->left = node;
        else
            tree[(N - 1) / 2]->right = node;
        return tree[(N - 1) / 2]->val;
    }

    TreeNode* get_root() {
        return tree[0];
    }
/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */