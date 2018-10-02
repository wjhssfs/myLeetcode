// 878. Nth Magical Number
// A positive integer is magical if it is divisible by either A or B.

// Return the N-th magical number.  Since the answer may be very large, return it modulo 10^9 + 7.

 

// Example 1:

// Input: N = 1, A = 2, B = 3
// Output: 2
// Example 2:

// Input: N = 4, A = 2, B = 3
// Output: 6
// Example 3:

// Input: N = 5, A = 2, B = 4
// Output: 10
// Example 4:

// Input: N = 3, A = 6, B = 4
// Output: 8
 

// Note:

// 1 <= N <= 10^9
// 2 <= A <= 40000
// 2 <= B <= 40000
// https://leetcode.com/problems/nth-magical-number/discuss/154613/C++JavaPython-Binary-Search
// Inclusion exclusion principle
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long l = min(A, B), h = max(A, B) * 1e9, mod = 1e9 + 7;
        int lcm = A * B / __gcd(A, B);
        while (l < h) {
            long m = (l + h)/2;
            if (m/A + m / B - m/lcm < N) l = m + 1;
            else h = m;
        }
        return l % mod;
    }
};