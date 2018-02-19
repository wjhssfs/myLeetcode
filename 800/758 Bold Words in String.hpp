// 758 Bold Words in String
// Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.

// The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

// For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

// Note:

// words has length in range [0, 50].
// words[i] has length in range [1, 10].
// S has length in range [0, 500].
// All characters in words[i] and S are lowercase letters.

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string res;
        for (int i = 0, bs = 0, be = -1; i <= s.size(); ++i) {
            for (int j = 0; j < dict.size(); ++j) {
                if (i + dict[j].size() <= s.size() && s.substr(i, dict[j].size()) == dict[j]) {
                    be = max(be, i + (int)dict[j].size() - 1);
                }
            }
            if (i > be) {
                if (be != -1) res += "<b>" + s.substr(bs, be - bs + 1) + "</b>";
                if (i < s.size()) res += s[i];
                bs = i + 1;
                be = -1;
            }
        }
        return res;
    }
};