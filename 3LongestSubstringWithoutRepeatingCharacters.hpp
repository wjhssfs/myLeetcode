// 3 Longest Substring Without Repeating Characters 
// Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		bool appeared[256] = {false};
        decltype(s.size()) i = 0, j = 0, maxLen = 0;//, maxStart = 0;
		while(j<s.size())
		{
			if(!appeared[s[j]]){
				if(maxLen < j-i+1){
					maxLen = j-i+1;
					//maxStart = i;
				}
				appeared[s[j]] = true;
				++j;
			}else{
				appeared[s[i]] = false;
				++i;
			}
		}
		return maxLen;
    }
};