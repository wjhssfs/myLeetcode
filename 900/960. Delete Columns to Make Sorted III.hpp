// 960. Delete Columns to Make Sorted III
// We are given an array A of N lowercase letter strings, all of the same length.

// Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

// For example, if we have an array A = ["babca","bbazb"] and deletion indices {0, 1, 4}, then the final array after deletions is ["bc","az"].

// Suppose we chose a set of deletion indices D such that after deletions, the final array has every element (row) in lexicographic order.

// For clarity, A[0] is in lexicographic order (ie. A[0][0] <= A[0][1] <= ... <= A[0][A[0].length - 1]), A[1] is in lexicographic order (ie. A[1][0] <= A[1][1] <= ... <= A[1][A[1].length - 1]), and so on.

// Return the minimum possible value of D.length.

 

// Example 1:

// Input: ["babca","bbazb"]
// Output: 3
// Explanation: After deleting columns 0, 1, and 4, the final array is A = ["bc", "az"].
// Both these rows are individually in lexicographic order (ie. A[0][0] <= A[0][1] and A[1][0] <= A[1][1]).
// Note that A[0] > A[1] - the array A isn't necessarily in lexicographic order.
// Example 2:

// Input: ["edcba"]
// Output: 4
// Explanation: If we delete less than 4 columns, the only row won't be lexicographically sorted.
// Example 3:

// Input: ["ghi","def","abc"]
// Output: 0
// Explanation: All rows are already lexicographically sorted.
 

// Note:

// 1 <= A.length <= 100
// 1 <= A[i].length <= 100

// https://leetcode.com/problems/delete-columns-to-make-sorted-iii/discuss/205679/C++JavaPython-Maximum-Increasing-Subsequence

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size(), n = A[0].size(), res = n;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0, k; j < i; ++j) {
                for (k = 0; k < m; ++k) {
                    if (A[k][j] > A[k][i]) break;
                }
                if (k == m) dp[i] = max(dp[i], dp[j] + 1);
            }
            res = min(res, n - dp[i]);
        }
        return res;
    }
};