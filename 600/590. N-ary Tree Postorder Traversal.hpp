// 590. N-ary Tree Postorder Traversal

// Given an n-ary tree, return the postorder traversal of its nodes' values.
 
// For example, given a 3-ary tree:

// Return its postorder traversal as: [5,6,3,2,4,1].

 
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
public:
    vector<int> postorder(Node* root) {
        vector<int> r;
        if (!root) return r;
        stack<pair<Node*, int>> s;
        s.push(make_pair(root, 0));
        while (s.size()) {
            auto curNode = s.top().first;
            auto& index = s.top().second;
            if (index < curNode->children.size()) {
                s.push(make_pair(curNode->children[index], 0));
                ++index;
            } else {
                r.push_back(s.top().first->val);
                s.pop();
            }
        }
        return r;
    }
};

vector<int> postorder(Node* root) {
    if(root==NULL) return {};
    vector<int> res;
    stack<Node*> stk;
    stk.push(root);
    while(!stk.empty())
    {
        Node* temp=stk.top();
        stk.pop();
        for(int i=0;i<temp->children.size();i++) stk.push(temp->children[i]);
        res.push_back(temp->val);
    }
    reverse(res.begin(), res.end());
    return res;
}