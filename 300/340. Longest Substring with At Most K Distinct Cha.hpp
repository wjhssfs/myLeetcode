// 340. Longest Substring with At Most K Distinct Characters

// Given a string, find the length of the longest substring T that contains at most k distinct characters.

// For example, Given s = “eceba” and k = 2,

// T is "ece" which its length is 3.

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> m(128);
        if (s.empty() || k == 0) return 0;
        int start = 0, end = 0, maxLen = 0, cK = 0;
        while (1) {
            while (end < s.size()) {
                if (m[s[end]] == 0) {
                    if (cK == k) break;
                    cK++;
                }
                ++m[s[end++]];
            }
            maxLen = max(maxLen, end - start);
            if (end == s.size()) break;
            while (start < end) {
                if (--m[s[start++]] == 0) {--cK; break;}
            }
        }
        return maxLen;
    }
};

public class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int[] count = new int[256];
        int num = 0, i = 0, res = 0;
        for (int j = 0; j < s.length(); j++) {
            if (count[s.charAt(j)]++ == 0) num++;
            if (num > k) {
                while (--count[s.charAt(i++)] > 0);
                num--;
            }
            res = Math.max(res, j - i + 1);
        }
        return res;
    }
}