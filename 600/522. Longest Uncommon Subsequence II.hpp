// 522. Longest Uncommon Subsequence II

// Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

// A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

// The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

// Example 1:
// Input: "aba", "cdc", "eae"
// Output: 3
// Note:

// All the given strings' lengths will not exceed 10.
// The length of the given list will be in the range of [2, 50].


class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        for (int i = 0; i < strs.size(); ++i) {
            bool isCandidate = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (i == j) continue;
                if (isSubSequenceOf(strs[i], strs[j])) {
                    isCandidate = false;
                }
            }
            if (isCandidate) maxLen = max(maxLen,(int)strs[i].size());
        }
        return maxLen;
    }
private:
    bool isSubSequenceOf(string &a, string &b) {
        if (a.size() > b.size()) return false;
        int i = 0, j = 0;
        while (i != a.size()) {
            if (j == b.size()) return false;
            if (a[i] == b[j]) { ++i; ++j;}
            else ++j;
        }
        return true;
    }
};

def subseq(w1, w2):
    #True iff word1 is a subsequence of word2.
    i = 0
    for c in w2:
        if i < len(w1) and w1[i] == c:
            i += 1
    return i == len(w1)
    
A.sort(key = len, reverse = True)
for i, word1 in enumerate(A):
    if all(not subseq(word1, word2) 
            for j, word2 in enumerate(A) if i != j):
        return len(word1)
return -1