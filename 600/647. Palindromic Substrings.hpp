// 647. Palindromic Substrings
// Given a string, your task is to count how many palindromic substrings in this string.

// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

// Example 1:
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// Note:
// The input string length won't exceed 1000.

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        int count = n;
        vector<vector<bool>> m(n, vector<bool>(n));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j + i - 1 < n; ++j) {
                if (i == 1) { m[j][j] = true; continue; }
                else {
                    if ((i == 2 || m[j + 1][j + i - 2]) && s[j] == s[j + i - 1]) {
                        m[j][j + i -1] = true;
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};

public class Solution {
    int count = 0;
    
    public int countSubstrings(String s) {
        if (s == null || s.length() == 0) return 0;
        
        for (int i = 0; i < s.length(); i++) { // i is the mid point
            extendPalindrome(s, i, i); // odd length;
            extendPalindrome(s, i, i + 1); // even length
        }
        
        return count;
    }
    
    private void extendPalindrome(String s, int left, int right) {
        while (left >=0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            count++; left--; right++;
        }
    }
}