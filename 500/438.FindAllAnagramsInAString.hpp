// 438. Find All Anagrams in a String
// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
// The order of output does not matter.
// Example 1:
// Input:
// s: "cbaebabacd" p: "abc"
// Output:
// [0, 6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:
// Input:
// s: "abab" p: "ab"
// Output:
// [0, 1, 2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		unordered_map<char, int> m;
		for (auto c : p) ++m[c];
		int pLen = (int)p.size();
		int needMatch = pLen;
		vector<int> res;
		for (int i = 0; i < (int)s.size(); ++i) {
			if (i >= pLen && m.count(s[i - pLen])) {
				if (m[s[i - pLen]] >= 0) ++needMatch;
				++m[s[i - pLen]];
			}
			if (m.count(s[i])) {
				if (m[s[i]] > 0) --needMatch;
				--m[s[i]];
				if (!needMatch) res.push_back(i - pLen + 1);
			}
		}
		return res;
	}
};

// https://discuss.leetcode.com/topic/64434/shortest-concise-java-o-n-sliding-window-solution
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int m[256] = { 0 };
		for (auto c : p) ++m[c];
		int needMatch = p.size(), left = 0, right = 0;
		vector<int> res;
		while(right < s.size()) {
			if (m[s[right++]]-- >= 1) --needMatch;
			if (!needMatch) res.push_back(left);
			if (right - left == p.size() && m[s[left++]]++ >= 0) ++needMatch;
		}
		return res;
	}
};