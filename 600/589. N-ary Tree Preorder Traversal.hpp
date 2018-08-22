// 589. N-ary Tree Preorder Traversal

// Given an n-ary tree, return the preorder traversal of its nodes' values.

// For example, given a 3-ary tree:
 
// Return its preorder traversal as: [1,3,5,6,2,4].

// Note: Recursive solution is trivial, could you do it iteratively?

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    void pre(Node* root, vector<int>& r) {
        if (!root) return;
        r.push_back(root->val);
        for (auto c : root->children) pre(c, r);
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> r;
        pre(root, r);
        return r;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> r;
        if (!root) return r;
        stack<pair<Node*, int>> s;
        s.push(make_pair(root, 0));
        r.push_back(root->val);
        while (s.size()) {
            auto curNode = s.top().first;
            auto& index = s.top().second;
            if (index < curNode->children.size()) {
                s.push(make_pair(curNode->children[index], 0));
                r.push_back(s.top().first->val);
                ++index;
            } else {
                s.pop();
            }
        }
        return r;
    }
};

class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> list = new ArrayList<>();
        if (root == null) return list;
        
        Stack<Node> stack = new Stack<>();
        stack.add(root);
        
        while (!stack.empty()) {
            root = stack.pop();
            list.add(root.val);
            for (int i = root.children.size() - 1; i >= 0; i--)
                stack.add(root.children.get(i));
        }
        
        return list;
    }
}