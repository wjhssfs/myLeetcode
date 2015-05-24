// 139 Word Break
// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
// 
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
// 
// Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<bool> canBreak(N+1);
        canBreak[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (canBreak[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[N];
    }
};
