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
        double p = 1;
        bool negN = n < 0;
        long long lln = n;
        lln = abs(lln);
        while (lln) {
            if (lln & 1) {
                p *= x;
            }
            lln >>= 1;
            x *= x;
        }
        if (negN) p = 1/p;
        return p;
    }
};