// 247 Strobogrammatic Number II
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// Find all strobogrammatic numbers that are of length = n.
// For example,
// Given n = 2, return ["11","69","88","96"].
// Hint:
// Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        result.clear();
        if(n <= 0) return result;
        string num(n,'0');
        recursiveFind(num, 0, n);
        return result;
    }
private:
    void recursiveFind(string &num, int start, int n){
        if(n == 1){
            if(start || num.size() == 1) {
                num[start] = '0'; result.emplace_back(num);
            }
            num[start] = '1'; result.emplace_back(num);
            num[start] = '8'; result.emplace_back(num);
        } else if (n == 0) {
            result.emplace_back(num);
        } else {
            if(start){
                num[start] = num[num.size() -1 - start] = '0'; recursiveFind(num, start+1, n -2);
            }
            num[start] = num[num.size() -1 - start] = '1'; recursiveFind(num, start+1, n -2);
            num[start] = '6'; num[num.size() -1 - start] = '9'; recursiveFind(num, start+1, n -2);
            num[start] = num[num.size() -1 - start] = '8'; recursiveFind(num, start+1, n -2);
            num[start] = '9'; num[num.size() -1 - start] = '6'; recursiveFind(num, start+1, n -2);
        }
    }
    
    vector<string> result;
};