// 14 Longest Common Prefix 
// Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int sz = strs.size();
        if (!sz) return "";
        int longestN = 0;
        bool continueSearch = true;
        while (continueSearch && longestN < strs[0].size())
        {
            char cur = strs[0][longestN];
            for (int i = 1; i < sz; i++)
            {
                if (longestN >= strs[i].size() || strs[i][longestN] != cur){
                    continueSearch = false;
                    break;
                }
            }
            if (continueSearch) longestN++;
        }
        return strs[0].substr(0, longestN);
    }
};

class Solution2 {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        if (strs.empty()) return res;
        for (int i = 0; i < strs[0].size(); ++i)
        {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j)
                if (i == strs[j].size() || strs[j][i] != ch)
                    return res;
            res.push_back(ch);
        }
        return res;
    }
};
