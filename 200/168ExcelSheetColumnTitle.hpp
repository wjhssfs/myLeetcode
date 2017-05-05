// 168 Excel Sheet Column Title 
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// For example:
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
        // (a0+1) + (a1+1)*26 + (a2+1)*26^2 ... = n
        // a0 = (n-1)%26
        do{
            r += char((n-1) % 26 + 'A');
            n = (n-1)/26; // minus 1 needed.
        } while (n);
        return string(r.rbegin(), r.rend());
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            int c = n % 26;
            if (!c) c = 26;
            s += 'A' + c - 1;
            n -= c;
            n /= 26;
        }
        return string(s.rbegin(), s.rend());
    }
};