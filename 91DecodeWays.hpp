// 91 Decode Ways
// A message containing letters from A-Z is being encoded to numbers using the following mapping:
// 
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.
// 
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
// 
// The number of ways decoding "12" is 2.

class Solution {
public:
	int numDecodings(string s) {
		if (!s.size()|| s[0]=='0') return 0;
		vector<int> cache(s.size());
		cache[0] = 1;
		for (int i = 1; i <(int) s.size(); i++){
			if (i>1 && s[i] == '0' &&(s[i - 1] == '0' || s[i-1]-'0'>2)) return 0;
			if(s[i]!='0')cache[i] = cache[i - 1];
			if (s[i-1]!='0' &&((s[i - 1] - '0') * 10 + s[i] - '0' < 27)){
				cache[i] += i<2 ? 1 : cache[i - 2];
			}
		}
		return cache[s.size() - 1];
	}
};

class Solution2 {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') 
            return 0;
        int N = s.size();
        int dp[N+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < N; ++i)
        {
            if (s[i] == '0')
            {
                if (s[i-1] != '1' && s[i-1] != '2')
                    return 0;
                dp[i+1] = dp[i-1];
            }
            else
            {
                int num = s[i] - '0' + (s[i-1] - '0') * 10;
                if (num >= 11 && num <= 26)
                    dp[i+1] = dp[i] + dp[i-1];
                else
                    dp[i+1] = dp[i];
            }
        }
        return dp[N];
    }
};