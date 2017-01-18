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


class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        x = abs(x);
        int res = 0;
        while (x > 0) {
            if (INT_MAX / 10 < res || (INT_MAX - x % 10) < res * 10) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }

        return sign * res;
    }
};

public int reverse(int x)
{
    int result = 0;

    while (x != 0)
    {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        if ((newResult - tail) / 10 != result)
        { return 0; }
        result = newResult;
        x = x / 10;
    }

    return result;
}