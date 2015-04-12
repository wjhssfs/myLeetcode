// 93 Restore IP Addresses
// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
// 
// For example:
// Given "25525511135",
// 
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int i, j, k;
        for (i = 1; i <= 3 && i + 3 <= s.size(); i++){
            if (i > 1 && s[0] == '0') break;
            if (i == 3 && !lessThen(&s[0])) break;
            for (j = 1; j <= 3 && i+j +2 <= s.size(); j++){
                if (j>1 && s[i] == '0') break;
                if (j == 3 && !lessThen(&s[i])) break;
                for (k = 1; k <= 3&&i+j+k + 1 <= s.size(); k++){
                    if (k>1 && s[i + j] == '0') break;
                    if (k == 3 && !lessThen(&s[i + j])) break;
                    if (i + j + k +3 < s.size()) continue;
                    if (i + j + k + 1 < s.size() && s[i + j + k] == '0') continue;
                    if (i + j + k + 3 == s.size() && !lessThen(&s[i + j + k])) continue;
                    result.push_back(s.substr(0, i) + "." + s.substr(i, j) + "." +
                        s.substr(i + j, k) + "." + s.substr(i + j + k));
                }
            }
        }
        return result;
    }
private:
    bool lessThen(char *s){
        return (*s - '0') * 100 + (*(s + 1) - '0') * 10 + *(s + 2) - '0' < 256;
    }
};

class Solution2 {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        restoreIpAddressRe(s, res, ip, 0, 0);
        return res;
    }
    
    void restoreIpAddressRe(string &s, vector<string> &res, string &ip, int deep, int start)
    {
        if (deep == 4 && start == s.size())
            res.push_back(ip);
        if (deep == 4) return;
        
        int num = 0, origSize = ip.size();
        if (origSize != 0) ip.push_back('.');
        for (int i = start; i < s.size(); ++i)
        {
            num = num * 10 + s[i] - '0';
            if (num > 255) break;
            ip.push_back(s[i]);
            restoreIpAddressRe(s, res, ip, deep + 1, i + 1);
            if (num == 0) break;
        }
        ip.resize(origSize);
    }
};