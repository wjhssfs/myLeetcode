// 161 One Edit Distance
// Given two strings S and T, determine if they are both one edit distance apart.

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() < t.size())swap(s,t);
        for(int i = 0; i < t.size(); i++){
            if(s[i] == t[i]) continue;
            if(s.size() == t.size()) return s.substr(i+1) == t.substr(i+1);
            else return s.substr(i+1) == t.substr(i);
        }
        return s.size() == t.size() + 1;
    }
};

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() < t.size()) swap(s, t);
        if (s.size() > t.size() + 1) return false;
        bool res = false;
        for (int i = 0, j = 0; i < s.size(); ++i, ++j) {
            if (t.size() && s[i] == t[j]) continue;
            if (res) return false;
            res = true;
            if (s.size() != t.size()) --j;
        }
        return res;
    }
};

/*
 * There're 3 possibilities to satisfy one edit distance apart: 
 * 
 * 1) Replace 1 char:
      s: a B c
      t: a D c
 * 2) Delete 1 char from s: 
      s: a D  b c
      t: a    b c
 * 3) Delete 1 char from t
      s: a   b c
      t: a D b c
 */
public boolean isOneEditDistance(String s, String t) {
    for (int i = 0; i < Math.min(s.length(), t.length()); i++) { 
        if (s.charAt(i) != t.charAt(i)) {
            if (s.length() == t.length()) // s has the same length as t, so the only possibility is replacing one char in s and t
                return s.substring(i + 1).equals(t.substring(i + 1));
            else if (s.length() < t.length()) // t is longer than s, so the only possibility is deleting one char from t
                return s.substring(i).equals(t.substring(i + 1));               
            else // s is longer than t, so the only possibility is deleting one char from s
                return t.substring(i).equals(s.substring(i + 1));
        }
    }       
    //All previous chars are the same, the only possibility is deleting the end char in the longer one of s and t 
    return Math.abs(s.length() - t.length()) == 1;        
}