// 255 Verify Preorder Sequence in Binary Search Tree
// Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
// You may assume each number in the sequence is unique.
// Follow up:
// Could you do it using only constant space complexity?

// https://leetcode.com/discuss/51543/java-o-n-and-o-1-extra-space
// Kinda simulate the traversal, keeping a stack of nodes (just their values) of which we're still in the left subtree.
// If the next number is smaller than the last stack value, then we're still in the left subtree of all stack nodes,
// so just push the new one onto the stack. But before that, pop all smaller ancestor values, as we must now be in their
// right subtrees (or even further, in the right subtree of an ancestor). Also, use the popped values as a lower bound,
// since being in their right subtree means we must never come across a smaller number anymore.
class Solution {
public:
	bool verifyPreorder(vector<int>& preorder) {
		int leftBound = INT_MIN;
		stack<int> s;
		for(int p : preorder){
		    if(p < leftBound) return false;
		    while(!s.empty() && p > s.top()){
		        leftBound = s.top();
		        s.pop();
		    }
		    s.push(p);
		}
		return true;
	}
};

// Resuing parameter
class Solution {
public:
	bool verifyPreorder(vector<int>& preorder) {
		int leftBound = INT_MIN, i = -1;
		for(int p : preorder){
		    if(p < leftBound) return false;
		    while(i >= 0 && p > preorder[i]){
		        leftBound = preorder[i--];
		    }
		    preorder[++i] = p;
		}
		return true;
	}
};
