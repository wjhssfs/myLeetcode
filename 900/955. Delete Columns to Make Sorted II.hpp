// 955. Delete Columns to Make Sorted II

// We are given an array A of N lowercase letter strings, all of the same length.

// Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

// For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef","vyz"].

// Suppose we chose a set of deletion indices D such that after deletions, the final array has its elements in lexicographic order (A[0] <= A[1] <= A[2] ... <= A[A.length - 1]).

// Return the minimum possible value of D.length.

 

// Example 1:

// Input: ["ca","bb","ac"]
// Output: 1
// Explanation: 
// After deleting the first column, A = ["a", "b", "c"].
// Now A is in lexicographic order (ie. A[0] <= A[1] <= A[2]).
// We require at least 1 deletion since initially A was not in lexicographic order, so the answer is 1.
// Example 2:

// Input: ["xc","yb","za"]
// Output: 0
// Explanation: 
// A is already in lexicographic order, so we don't need to delete anything.
// Note that the rows of A are not necessarily in lexicographic order:
// ie. it is NOT necessarily true that (A[0][0] <= A[0][1] <= ...)
// Example 3:

// Input: ["zyx","wvu","tsr"]
// Output: 3
// Explanation: 
// We have to delete every column.
 

// Note:

// 1 <= A.length <= 100
// 1 <= A[i].length <= 100

// sorted[i] = true if and only if A[i] < A[i + 1],
 int minDeletionSize(vector<string>& A) {
        int res = 0, n = A.size(), m = A[0].length(), i, j;
        vector<bool> sorted(n - 1, false);
        for (j = 0; j < m; ++j) {
            for (i = 0; i < n - 1; ++i) {
                if (!sorted[i] && A[i][j] > A[i + 1][j]) {
                    res++;
                    break;
                }
            }
            if (i < n - 1) continue;
            for (i = 0; i < n - 1; ++i)
                if (A[i][j] < A[i + 1][j])
                    sorted[i] = true;
        }
        return res;
    }

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.size() < 2) return 0;
        unordered_set<int> deletedCol;
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                if (deletedCol.count(j)) continue;
                if (A[i][j] < A[i-1][j]) {
                    deletedCol.insert(j);
                    i = 0;
                    break;
                } else if (A[i][j] > A[i-1][j]) break;
            }
        }
        return deletedCol.size();;
    }
};