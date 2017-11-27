// 371. Sum of Two Integers
// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
// Example:
// Given a = 1 and b = 2, return 3.

// https://discuss.leetcode.com/topic/50315/a-summary-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

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

Set union A | B
Set intersection A & B
Set subtraction A & ~B
Set negation ALL_BITS ^ A or ~A
Set bit A |= 1 << bit
Clear bit A &= ~(1 << bit)
Test bit (A & 1 << bit) != 0
Extract last bit A&-A or A&~(A-1) or x^(x&(x-1))
Remove last bit A&(A-1)
Get all 1-bits ~0

bool isPowerOfFour(int n) {
    return !(n&(n-1)) && (n&0x55555555);
    //check the 1-bit location;
}

// Find the largest power of 2 (most significant bit in binary form), which is less than or equal to the given number N.
long largest_power(long N) {
    //changing all right side bits to 1.
    N = N | (N>>1);
    N = N | (N>>2);
    N = N | (N>>4);
    N = N | (N>>8);
    N = N | (N>>16);
    return (N+1)>>1;
}

int rangeBitwiseAnd(int m, int n) {
    int a = 0;
    while(m != n) {
        m >>= 1;
        n >>= 1;
        a++;
    }
    return m<<a; 
}

// Given an array of integers, every element appears three times except for one. Find that single one
//inspired by logical circuit design and boolean algebra;
//counter - unit of 3;
//current   incoming  next
//a b            c    a b
//0 0            0    0 0
//0 1            0    0 1
//1 0            0    1 0
//0 0            1    0 1
//0 1            1    1 0
//1 0            1    0 0
//a = a&~b&~c + ~a&b&c;
//b = ~a&b&~c + ~a&~b&c;
//return a|b since the single number can appear once or twice;
int singleNumber(vector<int>& nums) {
    int t = 0, a = 0, b = 0;
    for(int i = 0; i < nums.size(); ++i) {
        t = (a&~b&~nums[i]) | (~a&b&nums[i]);
        b = (~a&b&~nums[i]) | (~a&~b&nums[i]);
        a = t;
    }
    return a | b;
}
;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> vv;
    int size = nums.size(); 
    if(size == 0) return vv;
    int num = 1 << size;
    vv.resize(num);
    for(int i = 0; i < num; ++i) {
        for(int j = 0; j < size; ++j)
            if((1<<j) & i) vv[i].push_back(nums[j]);   
    }
    return vv;
}