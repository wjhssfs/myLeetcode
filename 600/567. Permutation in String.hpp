// 567. Permutation in String
// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

// Example 1:
// Input:s1 = "ab" s2 = "eidbaooo"
// Output:True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
// Note:
// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        vector<int> m(26);
        int need = 0;
        for (auto c : s1) { 
            if (m[c - 'a'] == 0) ++need;
            ++m[c - 'a']; 
        }
        for (int start = 0, end = 0; end < s2.size();) {
            if (end >= s1.size() && m[s2[start++] - 'a']++ == 0) ++need;
            if (m[s2[end++] - 'a']-- == 1 && --need == 0) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        unordered_map<int, int> m;
        for (auto c : s1)  ++m[c];
        int need = m.size();
        for (int start = 0, end = 0; end < s2.size();) {
            if (end >= s1.size() && m[s2[start++]]++ == 0) ++need;
            if (m[s2[end++]]-- == 1 && --need == 0) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> m1(26), m2(26);
        for (int i = 0; i < s1.size(); ++i) {
            ++m1[s1[i] - 'a'];
            ++m2[s2[i] - 'a'];
        }
        if (m1 == m2) return true;
        for (int i = s1.size(); i < s2.size(); ++i) {
            --m2[s2[i - s1.size()] - 'a']; 
            ++m2[s2[i] - 'a'];
            if (m1 == m2) return true;
        }
        return false;
    }
};