// 233 Number of Digit One
// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
// For example:
// Given n = 13,
// Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        if(n < 10) return 1;
        char buf[100];
        sprintf(buf, "%d", n);
        int base = pow(10, strlen(buf)-1);
        int leadDigit = n/base;
        int sum = countDigitOne(base - 1) * leadDigit;
        sum += (leadDigit == 1) ? n - base + 1 : base;
        sum += countDigitOne(n%base);
        return sum;
    }
};

class Solution {
public:
    int countDigitOne(int n) {
        vector<int> t;
        populateTable(t);
        int total = 0, ti= 0;
        long long s = 1; // overflow if this is int
        while (s * 10 <= n){ s *= 10; ti++; }
        while (n){
            int c = n / s;
            n -= c * s;
            if (c == 1) total += (n+1);
            else if(c > 1) total += s;
            total += t[ti] * c;
            s /= 10;
            ti -= 1;
        }
        return total; 
    }
private:
    void populateTable(vector<int> &t){
        int base = 1;
        t.resize(11);
        t[0] = 0;
        for (int i = 1; i < t.size(); i++){
            t[i] = base + t[i - 1] * 10;
            base *= 10;
        }
    }
};