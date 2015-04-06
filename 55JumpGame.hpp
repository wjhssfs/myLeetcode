// 55 Jump Game 
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// 
// Each element in the array represents your maximum jump length at that position.
// 
// Determine if you are able to reach the last index.
// 
// For example:
// A = [2,3,1,1,4], return true.
// 
// A = [3,2,1,0,4], return false.


class Solution {
public:
	bool canJump(int A[], int n) {
		int maxR = 0;
		for (size_t i = 0; i != n && maxR < n-1; i++){
			if (i > maxR) return false;
			else maxR = max(maxR, ((int)i) + A[i]);
		}
		return true;
	}
};