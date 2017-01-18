// 58 Length of Last Word
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
// return the length of last word in the string. 
// If the last word does not exist, return 0.
// Note: A word is defined as a character sequence consists of non-space characters only.
// For example, 
// Given s = "Hello World",
// return 5.

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while (*s) {
            if (*s++ != ' ')
                ++len;
            else if (*s && *s != ' ')
                len = 0;

        }
        return len;
    }
};

class Solution2 {
public:
    int lengthOfLastWord(const char *s) {
        int res = 0;
        int length = strlen(s);
        for (int i = length - 1; i >= 0; --i)
            if (s[i] != ' ') res++;
            else if(res > 0) break;
        return res;
    }
};

