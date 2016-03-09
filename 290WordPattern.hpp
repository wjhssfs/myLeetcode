// 290 Word Pattern
// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = (int)pattern.size();
        vector<int> spaceP(n+1);
        spaceP[0] = -1;
        int j = 1;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ') spaceP[j++] = i;
        }
        if(j!=n) return false;
        spaceP[j] = (int)str.size();
        map<char, string> pTos;
        map<string, char> sTop;
        for(int i = 0; i < pattern.size(); i++){
            string subStr = str.substr(spaceP[i] + 1, spaceP[i+1] - spaceP[i] - 1);
            if(!pTos.count(pattern[i])){
                if(sTop.count(subStr)) return false;
                pTos[pattern[i]] = subStr;
                sTop[subStr] = pattern[i];
            }else if(pTos[pattern[i]] != subStr) return false;
        }
        return true;
    }
};

class Solution(object):
    def wordPattern(self, pattern, str):
        if len(pattern) != len(slist):
            return False
        return (len(set(pattern)) == len(set(slist)) == len(set(zip(pattern, slist))))

bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1; // avoid default value 0.
    }
    return i == n;
}

  bool wordPattern(string pattern, string str) {
        istringstream strcin(str);
        string s;
        vector<string> vs;
        while(strcin >> s) vs.push_back(s);
        if (pattern.size() != vs.size()) return false;
        map<string, char> s2c;
        map<char, string> c2s;
        for (int i = 0; i < vs.size(); ++i) {
            if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") { 
                s2c[vs[i]] = pattern[i]; 
                c2s[pattern[i]] = vs[i]; 
                continue; 
            }
            if (s2c[vs[i]] != pattern[i]) return false;
        }
        return true;
    }