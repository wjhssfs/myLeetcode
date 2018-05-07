// 821. Shortest Distance to a Character
// Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

// Example 1:

// Input: S = "loveleetcode", C = 'e'
// Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 

// Note:

// S string length is in [1, 10000].
// C is a single character, and guaranteed to be in string S.
// All letters in S and C are lowercase.

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> r(S.size(), INT_MAX);
        int cur = INT_MAX;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == C) cur = 0;
            else cur = cur == INT_MAX ? INT_MAX : cur + 1;
            r[i] = min(r[i], cur);
        }
        
        cur = INT_MAX;
        for (int i = S.size() - 1; i >= 0; --i) {
            if (S[i] == C) cur = 0;
            else cur = cur == INT_MAX ? INT_MAX : cur + 1;
            r[i] = min(r[i], cur);
        }
        
        return r;
    }
};