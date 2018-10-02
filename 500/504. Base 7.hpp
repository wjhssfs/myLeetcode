// 504. Base 7

// Given an integer, return its base 7 string representation.

// Example 1:
// Input: 100
// Output: "202"
// Example 2:
// Input: -7
// Output: "-10"
// Note: The input will be in range of [-1e7, 1e7].

class Solution {
public:
    string convertToBase7(int num) {
        if (!num) return "0";
        string res;
        bool isNegative = false;
        if (num < 0) {
            isNegative = true;
            num = -num;
        }
        while (num) {
            res += num % 7 + '0';
            num /= 7;
        }
        if (isNegative)  res += '-';
        return string(res.rbegin(), res.rend());
    }
};

    string convertToBase7(int num) {
      int x = abs(num);
      string res;
      do 
        res = to_string(x%7)+res; 
      while(x/=7);
      return num>=0? res : "-"+res;
    }

     string convertToBase7(int n) {
      return n>=0? n>=7? convertToBase7(n/7)+to_string(n%7) : to_string(n) : '-'+convertToBase7(-n);
    }