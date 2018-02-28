// 784. Letter Case Permutation
// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]
// Note:

// S will be a string with length at most 12.
// S will consist only of letters or digits.

class Solution {
    void dfs(string& S, int start, vector<string>& res) {
        while (start < S.size() && isdigit(S[start])) ++start;
        if (start == S.size()) {
            res.push_back(S);
            return;
        }
        dfs(S, start + 1, res);
        char c = S[start];
        if (islower(c)) S[start] = toupper(S[start]);
        else S[start] = tolower(S[start]);
        dfs(S, start + 1, res);
        S[start] = c;
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        dfs(S, 0, res);
        return res;
    }
};

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res(1);
        for (int i = 0; i < S.size(); ++i) {
            for (int j = 0; j < res.size(); ++j) {
                res[j] += S[i];
            }
            if (isdigit(S[i])) continue;
            char c = islower(S[i]) ? toupper(S[i]) : tolower(S[i]);
            int curSize = res.size();
            for (int j = 0; j < curSize; ++j) {
                res.push_back(res[j]);
                res.back().back() = c;
            }
        }
        return res;
    }
};