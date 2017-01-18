// 145 Binary Tree Postorder Traversal 
// Given a binary tree, return the postorder traversal of its nodes' values.
// 
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode *root) {
    	TreeNode *cur = root, *last = nullptr;
    	vector<int> res;
    	stack<TreeNode *> s;
    	while(cur || !s.empty())
    	{
    		if(cur)
    		{
    			s.push(cur);
    			cur = cur->left;
    		}
    		else
    		{
    			TreeNode *peek = s.top();
    			if(peek->right && last != peek->right)
    			{	
    			    cur = peek->right;
    			}
    			else 
    			{
    				res.push_back(peek->val);
    				s.pop();
    				last = peek;	
    		    }
    		}
	    }
	    return res;
    }
};

// pre-order traversal is root-left-right, and post order is left-right-root. modify the code for
// pre-order to make it root-right-left, and then reverse the output so that we can get left-right-root .
// Create an empty stack, Push root node to the stack.
// Do following while stack is not empty.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodeStack;
        vector<int> result;
        //base case
        if(root==NULL)
        return result;
        nodeStack.push(root);
        while(!nodeStack.empty())
        {
            TreeNode* node= nodeStack.top();  
            result.push_back(node->val);
            nodeStack.pop();
            if(node->left)
            nodeStack.push(node->left);
            if(node->right)
            nodeStack.push(node->right);
        }
         reverse(result.begin(),result.end());
         return result;
     }
};

// https://leetcode.com/discuss/9736/accepted-code-with-explaination-does-anyone-have-better-idea
void preorder_traversal_iteratively(TreeNode* root)
{
    if (root == 0)
        return;
    stack<TreeNode*> s;
    s.push(root);
    cout << root->val << ' '; // visit root
    TreeNode* last_pop = root;
    while (!s.empty())
    {
        TreeNode* top = s.top();
        if (top->left != 0 && top->left != last_pop && top->right != last_pop) // push_left
        {
            s.push(top->left);
            cout << top->left->val << ' '; // visit top->left
        }
        else if (top->right != 0 && top->right != last_pop && (top->left == 0 || top->left == last_pop)) // push_right
        {
            s.push(top->right);
            cout << top->right->val << ' '; // visit top->right
        }
        else // pop
        {
            s.pop();
            last_pop = top;
        }
    }
}

void inorder_traversal_iteratively(TreeNode* root)
{
    if (root == 0)
        return;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* last_pop = root;
    while (!s.empty())
    {
        TreeNode* top = s.top();
        if (top->left != 0 && top->left != last_pop && top->right != last_pop) // push_left
        {
            s.push(top->left);
        }
        else if (top->right != 0 && top->right != last_pop && (top->left == 0 || top->left == last_pop)) // push_right
        {
            s.push(top->right);
            cout << top->val << ' '; // visit top
        }
        else // pop
        {
            s.pop();
            last_pop = top;
            if (top->right == 0)
                cout << top->val << ' '; // visit top
        }
    }
}

void postorder_traversal_iteratively(TreeNode* root)
{
    if (root == 0)
        return;
    stack<TreeNode*> s;
    s.push(root);   
    TreeNode* last_pop = root;
    while (!s.empty())
    {       
        TreeNode* top = s.top();
        if (top->left != 0 && top->left != last_pop && top->right != last_pop) // push_left
        {
            s.push(top->left);
        }
        else if (top->right != 0 && top->right != last_pop && (top->left == 0 || top->left == last_pop)) // push_right
        {
            s.push(top->right);
        }
        else // pop
        {
            s.pop();
            last_pop = top;
            cout << top->val << ' '; // visit top
        }
    }
}

// https://leetcode.com/discuss/71943/preorder-inorder-and-postorder-iteratively-summarization
Pre Order Traverse
public List<Integer> preorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            result.add(p.val);  // Add before going to children
            p = p.left;
        } else {
            TreeNode node = stack.pop();
            p = node.right;   
        }
    }
    return result;
}

In Order Traverse
public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            p = p.left;
        } else {
            TreeNode node = stack.pop();
            result.add(node.val);  // Add after all left children
            p = node.right;   
        }
    }
    return result;
}

Post Order Traverse
public List<Integer> postorderTraversal(TreeNode root) {
    LinkedList<Integer> result = new LinkedList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            result.addFirst(p.val);  // Reverse the process of preorder
            p = p.right;             // Reverse the process of preorder
        } else {
            TreeNode node = stack.pop();
            p = node.left;           // Reverse the process of preorder
        }
    }
    return result;
}


// https://leetcode.com/discuss/36711/solutions-iterative-recursive-traversal-different-solutions
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> nodes;
    stack<TreeNode*> toVisit;
    TreeNode* curNode = root;
    TreeNode* lastNode = NULL;
    while (curNode || !toVisit.empty()) {
        if (curNode) {
            toVisit.push(curNode);
            curNode = curNode -> left;
        }
        else {
            TreeNode* topNode = toVisit.top();
            if (topNode -> right && lastNode != topNode -> right)
                curNode = topNode -> right;
            else {
                nodes.push_back(topNode -> val);
                lastNode = topNode;
                toVisit.pop();
            }
        }
    }
    return nodes;
}