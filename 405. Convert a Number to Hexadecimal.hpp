// 405. Convert a Number to Hexadecimal

// Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

// Note:

// All letters in hexadecimal (a-f) must be in lowercase.
// The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
// The given number is guaranteed to fit within the range of a 32-bit signed integer.
// You must not use any method provided by the library which converts/formats the number to hex directly.
// Example 1:

// Input:
// 26

// Output:
// "1a"
// Example 2:

// Input:
// -1

// Output:
// "ffffffff"

class Solution {
public:
    string toHex(int num) {
        string HEX = "0123456789abcdef";
        unsigned mask = 0xf0000000u, shift = 28;
        string result;
        while (mask) {
            int index = ((num & mask) >> shift);
            result += HEX[index];
            shift -= 4;
            mask >>= 4;
        }
        auto p = result.find_first_not_of("0");
        return p == string::npos ? "0" : result.substr(p);
    }
};

const string HEX = "0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string result;
        int count = 0;
        while (num && count++ < 8) {
            result = HEX[(num & 15)] + result;
            num >>= 4;
        }
        return result;
    }
};