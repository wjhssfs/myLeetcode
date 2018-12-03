// 50 Pow(x, n)
// Implement pow(x, n).

class Solution {
public:
    double pow(double x, int n) {
        if (x < 0) return (n % 2 == 0) ? pow(-x, n) : -pow(-x, n);
        if (x == 0 || x == 1) return x;
        if (n < 0) return 1.0 / pow(x, -n);
        if (n == 0) return 1.0;
        
        double half = pow(x, n / 2);
        if (n % 2 == 0) return half * half;
        else return x * half * half;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        bool negN = n < 0;
        unsigned un = abs(n);
        double res = 1.0;
        while (un) {
            if (un & 1) res *= x;
            un >>= 1;
            x *= x;
        }
        if (negN) res = 1/ res;
        return res;
    }
};