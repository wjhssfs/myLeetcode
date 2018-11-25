// 844. Backspace String Compare
// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

// Example 1:

// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:

// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:

// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:

// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:

// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// Follow up:

// Can you solve it in O(N) time and O(1) space?

class Solution {
    char getNext(const string &s, int &i) {
        int b = 1;
        while (i >= 0 && b) (s[i--] == '#') ? ++b : --b;
        return b ? 'X' : s[i + 1];
    }
public:
    bool backspaceCompare(string S, string T) {
        int s = S.size() - 1, t = T.size() - 1;
        while (getNext(S, s) == getNext(T, t)) {
            if (s == -1 && t == -1) return true;
        }
        return false;
    }
};

bool backspaceCompare(string S, string T) {
    for (int i = S.length() - 1, j = T.length() - 1;;i--, j--){
        for (int b = 0; i >= 0 && (b || S[i] == '#'); --i) b += S[i] == '#' ? 1 : -1;
        for (int b = 0; j >= 0 && (b || T[j] == '#'); --j) b += T[j] == '#' ? 1 : -1;
        if (i < 0 || j < 0 || S[i] != T[j]) return i == -1 && j == -1;
    }
}