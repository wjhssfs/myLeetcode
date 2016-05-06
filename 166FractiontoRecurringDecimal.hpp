// 166 Fraction to Recurring Decimal 
// Given two integers representing the numerator and denominator of a fraction,
// return the fraction in string format.
// If the fractional part is repeating, enclose the repeating part in parentheses.
// For example,
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


// upgraded parameter types
string fractionToDecimal(int64_t n, int64_t d) {
    // zero numerator
    if (n == 0) return "0";

    string res;
    // determine the sign
    if (n < 0 ^ d < 0) res += '-';

    // remove sign of operands
    n = abs(n), d = abs(d);

    // append integral part
    res += to_string(n / d);

    // in case no fractional part
    if (n % d == 0) return res;

    res += '.';

    unordered_map<int, int> map;

    // simulate the division process
    for (int64_t r = n % d; r; r %= d) {

        // meet a known remainder
        // so we reach the end of the repeating part
        if (map.count(r) > 0) {
            res.insert(map[r], 1, '(');
            res += ')';
            break;
        }

        // the remainder is first seen
        // remember the current position for it
        map[r] = res.size();

        r *= 10;

        // append the quotient digit
        res += to_string(r / d);
    }

    return res;
}
