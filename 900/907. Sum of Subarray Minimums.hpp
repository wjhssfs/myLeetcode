// 907. Sum of Subarray Minimums
// Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

// Since the answer may be large, return the answer modulo 10^9 + 7.

 

// Example 1:

// Input: [3,1,2,4]
// Output: 17
// Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

// Note:

// 1 <= A.length <= 30000
// 1 <= A[i] <= 30000

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<long> s;
        A.push_back(0);
        long mod = 1e9 + 7, res = 0;
        for (long i = 0; i < A.size(); ++i) {
            if (s.empty() || A[i] > A[s.top()]) {s.push(i); continue;};
            while (!s.empty() && A[i] < A[s.top()]) {
                long c = s.top(); s.pop();
                long left = c - (s.empty() ? -1 : s.top());
                res = (res + (i - c) * left * A[c]) % mod;
            }
            s.push(i);
        }
        return res;
    }
};

// https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/C++JavaPython-Stack-Solution
    int sumSubarrayMins(vector<int> A) {
        int res = 0, n = A.size(), mod = 1e9 + 7, j, k;
        stack<int> s;
        // avoid push to A
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && A[s.top()] > (i == n ? 0 : A[i])) {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();
                res = (res + A[j] * (i - j) * (j - k)) % mod;
            }
            s.push(i);
        }
        return res;
    }
901. Online Stock Span
828. Unique Letter String
891. Sum of Subsequence Widths