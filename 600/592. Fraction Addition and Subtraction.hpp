// 592. Fraction Addition and Subtraction

// Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

// Example 1:
// Input:"-1/2+1/2"
// Output: "0/1"
// Example 2:
// Input:"-1/2+1/2+1/3"
// Output: "1/3"
// Example 3:
// Input:"1/3-1/2"
// Output: "-1/6"
// Example 4:
// Input:"5/3+1/3"
// Output: "2/1"
// Note:
// The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
// Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
// The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
// The number of given fractions will be in the range [1,10].
// The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

class Solution {
    int gcd (int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
public:
    string fractionAddition(string expression) {
        int n1 = 0, d1 = 1;
        for (int i = 0; i < expression.size();) {
            int n2 = 0, d2 = 0, f = 1;
            if (expression[i] == '-') f = -1;
            if (!isdigit(expression[i])) ++i;
            while (expression[i] != '/') { n2 = n2 * 10 + expression[i] - '0'; ++i; }
            n2 *= f;
            ++i;
            while (i < expression.size() && isdigit(expression[i])) { d2 = d2 * 10 + expression[i] - '0'; ++i; }
            
            int n = n1 * d2 + n2 * d1;
            int d = d1 * d2;
            int g = gcd (abs(n), d);
            n1 = n / g; d1 = d / g;
        }
        return to_string(n1) + "/" + to_string(d1);
    }
};

string fractionAddition(string expression) {
    istringstream in(expression);
    int A = 0, B = 1, a, b;
    char _;
    while (in >> a >> _ >> b) {
        A = A * b + a * B;
        B *= b;
        int g = abs(__gcd(A, B));
        A /= g;
        B /= g;
    }
    return to_string(A) + '/' + to_string(B);
}