// 536. Construct Binary Tree from String

// You need to construct a binary tree from a string consisting of parenthesis and integers.

// The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

// You always start to construct the left child node of the parent first if it exists.

// Example:
// Input: "4(2(3)(1))(6(5))"
// Output: return the tree root node representing the following tree:

//        4
//      /   \
//     2     6
//    / \   / 
//   3   1 5   
// Note:
// There will only be '(', ')', '-' and '0' ~ '9' in the input string.
// An empty tree is represented by "" instead of "()".

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
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        stack<TreeNode*> st;
        int p = 0;
        st.push(new TreeNode(parseV(s, p)));
        while (p < s.size()) {
            if (s[p] == '(') {
                ++p;
                auto cur = new TreeNode(parseV(s, p));
                if (!st.top()->left) st.top()->left = cur;
                else st.top()->right = cur;
                st.push(cur);
            } else {
                assert(s[p] == ')');
                ++p;
                st.pop();
            }
        }
        
        return st.top();
    }
    
private:
    int parseV(const string &s, int &p) {
        int sign = 1, v = 0;
        if (s[p] == '-') {sign = -1; ++p;}
        while (p < s.size() && isdigit(s[p])) {
            v *= 10;
            v += s[p] - '0';
            ++p;
        }
        return v * sign;
    }
};

class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        s = "(" + s + ")";
        int p = 0;
        return parseSubTree(s, p);
    }
    
private:
    TreeNode* parseSubTree(string &s, int &p) {
        if (s[p] != '(') return nullptr;
        ++p;
        size_t n = 0;
        auto root = new TreeNode(stoi(s.substr(p), &n));
        p += n;
        root->left = parseSubTree(s, p);
        root->right = parseSubTree(s, p);
        ++p;
        return root;
    }
};

public TreeNode str2tree(String s) {
    if (s == null || s.length() == 0) return null;
    int firstParen = s.indexOf("(");
    int val = firstParen == -1 ? Integer.parseInt(s) : Integer.parseInt(s.substring(0, firstParen));
    TreeNode cur = new TreeNode(val);
    if (firstParen == -1) return cur;
    int start = firstParen, leftParenCount = 0;
    for (int i=start;i<s.length();i++) {
        if (s.charAt(i) == '(') leftParenCount++;
        else if (s.charAt(i) == ')') leftParenCount--;
        if (leftParenCount == 0 && start == firstParen) {cur.left = str2tree(s.substring(start+1,i)); start = i+1;}
        else if (leftParenCount == 0) cur.right = str2tree(s.substring(start+1,i));
    }
    return cur;
}

class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        auto firstParen = s.find('(');
        auto root = new TreeNode(stoi(s.substr(0, firstParen)));
        if (firstParen == string::npos) return root;
        for (size_t i = firstParen, openParent = 0; i < s.size(); ++i) {
            if (s[i] == '(') ++openParent;
            else if (s[i] == ')') --openParent;
            if (openParent == 0) {
                root->left = str2tree(s.substr(firstParen + 1, i - firstParen - 1));
                s.pop_back(); // get rid of trailing ')'
                root->right = str2tree(s.substr(min(s.size(), i + 2)));
                break;
            }
        }
        return root;
    }
};