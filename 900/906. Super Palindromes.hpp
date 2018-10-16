// 906. Super Palindromes

// Let's say a positive integer is a superpalindrome if it is a palindrome, and it is also the square of a palindrome.

// Now, given two positive integers L and R (represented as strings), return the number of superpalindromes in the inclusive range [L, R].

 

// Example 1:

// Input: L = "4", R = "1000"
// Output: 4
// Explanation: 4, 9, 121, and 484 are superpalindromes.
// Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
 

// Note:

// 1 <= len(L) <= 18
// 1 <= len(R) <= 18
// L and R are strings representing integers in the range [1, 10^18).
// int(L) <= int(R)

class Solution {
    vector<long> GenP(int n) {
        string buf(n, '0');
        vector<long> res;
        dfs(res, buf, 0, n - 1);
        return res;
    }
    void dfs(vector<long>& res, string& buf, int left, int right) {
        if (left > right) {res.push_back(stol(buf)); return;}
        for (int i = 0; i < 10; ++i) {
            if (i == 0 && left == 0 && right != 0) continue;
            buf[left] = buf[right] = '0' + i;
            dfs(res, buf, left + 1, right - 1);
        }
    }
    bool isPalindrome(string& str) {
        for(int l = 0, r = str.size() - 1; l < r; ++l, --r) if (str[l] != str[r]) return false;
        return true;
    }
public:
    int superpalindromesInRange(string L, string R) {
        long l = stol(L), r = stol(R);
        int szL = to_string((long)sqrt(l)).size(), szR = to_string((long)sqrt(r)).size();
        //cout << szL << " " << szR << endl;
        int res = 0;
        for (int i = szL; i <= szR; ++i) {
            //cout << i << endl;
            auto roots = GenP(i);
            for (auto root : roots) {
                long sq = root * root;
                //cout << root << " sq " << sq << endl;
                if (sq < l || sq > r) continue;
                auto str = to_string(sq);
                if (isPalindrome(str)) ++res;
                //cout << "P " << str << endl;
            }
        }
        return res;
    }
};