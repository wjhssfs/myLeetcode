// 205 Isomorphic Strings 
// Given two strings s and t, determine if they are isomorphic.
// Two strings are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters.
// No two characters may map to the same character but a character may map to itself.
// For example,
// Given "egg", "add", return true.
// Given "foo", "bar", return false.
// Given "paper", "title", return true.
// Note:
// You may assume both s and t have the same length.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char m[256] = {}/*real mapping*/, mr[256] = {}/*to make sure not two characters mapped to same character*/;
        for(int i = 0; i < s.size(); i++){
            if(!m[s[i]]) {
                if(mr[t[i]]) return false;
                m[s[i]] = t[i];
                mr[t[i]] = 1;
            }
            if(m[s[i]] != t[i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};