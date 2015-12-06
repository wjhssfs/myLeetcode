// 159 Longest Substring with At Most Two Distinct Characters

// Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

// For example, Given s = “eceba”,

// T is "ece" which its length is 3.

class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		if (s.empty()) return 0;
		int m[256] = {}, start = 0, end = 0, nc = 1, maxLen = 0, curLen = 0, sz = s.size();
		m[s[start]] = 1;
		while (end < sz) {
			while (nc < 3) {
				++curLen; 
				maxLen = max(curLen, maxLen);
				++end;
				if (end == sz)
					break;
				if (!m[s[end]])
					++nc;
				++m[s[end]];
			}
			while (nc == 3) {
				if (m[s[start]] == 1)
					--nc;
				--m[s[start]];
				++start; --curLen;
			}
		}

		return maxLen;
	}
};