// 3 Longest Substring Without Repeating Characters 
// Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool appeared[256] = {false};
        int i = 0, j = 0, maxLen = 0;
        while(j<s.size())
        {
            if(!appeared[s[j]]){
                maxLen = max(maxLen, j-i+1);
                appeared[s[j++]] = true;
            }
            else appeared[s[i++]] = false;
        }
        return maxLen;
    }
};