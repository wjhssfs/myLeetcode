// 926. Flip String to Monotone Increasing
// A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

// We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

// Return the minimum number of flips to make S monotone increasing.

 

// Example 1:

// Input: "00110"
// Output: 1
// Explanation: We flip the last digit to get 00111.
// Example 2:

// Input: "010110"
// Output: 2
// Explanation: We flip to get 011111, or alternatively 000111.
// Example 3:

// Input: "00011000"
// Output: 2
// Explanation: We flip to get 00000000.
 

// Note:

// 1 <= S.length <= 20000
// S only consists of '0' and '1' characters.


class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int t0 = count(begin(S), end(S), '0');
        int minF = S.size(), c0 = 0;
        for (int i = 0; i <= S.size(); ++i) {
            int f1 = i - c0;
            int f0 = t0 - c0;
            minF = min(f1 + f0, minF);
            if (S[i] == '0') c0++;
        }
        return minF;
    }
};