// 166 Fraction to Recurring Decimal 
// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
// 
// If the fractional part is repeating, enclose the repeating part in parentheses.
// 
// For example,
// 
// Given numerator = 1, denominator = 2, return "0.5".
// Given numerator = 2, denominator = 1, return "2".
// Given numerator = 2, denominator = 3, return "0.(6)".


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!denominator) return "0";
        string str;
        long long n = numerator, d = denominator;
        if (n < 0 && d < 0) { n = -n; d = -d; }
        else if (n < 0 && d > 0) { n = -n; str += '-'; }
        else if (n > 0 && d < 0) { d = -d; str += '-'; }
        long long integerPart = n / d;
        str += to_string(integerPart);
        long long r = n % d;
        
        if (!r) return str;
        map<long long, long long> m;
        str += '.';
        while (r){
            if (m.find(r) == m.end()){
                m[r] = str.length();
            }
            else
            {
                str.insert(str.begin() + m[r], '(');
                str += ')';
                break;
            }
            r *= 10;
            if (r < d){ str += '0'; continue; }
            long long q = 0;
            while (r - d >= 0){ q++; r -= d; }
            str += '0' + q;            
        }

        return str;
    }
};
