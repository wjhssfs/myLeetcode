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

// https://discuss.leetcode.com/topic/68206/easy-python-solution-with-explaination/4
// First char of input string is first char of repeated substring
// Last char of input string is last char of repeated substring
// Let S1 = S + S (where S in input string)
// Remove 1 and last char of S1. Let this be S2
// If S exists in S2 then return true else false
// Let i be index in S2 where S starts then repeated substring length i + 1 and repeated substring S[0: i+1]
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if (str.empty()) return false;
        return (str + str).substr(1, str.size() * 2 - 2).find(str) != string::npos;
    }
};

def repeatedSubstringPattern(self, str):
    return str in (2 * str)[1:-1]