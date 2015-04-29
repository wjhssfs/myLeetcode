// 49 Anagrams 
// Given an array of strings, return all groups of strings that are anagrams.

// Note: All inputs will be in lower-case.

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> m;
        vector<string> r;
        for (auto str : strs){
            string k = str;
            sort(k.begin(), k.end());
            m[k].push_back(str);
        }
        for (auto group : m)
        {
            if (group.second.size() > 1)
            {
                for (auto str : group.second) r.push_back(str);
            }
        }
        return r;
    }
};