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