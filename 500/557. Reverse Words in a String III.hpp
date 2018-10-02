// 557. Reverse Words in a String III
// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Note: In the string, each word is separated by single space and there will not be any extra space in the string.

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && isspace(s[i])) ++i;
            int j = i;
            while (j + 1 < s.size() && !isspace(s[j + 1])) ++j;
            for (int jj = j; i < jj; ++i,--jj) {
                swap(s[i], s[jj]);
            }
            i = j + 1;
        }
        return s;
    }
};