// 255 Verify Preorder Sequence in Binary Search Tree
// Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
// You may assume each number in the sequence is unique.
// Follow up:
// Could you do it using only constant space complexity?

// https://leetcode.com/discuss/51543/java-o-n-and-o-1-extra-space
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