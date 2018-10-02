// 342. Power of Four
// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
// Example:
// Given num = 16, return true. Given num = 5, return false.
// Follow up: Could you solve it without loops/recursion?
class Solution {
public:
    bool isPowerOfFour(int num) {
        unsigned base = 1ul;
        for(int i = 0; i < 16; ++i)
        {
            if(num == base) return true;
            base = (base << 2);
        }
        return false;
    }
};

bool isPowerOfFour(int num) {
    return (num & 0x55555555) && !(num & (num - 1)); 
}