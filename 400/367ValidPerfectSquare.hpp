// 367. Valid Perfect Square
// Given a positive integer num, write a function which returns True if num is a perfect square else False.
// Note: Do not use any built-in library function such as sqrt.
// Example 1:
// Input: 16
// Returns: True
// Example 2:
// Input: 14
// Returns: False

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        long long l = 1, r = num;
        while (l <=r) {
            long long m = (l + r) / 2;
            long long msq = m * m;
            if (msq == num)
                return true;
            msq > num ? r = m - 1 : l = m + 1;
        }
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0, r = num;
        while (l < r) {
            long long m = l + (r - l) / 2;
            long long msq = m * m;
            if (msq < num) {
                l++;
            } else r = m;
        }
        return l * l == num;
    }
};

// A square number is 1+3+5+7+...,
public boolean isPerfectSquare(int num) {
    int i = 1;
    while (num > 0) {
        num -= i;
        i += 2;
    }
    return num == 0;
}

// https://discuss.leetcode.com/topic/49342/3-4-short-lines-integer-newton-most-languages
// https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
    long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r*r == x;