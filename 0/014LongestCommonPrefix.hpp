// 14 Longest Common Prefix 
// Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
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

// greedy.
public String longestCommonPrefix(String[] strs) {
    if(strs == null || strs.length == 0)    return "";
    String pre = strs[0];
    int i = 1;
    while(i < strs.length){
        while(strs[i].indexOf(pre) != 0)
            pre = pre.substring(0,pre.length()-1);
        i++;
    }
    return pre;
}