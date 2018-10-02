// 5 Longest Palindromic Substring 
// Given a string S, find the longest palindromic substring in S. You may assume that the maximum length
// of S is 1000, and there exists one unique longest palindromic substring.

class Solution {
public:
	string longestPalindrome(string s) {
		if (!s.size()) return "";
		int start = -1, longestLen = -1;
		for (int i = 0; i < s.size(); i++){
			int len = 1;
			while (i - len >= 0 && i + len < s.size()){
				if (s[i - len] == s[i + len]) len++;
				else break;
			}
			if (longestLen < len * 2 - 1){
				longestLen = len * 2 - 1;
				start = i - len + 1;
			}
		}
		for (int i = 0; i < s.size()-1; i++){
			if (s[i] != s[i + 1]) continue;
			int len = 1;
			while (i - len >= 0 && i + 1 + len < s.size()){
				if (s[i - len] == s[i + len + 1]) len++;
				else break;
			}
			if (longestLen < len * 2){
				longestLen = len * 2;
				start = i - len + 1;
			}
		}
		return s.substr(start, longestLen);
	}
};

// Time O(n), Space O(n) (Manacher's Algorithm)
class Solution2 {
public:
	string longestPalindrome(string s) {
		int osz = s.size();
		if (osz < 2) return s;
		string t(osz + osz + 1, '#');
		for (size_t i = 0; i != s.size(); i++)t[i * 2+1] = s[i];
		vector<int>p(t.size());

		int C = 1, R = 1;
		while (R < t.size()){
			if (R == C){
				while (C+C-R-1 >= 0 && R+1 < t.size() && t[C +C-R-1] == t[R+1]) R++;
				p[C] = R-C;
			}
			while (C < R){
				for (int j = 1; j <= R - C; j++){
					if (p[C - j] + (C + j) >= R){
						C = C + j;
						while (C+C-R -1 >= 0 && R+1 < t.size() && t[C +C -R- 1] == t[R+1]) R++;
						p[C] = R-C;
						break;
					}
					else p[C + j] = p[C - j];
				}
			}
			C = R = R + 1;
		}

		int lenM = 0, start = -1;
		for (int i = 0; i < t.size(); i++){
			if (p[i] > lenM){
				lenM = p[i];
				start = i;
			}
		}

		string result = s.substr(start / 2 - lenM / 2, lenM);
		return result;
	}
};

/*
Solution: 1. Time O(n^2), Space O(n^2)
           2. Time O(n^2), Space O(n)
           3. Time O(n^2), Space O(1) (actually much more efficient than 1 & 2)
 */

class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindrome_4(s);
    }
    string longestPalindrome_1(string s) {
        int N = s.size();
        bool dp[N][N];
        pair<int, int> res = make_pair(0, 0); // start pos and length
        for (int k = 0; k < N; ++k) // length
        {
            for (int i = 0; i < N-k; ++i) // start pos
            {
                if (k == 0 || k == 1) 
                    dp[i][i+k] = s[i] == s[i+k];
                else 
                    dp[i][i+k] = (s[i] == s[i+k]) ? dp[i+1][i+k-1] : false;
                
                if (dp[i][i+k] && k+1 > res.second)
                    res = make_pair(i, k+1);
            }
        }
        return s.substr(res.first, res.second);
    }

    string longestPalindrome_2(string s) {
        int N = s.size();
        bool dp[2][N];
        pair<int, int> res = make_pair(0, 0);
        int cur = 1, last = 0;
        for (int i = 0; i < N; ++i)
        {
            cur = !cur; last = !last;
            for (int j = i; j >= 0; --j)
            {
                if (j == i || j == i-1)
                    dp[cur][j] = s[j] == s[i];
                else
                    dp[cur][j] = s[j] == s[i] && dp[last][j+1];

                if (dp[cur][j] && i-j+1 > res.second)
                    res = make_pair(j, i-j+1);
            }
        }
        return s.substr(res.first, res.second);
    }

    string longestPalindrome_3(string s) {
        int N = s.size();
        pair<int, int> res = make_pair(0, 0); // start pos and length
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= 1; ++j) {
                bool isP = true;
                for (int k = 0; i-k >= 0 && i+k < N && isP; ++k) {
                    isP = s[i-k] == s[i+j+k];
                    if (isP && j+1+k*2 > res.second)
                        res = make_pair(i-k, j+1+k*2);
                }
            }
        }
        return s.substr(res.first, res.second);
    }
};

string longestPalindrome(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}