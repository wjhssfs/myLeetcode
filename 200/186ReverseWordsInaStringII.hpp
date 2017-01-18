// 186 Reverse Words in a String II
// Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
// The input string does not contain leading or trailing spaces and the words are always separated by a single space.
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".
// Could you do it in-place without allocating extra space?
class Solution {
public:
    void reverseWords(string &s) {
        int sz = s.size(), i = 0, j = sz-1;
        while(i<j)
            swap(s[i++], s[j--]);
        i = 0;
        while(i < sz){
            int start = i, end = i;
            while(end < sz - 1 && s[end + 1] != ' ')
                ++end;
            i = end + 2;
            while(start < end)
                swap(s[start++], s[end--]);
        }
    }
};