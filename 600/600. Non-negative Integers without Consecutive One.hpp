// 600. Non-negative Integers without Consecutive Ones
// Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.

// Example 1:
// Input: 5
// Output: 5
// Explanation: 
// Here are the non-negative integers <= 5 with their corresponding binary representations:
// 0 : 0
// 1 : 1
// 2 : 10
// 3 : 11
// 4 : 100
// 5 : 101
// Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
// Note: 1 <= n <= 10^9

class Solution {
public:
    int findIntegers(int num) {
        int m[32][2] = {1, 1};
        for (int i = 1; i < 32; ++i) {
            m[i][0] = m[i-1][0] + m[i-1][1];
            m[i][1] = m[i-1][0];
        }
        unsigned mask = 1UL << 30;
        int res = 0;
        for (int i = 1; i < 32; ++i) {
            if (num & mask) {
                res += m[31 - i][0];
                if (num & (mask << 1)) return res;
            }
            mask >>= 1;
        }

        // +1 for n
        return res + 1;
    }
};

// https://discuss.leetcode.com/topic/90639/c-non-dp-o-32-fibonacci-solution
// The solution is based on 2 facts:

// the number of length k string without consecutive 1 is Fibonacci sequence f(k);
// For example, if k = 5, the range is 00000-11111. We can consider it as two ranges, which are 00000-01111 and 10000-10111. Any number >= 11000 is not allowed due to consecutive 1. The first case is actually f(4), and the second case is f(3), so f(5)= f(4)+f(3).
// Scan the number from most significant digit, i.e. left to right, in binary format. If we find a '1' with k digits to the right, count increases by f(k) because we can put a '0' at this digit and any valid length k string behind; After that, we continue the loop to consider the remaining cases, i.e., we put a '1' at this digit. If consecutive 1s are found, we exit the loop and return the answer. By the end of the loop, we return count+1 to include the number n itself.
// For example, if n is 10010110,
// we find first '1' at 7 digits to the right, we add range 00000000-01111111, which is f(7);
// second '1' at 4 digits to the right, add range 10000000-10001111, f(4);
// third '1' at 2 digits to the right, add range 10010000-10010011, f(2);
// fourth '1' at 1 digits to the right, add range 10010100-10010101, f(1);
// Those ranges are continuous from 00000000 to 10010101. And any greater number <= n will have consecutive 1.

class Solution {
public:
    int findIntegers(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i-1]+f[i-2];
        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0) {
            if (num&(1<<k)) {
                ans += f[k];
                if (pre_bit) return ans;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            --k;
        }
        return ans+1;
    }
};

// // https://discuss.leetcode.com/topic/90571/java-solution-dp/2
// First, I know we need to do the subtraction only for the highest effective bit as the problem requires less than or equal to n.
// Second. I understand that when there are two consecutive ones, other integers will be less than it, stop!
// Third, if we met 01, according to the dp formula, the number of qualified integers for first 0 should be 00 and 01, both of them are less than or equal to 01. The same for 10.
// Finally, for 00, the number of qualified integers for first 0 should be 00 and 01, but 01 is greater than 00, we should subtract it.
public class Solution {
    public int findIntegers(int num) {
        StringBuilder sb = new StringBuilder(Integer.toBinaryString(num)).reverse();
        int n = sb.length();
        
        int a[] = new int[n];
        int b[] = new int[n];
        a[0] = b[0] = 1;
        for (int i = 1; i < n; i++) {
            a[i] = a[i - 1] + b[i - 1];
            b[i] = a[i - 1];
        }
        
        int result = a[n - 1] + b[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (sb.charAt(i) == '1' && sb.charAt(i + 1) == '1') break;
            // check for double 00 and remove those over-counted.
            if (sb.charAt(i) == '0' && sb.charAt(i + 1) == '0') result -= b[i];
        }
        
        return result;
    }
}