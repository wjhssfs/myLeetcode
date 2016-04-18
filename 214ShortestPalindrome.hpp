// 214 Shortest Palindrome 
// Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
// Find and return the shortest palindrome you can find by performing this transformation.
// For example:
// Given "aacecaaa", return "aaacecaaa".
// Given "abcd", return "dcbabcd".
// https://leetcode.com/discuss/36807/c-8-ms-kmp-based-o-n-time-&-o-n-memory-solution
// We can construct the following string and run KMP algorithm on it: (s) + (some symbol not present in s) + (reversed string)
// After running KMP on that string as result we get a vector p with values of a prefix function for each
// character (for definition of a prefix function see KMP algorithm description). We are only interested in the
// last value because it shows us the largest suffix of the reversed string that matches the prefix of the
// original string. So basically all we left to do is to add the first k characters of the reversed string to
// the original string, where k is a difference between original string size and the prefix function
// for the last character of a constructed string.
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }

        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }
};

// O(n2)
// In order to slove this problem, the key is to get the length of the longest palindromic prefix substring. 
// if the length of s is len, and the length of the longest palindromic prefix substring is longest,
// the remaining substring will be s.substr(longest, len - longest),
// than we should reverse the remaining substring and adding it in front of s.
// For example, if s is "abacbbcda", so the longest palindromic prefix substring is
// "aba"(not "cbbc" because it's not prefix string), and the remaining substring is "cbbcda",
// we reverse the remaining substring and get "adcbbc", so the result is "adcbbc" + "abacbbcda".

class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        int len = s.length();
        if (len < 2)
            return s;
        // calculate the length of the longest palindromic prefix substring.
        int longest = 1, start, end;
        for (int begin = 0; begin <= len / 2;) {
            start = end = begin;
            while (end < len - 1 && s[end + 1] == s[end])
                ++end;
            begin = end + 1;
            while (end < len - 1 && start > 0 && s[end + 1] == s[start - 1]) {
                ++end;
                --start;
            }
            // start == 0 means the palindromic substring is also prefix string.
            if (start == 0 && longest < end - start + 1)
                longest = end - start + 1;
        }
        // reverse the remaining substring and adding it in front of s.
        std::string remaining = s.substr(longest, len - longest);
        std::reverse(remaining.begin(), remaining.end());
        return remaining + s;
    }
};