// 395. Longest Substring with At Least K Repeating Characters

// Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

// Example 1:

// Input:
// s = "aaabb", k = 3

// Output:
// 3

// The longest substring is "aaa", as 'a' is repeated 3 times.
// Example 2:

// Input:
// s = "ababbc", k = 2

// Output:
// 5

// The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s, 0, s.size(), k);
    }
    
    int longestSubstring(const string &s, int start, int end, int k) {
        if (end - start < k) return 0;
        vector<int> m(26), p(26, -1);
        for (int i = start; i < end; ++i) { ++m[s[i] - 'a']; p[s[i] - 'a'] = i; }
        for (int i = 0; i < 26; ++i) {
            if (m[i] && m[i] < k) {
                int left = longestSubstring(s, start, p[i], k);
                int right = longestSubstring(s, p[i] + 1, end, k);
                return max(left, right);
            }
        }
        return end - start;
    }
};

def longestSubstring(self, s, k):
    for c in set(s):
        if s.count(c) < k:
            return max(self.longestSubstring(t, k) for t in s.split(c))
    return len(s)