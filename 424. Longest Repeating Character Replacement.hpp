// 424. Longest Repeating Character Replacement
// Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

// Note:
// Both the string's length and k will not exceed 104.

// Example 1:

// Input:
// s = "ABAB", k = 2

// Output:
// 4

// Explanation:
// Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input:
// s = "AABABBA", k = 1

// Output:
// 4

// Explanation:
// Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.

// https://discuss.leetcode.com/topic/63494/java-12-lines-o-n-sliding-window-solution-with-explanation/2
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(128);
        int maxCount = 0, start = 0;
        for (int end = 0; end < static_cast<int>(s.size()); ++end) {
            maxCount = max(maxCount, ++count[s[end]]);
            while(end - start + 1 - maxCount > k) --count[s[start++]];
        }
        return s.size() - start;
    }
};