// 476. Number Complement

// Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

// Note:
// The given integer is guaranteed to fit within the range of a 32-bit signed integer.
// You could assume no leading zero bit in the integer’s binary representation.
// Example 1:
// Input: 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:
// Input: 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

class Solution {
public:
    int findComplement(int num) {
        if (!num) return 1;
        num = ~num;
        unsigned mask = 1 << 31;
        while (num & mask) {
            num &= ~mask;
            mask >>= 1;
        }
        return num;
    }
};

class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};


    int findComplement(int num) {
        return ~num & ((1 <<(int)log2(num))-1);
    }
class Solution {
public:
    int findComplement(int num) {
        int mask=(1<<(int)(log2(num)+1))-1;
        return ~num&mask;
    }
};
// That extra plus 1 is not needed since we need to change the leading bit which is a 1 to a 0. But yes to get a mask of all 1's with the same width as the num then we need that extra plus 1.

// http://stackoverflow.com/questions/53161/find-the-highest-order-bit-in-c
int findComplement(int num) {
    int mask = num;
    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;
    return num ^ mask;
}