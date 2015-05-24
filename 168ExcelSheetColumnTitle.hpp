// 168 Excel Sheet Column Title 
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// 
// For example:
// 
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 

// http://articles.leetcode.com/2010/10/amazon-bar-raiser-interview-question.html

class Solution {
public:
    string convertToTitle(int n) {
        string r;
        if (n <= 0) return r;
        do{
            r += char((n-1) % 26 + 'A');
            n = (n-1)/26; // minus 1 needed.
        } while (n);
        return string(r.rbegin(), r.rend());
    }
};