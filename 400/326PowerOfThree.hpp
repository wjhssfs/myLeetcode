// 326. Power of Three
// Given an integer, write a function to determine if it is a power of three.

// Follow up:
// Could you do it without using any loop / recursion?

class Solution {
public:
    bool isPowerOfThree(int n) {
    	if(n>1)
        	while(n%3 == 0) n = n / 3;
        return n == 1;
    }
};

// Find the maximum integer that is a power of 3 and check if it is a multiple of the given input. 
// public boolean isPowerOfThree(int n) {
//     int maxPowerOfThree = (int)Math.pow(3, (int)(Math.log(0x7fffffff) / Math.log(3)));
//     return n>0 && maxPowerOfThree%n==0;
// }

// public boolean isPowerOfThree(int n) {
//     return n==0 ? false : n==Math.pow(3, Math.round(Math.log(n) / Math.log(3)));
// }