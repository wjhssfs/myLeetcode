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

// last bit of (odd number & even number) is 0.
// when m != n, There is at least an odd number and an even number, so the last bit position result is 0.
// Move m and n rigth a position.
public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        int step = 0;
        while(m!=n){
            m >>= 1;
            n >>= 1;
            step ++;
        }
        return m<<step;
    }
}


while n > m:
    n &= (n-1);
return n;


// The idea is to use a mask to find the leftmost common digits of m and n. Example: m=1110001, n=1110111, and you just need to find 1110000 and it will be the answer.
public class Solution {
public int rangeBitwiseAnd(int m, int n) {
    int r=Integer.MAX_VALUE;
    while((m&r)!=(n&r))  r=r<<1;
    return n&r;
}