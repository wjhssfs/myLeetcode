// 459. Repeated Substring Pattern
// Given a non-empty string check if it can be constructed by taking a substring of it and appending 
// multiple copies of the substring together. You may assume the given string consists of lowercase
// English letters only and its length will not exceed 10000.
// Example 1:
// Input: "abab"
// Output: True
// Explanation: It's the substring "ab" twice.
// Example 2:
// Input: "aba"
// Output: False
// Example 3:
// Input: "abcabcabcabc"
// Output: True
// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        for (int l = 1; l <= str.size() / 2; ++l) {
            if (str.size() % l) continue;
            string subStr = str.substr(0, l);
            int start = l;
            while (start < str.size()) {
                if (str.substr(start, l) != subStr) break;
                start += l;
            }
            if (start == str.size()) return true;
        }
        return false;
    }
};