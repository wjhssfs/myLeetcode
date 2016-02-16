// 316. Remove Duplicate Letters

// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

// Example:
// Given "bcabc"
// Return "abc"

// Given "cbacdcbc"
// Return "acdb"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<unsigned int> cnt(26,0); //only consider lowercase letters
        vector<bool> inRes(26, false); //true if the letter has been added to res 
        for(char ch:s) cnt[ ch-'a' ]++;
        string res = ""; //use res as a stack
        for(char ch:s){
           cnt[ ch-'a' ]--;
           if(inRes[ch-'a']) continue;
           while(!res.empty() && ch<res.back() && cnt[ res.back()-'a' ]>0){
               inRes[ res.back()-'a' ] = false;
               res.pop_back();

           }
           res.push_back(ch);
           inRes[ ch-'a' ] = true;
        }
        return res;
    }
};


// https://leetcode.com/discuss/73761/a-short-o-n-recursive-greedy-solution
public class Solution {
    public String removeDuplicateLetters(String s) {
        int[] cnt = new int[26];
        int pos = 0; // the position for the smallest s[i]
        for (int i = 0; i < s.length(); i++) cnt[s.charAt(i) - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(pos)) pos = i;
            if (--cnt[s.charAt(i) - 'a'] == 0) break;
        }
        return s.length() == 0 ? "" : s.charAt(pos) + removeDuplicateLetters(s.substring(pos + 1).replaceAll("" + s.charAt(pos), ""));
    }
}