// 859. Buddy Strings
// Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.
 

// Example 1:

// Input: A = "ab", B = "ba"
// Output: true
// Example 2:

// Input: A = "ab", B = "ab"
// Output: false
// Example 3:

// Input: A = "aa", B = "aa"
// Output: true
// Example 4:

// Input: A = "aaaaaaabc", B = "aaaaaaacb"
// Output: true
// Example 5:

// Input: A = "", B = "aa"
// Output: false
 

// Note:

// 0 <= A.length <= 20000
// 0 <= B.length <= 20000
// A and B consist only of lowercase letters.

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        vector<int> diff;
        bool m[256] = {};
        bool hasDuplicate = false;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != B[i]) diff.push_back(i);
            if (m[A[i]]) hasDuplicate = true;
            m[A[i]] = true;
        }
        if (diff.size() == 0) return hasDuplicate;
        if (diff.size() != 2) return false;
        if (A[diff[0]] != B[diff[1]] || A[diff[1]] != B[diff[0]]) return false;
        return true;
    }
};

  bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) return false;
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size()) return true;
        vector<int> dif;
        for (int i = 0; i < A.length(); ++i) if (A[i] != B[i]) dif.push_back(i);
        return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
    }