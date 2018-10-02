// 854. K-Similar Strings

// Strings A and B are K-similar (for some non-negative integer K) if we can swap the positions of two letters in A exactly K times so that the resulting string equals B.

// Given two anagrams A and B, return the smallest K for which A and B are K-similar.

// Example 1:

// Input: A = "ab", B = "ba"
// Output: 1
// Example 2:

// Input: A = "abc", B = "bca"
// Output: 2
// Example 3:

// Input: A = "abac", B = "baca"
// Output: 2
// Example 4:

// Input: A = "aabc", B = "abca"
// Output: 2
// Note:

// 1 <= A.length == B.length <= 20
// A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}

class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A == B) return 0;
        int res = 0;
        queue<string> q;
        unordered_set<string> m;
        q.push(A);
        m.insert(A);
        while (!q.empty()) {
            res++;
            for (int i = q.size(); i > 0; --i) {
                auto c = q.front(); q.pop();
                int ai = 0;
                while (c[ai] == B[ai]) ++ai;
                for (int bi = ai + 1; bi < B.size(); ++bi) {
                    if (A[bi] == B[bi] || c[ai] != B[bi]) continue;
                    auto t = c;
                    swap(t[ai], t[bi]);
                    if (t == B) return res;
                    if (!m.count(t)) {
                        m.insert(t);
                        q.push(t);
                    }
                }
                
            }
        }
        return res;
    }
};


// Let n be the size of anagrams, at most n (actually n-1) swaps would make them identical.
// In the optimal strategy, each swap should contribute to at least 1 match of characters. 
// We also note the best we can achieve in a single swap is 2 matches, which is guaranteed
// to be optimal (although it might not be the only one). Therefore, if A[i]!=B[i], we should
// try our luck and look for a position j, such that A[j]==B[i] && A[i]==B[j], if one is found,
// then we achieve a optimal double match and proceed to match the remaining. Otherwise, we look
// for a position j, such that A[j]==B[i], and MAKE SURE IT IS NOT A MATCH ALREADY (i.e., A[j]!=B[j],
// otherwise you simply push the mismatch in position i to position j and don't make any real progress).
// There might be multiple positions j satisfying such condition, and we need to go over each one of them,
// as certain j might give rise to a double match later on, and therefore outperform others.
class Solution {
public:
    int kSimilarity(string A, string B) {
      for (int i=0; i<A.size(); i++) {
        if (A[i]==B[i]) continue;
        vector<int> matches;
        for (int j=i+1;j<A.size();j++) { 
          if (A[j]==B[i] && A[j]!=B[j]) {
            matches.push_back(j);
            if (A[i]==B[j]) {
              swap(A[i],A[j]);
              return 1+kSimilarity(A.substr(i+1),B.substr(i+1));
            }
          }
        }
        int best=A.size()-1;
        for (int j: matches) {
            swap(A[i],A[j]);
            best = min(best, 1+kSimilarity(A.substr(i+1),B.substr(i+1)));
            swap(A[i],A[j]);
        }
        return best;
      }
      return 0;
    }
};

// should be able to get result by getting size of swap loops