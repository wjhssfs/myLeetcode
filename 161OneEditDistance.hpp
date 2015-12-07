// 161 One Edit Distance

// Given two strings S and T, determine if they are both one edit distance apart.

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() < t.size())swap(s,t);
        if(s.size() - t.size() > 1) return false;
        for(int i = 0; i < t.size(); i++){
            if(s[i] == t[i]) continue;
            if(s.size() == t.size()) return s.substr(i+1) == t.substr(i+1);
            else return s.substr(i+1) == t.substr(i);
        }
        return s.size()!=t.size();
    }
};