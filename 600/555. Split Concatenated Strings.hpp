// 555. Split Concatenated Strings
// Given a list of strings, you could concatenate these strings together into a loop, where for each string you could choose to reverse it or not. Among all the possible loops, you need to find the lexicographically biggest string after cutting the loop, which will make the looped string into a regular one.

// Specifically, to find the lexicographically biggest string, you need to experience two phases:

// Concatenate all the strings into a loop, where you can reverse some strings or not and connect them in the same order as given.
// Cut and make one breakpoint in any place of the loop, which will make the looped string into a regular one starting from the character at the cutpoint.
// And your job is to find the lexicographically biggest one among all the possible regular strings.

// Example:
// Input: "abc", "xyz"
// Output: "zyxcba"
// Explanation: You can get the looped string "-abcxyz-", "-abczyx-", "-cbaxyz-", "-cbazyx-", 
// where '-' represents the looped status. 
// The answer string came from the fourth looped one, 
// where you could cut from the middle character 'a' and get "zyxcba".
// Note:
// The input strings will only contain lowercase letters.
// The total length of all the strings will not over 1,000.

class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string m, res;
        for (auto && str : strs) {
            string strR(str.rbegin(), str.rend());
            str >= strR ? m += str: m += strR;
        }
        int start = 0;
        for (auto && str : strs) {
            auto center = m.substr(start + str.size()) + m.substr(0, start);
            for (int i = 0; i < str.size(); ++i) {
                auto tr = str.substr(i) + center + str.substr(0, i);
                if (tr > res) res = tr;
            }
            string strR(str.rbegin(), str.rend());
            for (int i = 0; i < str.size(); ++i) {
                auto tr = strR.substr(i) + center + strR.substr(0, i);
                if (tr > res) res = tr;
            }
            start += str.size();
        }
        return res;
    }
};

string splitLoopedString(vector<string>& strs) {
    string s = "", res = "a";
    for (auto i = 0; i < strs.size(); ++i) {
        auto r = strs[i];
        reverse(r.begin(), r.end());
        s += max(r, strs[i]);
    }
    for (auto i = 0, st = 0; i < strs.size(); st += strs[i++].size()) {
        auto p1 = strs[i], p2 = strs[i], body = s.substr(st + p1.size()) + s.substr(0, st);
        reverse(p2.begin(), p2.end());
        for (auto j = 0; j < strs[i].size(); ++j) {
            if (p1[j] >= res[0]) res = max(res, p1.substr(j) + body + p1.substr(0, j));
            if (p2[j] >= res[0]) res = max(res, p2.substr(j) + body + p2.substr(0, j));
        }
    }
    return res;
}