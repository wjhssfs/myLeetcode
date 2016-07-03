// 345. Reverse Vowels of a String
// Write a function that takes a string as input and reverse only the vowels of a string.
// Example 1:
// Given s = "hello", return "holle".
// Example 2:
// Given s = "leetcode", return "leotcede".
class Solution {
public:
    string reverseVowels(string s) {
   		int i = 0, j = s.size() - 1;
   		while (i < j)
   		{
   			if (!isVowel(s[i])) {
   				++i;
   			} else if (!isVowel(s[j])) {
   				--j;
   			} else {
   				swap(s[i++], s[j--]);
   			}
   		}
   		return s;
    }

    bool isVowel(char c) {
    	static unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    	return vowels.count(c);
    }
};