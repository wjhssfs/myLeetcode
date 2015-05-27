// 172 Factorial Trailing Zeroes 
// Given an integer n, return the number of trailing zeroes in n!.
// Note: Your solution should be in logarithmic time complexity.

class Solution {
public:
	// number of n(5^1) + n(5^2) + f(5^3)+...
    int trailingZeroes(int n) {
        int r = 0;
        while(n/5){
            r += n/5;
            n = n/5;
        }
        return r;
    }
};