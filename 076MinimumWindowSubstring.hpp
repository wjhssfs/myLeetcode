// 76 Minimum Window Substring 
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
// 
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
// 
// Note:
// If there is no such window in S that covers all characters in T, return the emtpy string "".
// 
// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

class Solution {
public:
	string minWindow(string S, string T) {
		int tsz = T.size(), ssz = S.size();
		unordered_map<char, int> m;
		for (int i = 0; i < tsz; i++){
			m[T[i]]++;
		}
		int start = 0, end = 0, t = 0, maxLen = INT_MAX, fstart = 0, fend = 0;
		while (start < ssz && !m.count(S[start]))start++;
		end = start;
		while (start <= end && end < ssz){
			while (t != tsz && end<ssz){
				if (m.count(S[end])){
					if (m[S[end]]>0) t++;
					m[S[end]]--;
				}
				end++;
			}
			if (t == tsz){
				if (end - start < maxLen){
					fend = end;
					fstart = start;
					maxLen = end - start;
				}
				m[S[start]]++;
				if (m[S[start]] >0) t--;
				start++;
				while (start < end && (m.count(S[start]) == 0 || m[S[start]] < 0)){
					if (m.count(S[start]))m[S[start]]++;
					start++;
				}
				if (t==tsz && start < end && end - start < maxLen){
					fend = end;
					fstart = start;
					maxLen = end - start;
				}
			}
		}
		return S.substr(fstart, fend - fstart);
	}
};

/*
Solution: 1. Use two pointers: start and end. 
              First, move 'end'. After finding all the needed characters, move 'start'.
           2. Use array as hashtable.
 */

class Solution {
public:
    string minWindow(string S, string T) {
        int N = S.size(), M = T.size();
        if (N < M) return "";
        int need[256] = {0};
        int find[256] = {0};
        for (int i = 0; i < M; ++i)
            need[T[i]]++;

        int count = 0, resStart = -1, resEnd = N;
        for (int start = 0, end = 0; end < N; ++end)
        {
            if (need[S[end]] == 0)
                continue;
            if (find[S[end]] < need[S[end]])
                count++;
            find[S[end]]++;
            if (count != M) continue;
            // move 'start'
            for (; start < end; ++start) {
                if (need[S[start]] == 0) continue;
                if (find[S[start]] <= need[S[start]]) break;
                find[S[start]]--;
            }
            // update result
            if (end - start < resEnd - resStart) {
                resStart = start;
                resEnd = end;
            }
        }
        return (resStart == -1) ? "" : S.substr(resStart, resEnd - resStart + 1);
    }
};
