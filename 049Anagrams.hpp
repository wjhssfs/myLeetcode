// 49 Anagrams 
// Given an array of strings, return all groups of strings that are anagrams.
// Note: All inputs will be in lower-case.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> r;
        for (auto str : strs){
            string k = str;
            sort(k.begin(), k.end());
            m[k].push_back(str);
        }
        for (auto && e : m) {
            r.push_back(e.second);
        }
        return r;
    }
};