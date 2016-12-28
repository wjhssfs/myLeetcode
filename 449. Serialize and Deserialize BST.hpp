// 449. Serialize and Deserialize BST
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

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
        stack<TreeNode *> s;
        string result;
        auto cur = root;
        while(cur || s.size()) {
            if (cur) {
                result += to_string(cur->val) + ",";
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top()->right;
                s.pop();
            }
        }
        if (result.size()) result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<int> inOrder, preOrder;
        stringstream ss(data);
        string num;
        while(getline(ss, num, ',')) preOrder.push_back(stoi(num));
        inOrder = preOrder;
        sort(inOrder.begin(), inOrder.end());
        return constructTree(preOrder, 0, preOrder.size(), inOrder, 0, inOrder.size());
    }
private:
    TreeNode* constructTree(vector<int> &preOrder, int pStart, int pEnd, vector<int>& inOrder, int iStart, int iEnd) {
        if (pStart == pEnd) return nullptr;
        TreeNode* root = new TreeNode(preOrder[pStart]);
        int i = iStart;
        while(inOrder[i] != root->val) ++i;
        auto left = constructTree(preOrder, pStart + 1, pStart + 1 + i - iStart, inOrder, iStart, i - 1);
        auto right = constructTree(preOrder, pStart + 1 + i - iStart , pEnd, inOrder, i+1, iEnd);
        root->left = left;
        root->right = right;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// https://discuss.leetcode.com/topic/66495/using-lower-bound-and-upper-bound-to-deserialize-bst
 // Encodes a tree to a single string.
    void serialize(TreeNode* root, ostringstream& out )
    {
        if ( !root ) return;
        out << root->val << ",";
        serialize(root->left, out);
        serialize(root->right, out);
    }
    
    string serialize(TreeNode* root) {
        ostringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    TreeNode* deserialize(const string& s, int lower, int upper, int & pos )
    {
        // pos is a variable to record the end of decoded buffer 
        if ( pos == s.size() ) return nullptr;
        int cur_pos = pos;
        int number = 0;
        while( s[cur_pos] != ',')
        {
            number = number * 10 + s[cur_pos] - '0';
            ++cur_pos;
        }
        ++cur_pos;
        // The next number is not part of current subtree, should return nullptr
        if ( number < lower || number > upper ) return nullptr;

        TreeNode* root = new TreeNode( number );
        pos = cur_pos; // update pos 
        root->left =  deserialize( s, lower, root->val, pos );
        root->right = deserialize( s, root->val, upper, pos );
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserialize( data, INT_MIN, INT_MAX, pos );
        
    }