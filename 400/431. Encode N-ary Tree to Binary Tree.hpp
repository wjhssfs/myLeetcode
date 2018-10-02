// 431. Encode N-ary Tree to Binary Tree

// Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get the original N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. Similarly, a binary tree is a rooted tree in which each node has no more than 2 children. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be decoded to the original N-nary tree structure.

// For example, you may encode the following 3-ary tree to a binary tree in this way:

// Note that the above is just an example which might or might not work. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.


// Note:

// N is in the range of [1, 1000]
// Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
 

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

  // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        //left child: child chain, right child: lower siblings
        if (root==NULL) return NULL;
        TreeNode *ret=new TreeNode(root->val);
        if (root->children.size()==0) return ret;
        ret->left=encode(root->children[0]);
        TreeNode *now=ret->left;
        for (int i=1;i<root->children.size();++i){
            now->right=encode(root->children[i]);
            now=now->right;
        }
        return ret;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (root==NULL) return NULL;
        Node* ret=new Node;
        ret->val=root->val;
        TreeNode *now=root->left;
        while (now){
            ret->children.push_back(decode(now));
            now=now->right;
        }
        return ret;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));