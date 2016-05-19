// 93 Restore IP Addresses
// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
// For example:
// Given "25525511135",
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
class Solution {
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

public class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<String>();
        int len = s.length();
        for(int i = 1; i<4 && i<len-2; i++){
            for(int j = i+1; j<i+4 && j<len-1; j++){
                for(int k = j+1; k<j+4 && k<len; k++){
                    String s1 = s.substring(0,i), s2 = s.substring(i,j), s3 = s.substring(j,k), s4 = s.substring(k,len);
                    if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)){
                        res.add(s1+"."+s2+"."+s3+"."+s4);
                    }
                }
            }
        }
        return res;
    }
    public boolean isValid(String s){
        if(s.length()>3 || s.length()==0 || (s.charAt(0)=='0' && s.length()>1) || Integer.parseInt(s)>255)
            return false;
        return true;
    }
}