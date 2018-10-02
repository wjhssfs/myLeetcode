// 839. Similar String Groups

// Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.

// For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

// Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

// We are given a list A of strings.  Every string in A is an anagram of every other string in A.  How many groups are there?

// Example 1:

// Input: ["tars","rats","arts","star"]
// Output: 2
// Note:

// A.length <= 2000
// A[i].length <= 1000
// A.length * A[i].length <= 20000
// All words in A consist of lowercase letters only.
// All words in A have the same length and are anagrams of each other.
// The judging time limit has been increased for this question.


class Solution {
    int find(int i, vector<int> &p) {
        if (p[i] == -1) return i;
        p[i] = find(p[i], p);
        return p[i];
    }
    void join(int i, int j, vector<int> &p) {
        int pi = find(i, p);
        int pj = find(j, p);
        if (pi != pj) p[pi] = pj;
    }
    bool similar(string &a, string &b) {
        int n = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i] && ++n > 2)
                return false;
        return true;
    }
public:
    int numSimilarGroups(vector<string>& A) {
        vector<int> p(A.size(), -1);
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                if (similar(A[i], A[j])) join(i, j, p);
            }
        }
        int r = count(p.begin(), p.end(), -1);
        return r;
    }
};