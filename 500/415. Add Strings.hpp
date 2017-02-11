// 415. Add Strings

// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

class Solution {
public:
    string addStrings(const string &num1, const string &num2) {
        int i1 = num1.size() - 1, i2 = num2.size() - 1, c = 0;
        string result;
        while (c || i1 >= 0 || i2 >= 0) {
            int cur = c;
            if (i1 >= 0) {cur += num1[i1] - '0'; --i1;}
            if (i2 >= 0) {cur += num2[i2] - '0'; --i2;}
            c = cur / 10;
            cur = cur % 10;
            result.push_back('0' + cur);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};