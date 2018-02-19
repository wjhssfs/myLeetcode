// 269 Alien Dictionary 

// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

// For example,
// Given the following words in dictionary,

// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// The correct order is: "wertf".

// Note:
// You may assume all letters are in lowercase.
// If the order is invalid, return an empty string.
// There may be multiple valid order of letters, return any one of them is fine.

class Solution {
public:
    string alienOrder(vector<string>& words) {
        bool m[26][26] = {};
        int ind[26] = {};
        bool cS[26] = {};
        int nC = 0;
        for(auto &word : words){
            for(char c : word){
                if(!cS[c-'a']) ++nC;
                cS[c-'a'] = true;
            }
        }
        
        for(int i = 0; i < words.size()-1; i++){
            int jCeil = (int)min(words[i].size(), words[i+1].size());
            for(int j = 0; j < jCeil; j++){
                if(words[i][j] == words[i+1][j]) continue;
                if(!m[words[i][j]-'a'][words[i+1][j]-'a']) {
                    m[words[i][j]-'a'][words[i+1][j]-'a'] = true;
                    ++ind[words[i+1][j] - 'a'];
                }
                break;
            }
        }
        
        string r;
        bool changed = true;
        while(changed){
            changed = false;
            for(int i = 0; i < 26; i++){
                if(cS[i] && ind[i] == 0){
                    r.push_back('a'+i);
                    for(int j = 0; j < 26; j++){
                        if(m[i][j]) --ind[j];
                    }
                    changed = true;
                    ind[i] = -1;
                }
            }
        }
        if(r.size()==nC) return r;
        else return "";
    }
};

// https://leetcode.com/discuss/54188/16-18-lines-python-30-lines-c
string alienOrder(vector<string>& words) {
    map<char, set<char>> suc, pre;
    set<char> chars;
    string s;
    for (string t : words) {
        chars.insert(t.begin(), t.end());
        for (int i=0; i<min(s.size(), t.size()); ++i) { // skipped for first word since s is empty
            char a = s[i], b = t[i];
            if (a != b) {
                suc[a].insert(b);
                pre[b].insert(a);
                break;
            }
        }
        s = t;
    }
    set<char> free = chars;
    for (auto p : pre)
        free.erase(p.first);
    string order;
    while (free.size()) {
        char a = *begin(free);
        free.erase(a);
        order += a;
        for (char b : suc[a]) {
            pre[b].erase(a);
            if (pre[b].empty())
                free.insert(b);
        }
    }
    return order.size() == chars.size() ? order : "";
}
