// 231 Power of Two 
// Given an integer, write a function to determine if it is a power of two.

class Solution {
public:
    bool isPowerOfTwo(int n) {
    	// INT_MIN for (100...00)2
        if(!n || n == INT_MIN) return false; 
        return !(n & (n -1));
    }
};