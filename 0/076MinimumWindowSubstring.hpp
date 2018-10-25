// 76 Minimum Window Substring 
// Given a string S and a string T, find the minimum window in S which will contain all
// the characters in T in complexity O(n). 
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
// Note:
// If there is no such window in S that covers all characters in T, return the emtpy string "".
// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

/*
Solution: Use two pointers: start and end. 
              First, move 'end'. After finding all the needed characters, move 'start'.
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

// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }

// Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int counter=0, begin=0, end=0, d=0; 
        while(end<s.size()){
            if(map[s[end++]]++>0) counter++; 
            while(counter>0) if(map[s[begin++]]-->1) counter--;
            d=max(d, end-begin); //while valid, update d
        }
        return d;
    }

// Longest Substring with At Most Two Distinct Characters
int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> map(128, 0);
        int counter=0, begin=0, end=0, d=0; 
        while(end<s.size()){
            if(map[s[end++]]++==0) counter++;
            while(counter>2) if(map[s[begin++]]--==1) counter--;
            d=max(d, end-begin);
        }
        return d;
    }

    
string minWindow(string s, string t) {
    unordered_map<char, int> m;
    // Statistic for count of char in t
    for (auto c : t) m[c]++;
    // counter represents the number of chars of t to be found in s.
    size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
    size_t size = s.size();

    // Move end to find a valid window.
    while (end < size) {
        // If char in s exists in t, decrease counter
        if (m[s[end]] > 0)
            counter--;
        // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
        m[s[end]]--;
        end++;
        // When we found a valid window, move start to find smaller window.
        while (counter == 0) {
            if (end - start < minLen) {
                minStart = start;
                minLen = end - start;
            }
            m[s[start]]++;
            // When char exists in t, increase counter.
            if (m[s[start]] > 0)
                counter++;
            start++;
        }
    }
    if (minLen != INT_MAX)
        return s.substr(minStart, minLen);
    return "";
}
