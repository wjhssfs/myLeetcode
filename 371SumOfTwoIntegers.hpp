// 371. Sum of Two Integers
// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
// Example:
// Given a = 1 and b = 2, return 3.

class Solution {
public:
    int getSum(int a, int b) {
         int ret = 0;
         bool c = false;
         unsigned mask = 1;
         for (int i = 0; i < 32; ++i) {
             bool aBit = a & mask, bBit = b & mask;
             if ((aBit && !bBit && !c) ||
                 (!aBit && bBit && !c) ||
                 (!aBit && !bBit && c) ||
                 (aBit && bBit && c)) {
                     ret |= mask;
            }
            c = (aBit && bBit) || (aBit && c) || (bBit && c);
            mask <<= 1;
         }
         return ret;
    }
};

 public int getSum(int a, int b) {
     if(b == 0) return a;
    int sum,carry;
    sum = a^b;
    carry = (a&b)<<1;
    return getSum(sum,carry);
}
public int getSum(int a, int b) {
    return b == 0 ? a : getSum(a^b, (a&b)<<1);
}

// Iterative
public int getSum(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    
    return a;
}

public int getSubtract(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    
    return a;
}
public int getSubtract(int a, int b) {
    return (b == 0) ? a : getSubtract(a ^ b, (~a & b) << 1);
}

// Get negative number
public int negate(int x) {
    return ~x + 1;
}