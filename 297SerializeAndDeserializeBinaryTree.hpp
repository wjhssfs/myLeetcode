// 297 Serialize and Deserialize Binary Tree

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// For example, you may serialize the following tree

//     1
//    / \
//   2   3
//      / \
//     4   5
// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        ss << "[";
        queue<TreeNode *> q;
        if(root) q.push(root);
        int nNull = 0;
        while(!q.empty() && nNull != q.size())
        {
            if(!q.front()) {
                ss << "null,";
                nNull--;
            } else {
                ss << q.front()->val << ",";
                if(!q.front()->left) nNull++;
                if(!q.front()->right) nNull++;
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
        ss << "]";
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1, data.size()-2);
        stringstream ss(data);
        string line;
        char delim = ',';
        if(!getline(ss, line, delim)) return nullptr;
        TreeNode *root = new TreeNode(stoi(line, nullptr, 10));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            if(!getline(ss, line, delim)) break;
            if(line != "null") { 
                TreeNode *leftNode = new TreeNode(stoi(line, nullptr, 10));
                q.front()->left = leftNode;
                q.push(leftNode);
            }
            if(!getline(ss, line, delim)) break;
            if(line != "null") {
                TreeNode *rightNode = new TreeNode(stoi(line, nullptr, 10));
                q.front()->right = rightNode;
                q.push(rightNode);
            }
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};