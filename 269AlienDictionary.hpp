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
                if(words[i][j] == words[i+1][j] || m[words[i][j]-'a'][words[i+1][j]-'a']) continue;
                m[words[i][j]-'a'][words[i+1][j]-'a'] = true;
                ++ind[words[i+1][j] - 'a'];
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
