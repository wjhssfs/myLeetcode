// 387. First Unique Character in a String
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

class Solution {
public:
    int firstUniqChar(string s) {
        int count[128] = {};
        for (auto c : s) ++count[c];
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]] == 1) return i;
        }
        return -1;
    }
};

// if string is extremely long
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        int idx = s.size();
        for(int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        for(auto &p : m) {
            if(p.second.first == 1) idx = min(idx, p.second.second);
        }
        return idx == s.size() ? -1 : idx;
    }
};

class Solution(object):
    def firstUniqChar(self, s):
        index=[s.index(l) for l in string.ascii_lowercase if s.count(l) == 1]
        return min(index) if len(index) > 0 else -1