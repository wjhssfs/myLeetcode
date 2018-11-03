// 829. Consecutive Numbers Sum

// Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?

// Example 1:

// Input: 5
// Output: 2
// Explanation: 5 = 5 = 2 + 3
// Example 2:

// Input: 9
// Output: 3
// Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
// Example 3:

// Input: 15
// Output: 4
// Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
// Note: 1 <= N <= 10 ^ 9.

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int n = 1;
        int k;
        int r = 0;
        while ((k = 2 * N + n - n * n) > 0) {
            if (k % (2 * n) == 0) r++;
            ++n;
        }
        return r;
    }
};

// https://leetcode.com/problems/consecutive-numbers-sum/discuss/129015/5-lines-C++-solution-with-detailed-mathematical-explanation.
// x + (x+1) + (x+2)+...+ k terms = N
// kx + k*(k-1)/2 = N implies
// kx = N - k*(k-1)/2

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 1; // N sums to N
        for( int k = 2; k < sqrt( 2 * N ); k++ ) {
            if ( ( N - ( k * ( k - 1 )/2) ) % k == 0) count++;
        }
        return count;
    }
};

