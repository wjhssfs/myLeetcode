// 409. Longest Palindrome

// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:

// Input:
// "abccccdd"

// Output:
// 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

class Solution {
public:
    int longestPalindrome(string s) {
        bool odd[128] = {};
        int nEven = 0;
        for (auto c : s) {
            if (odd[c]) {
                ++nEven;
                odd[c] = false;
            } else {
                odd[c] = true;
            }
        }
        return nEven * 2 == s.size() ? nEven * 2 : nEven * 2 + 1;
    }
};