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

class Solution2 {
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

class Solution {
public:
    string convertToTitle(int n) {
        string r;
        if (n <= 0) return r;
        do{
            n--; // become 0 based
            r += char(n % 26 + 'A');
            n /= 26;
        } while (n);
        return string(r.rbegin(), r.rend());
    }
};