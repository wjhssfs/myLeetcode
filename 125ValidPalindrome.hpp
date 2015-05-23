// 125 Valid Palindrome
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// 
// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
// 
// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.
// 
// For the purpose of this problem, we define empty string as valid palindrome.

#include <cctype> // needed for isalnum(), isupper() and tolower().

class Solution {
public:
	bool isPalindrome(string s) {
		int sz = s.size();
		int i = 0, j = sz - 1;
		while (i<j){
			while (i < j&&!isalnum(s[i])) i++;
			while (i < j&&!isalnum(s[j])) j--;
			if (tolower(s[i]) != tolower(s[j])) {
				return false;
			} else{
			i++; j--;
			}
		}
		return true;
	}
};
