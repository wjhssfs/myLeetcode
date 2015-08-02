// 242 Valid Anagram 

// Given two strings s and t, write a function to determine if t is an anagram of s.

// For example,
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.

// Note:
// You may assume the string contains only lowercase alphabets.

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m[26] = {};
        int total = 0;
        for(char c : s) {m[c-'a']++; total++;}
        for(char c : t) {
            if(!m[c-'a'] || !total) return false;
            total--; m[c-'a']--;
        }
        return !total;
    }
};