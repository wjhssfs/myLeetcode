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

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if (n <= 0) return {};
       return helper(n, n);
    }
private:
    vector<string> helper(int left, int total) {
        if (left == 0) return {""};
        if (left == 1) return {"0", "1", "8"};
        
        auto subRes = helper(left - 2, total);
        vector<string> res;
        for (auto r : subRes) {
            if (left != total) res.emplace_back("0" + r + "0");
            res.emplace_back("1" + r + "1");
            res.emplace_back("6" + r + "9");
            res.emplace_back("8" + r + "8");
            res.emplace_back("9" + r + "6");
        }
        return res;
    }
};