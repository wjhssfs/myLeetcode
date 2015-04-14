// 7 Reverse Integer 
// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321

class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
		x = x * sign;
		int ret = 0;
		while (x > 0){
			ret *= 10;
			ret += x % 10;
			x /= 10;
		}
		return sign* ret;
    }
};