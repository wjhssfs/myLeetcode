// 201 Bitwise AND of Numbers Range 
// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

// For example, given the range [5, 7], you should return 4.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned um = m, un = n, sig = (1ul << 31), res = 0, nNum = un - um + 1;
        while (sig){
            if (um & sig & un) res |= sig; // Left most bit of res
            if (nNum > (sig >> 1)) return res; // if nNum > sig/2, then the rest must be 0
            um &= ~sig; un &= ~sig;
            sig >>= 1;
        }
        return res;
    }
};