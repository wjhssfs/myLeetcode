// 400. Nth Digit
// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

// Note:
// n is positive and will fit within the range of a 32-bit signed integer (n < 231).

// Example 1:

// Input:
// 3

// Output:
// 3
// Example 2:

// Input:
// 11

// Output:
// 0

// Explanation:
// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

class Solution {
public:
    int findNthDigit(int n) {
        long long base = 9, ndigits = 1;
        while (n > base * ndigits) {
            n -= base * ndigits;
            base *= 10;
            ++ndigits;
        }
        base /= 9;
        --n;
        long long num = base + n / ndigits;
        string strN = to_string(num);
        return strN[n%ndigits] - '0';
    }
};

// https://leetcode.com/problems/nth-digit/
class Solution 
{
    // date: 2016-09-18     location: Vista Del Lago III Apartments
public:
    int findNthDigit(int n) 
    {
        // step 1. calculate how many digits the number has.
        long base = 9, digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // step 2. calculate what the muber is.
        int index = n % digits;
        if (index == 0)
            index = digits;
        long num = 1;
        for (int i = 1; i < digits; i ++)
            num *= 10;
        num += (index == digits) ? n / digits - 1 : n / digits;;

        // step 3. find out which digit in the number is we want.
        for (int i = index; i < digits; i ++)
            num /= 10;
        return num % 10;
    }
};

// https://discuss.leetcode.com/topic/59410/straight-forward-6-line-c-solution-with-explanation
int findNthDigit(int n) {
    n--;
    for (int k = 1, first = 1; ; k++, first *= 10) {
        if (n / 9 / k < first)
            return (first + n / k) / (int)pow(10, k - 1 - n % k) % 10;
        n -= 9 * k * first;
    }
}
