// 795. Number of Subarrays with Bounded Maximum
// We are given an array A of positive integers, and two positive integers L and R (L <= R).

// Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.

// Example :
// Input: 
// A = [2, 1, 4, 3]
// L = 2
// R = 3
// Output: 3
// Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
// Note:

// L, R  and A[i] will be an integer in the range [0, 10^9].
// The length of A will be in the range of [1, 50000].

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        stack<int> s;
        s.push(-1);
        int res = 0;
        int mod = 1000000007;
        for (int i = 0; i <= A.size(); ++i) {
            if (i == A.size() || A[i] > R) {
                while (s.size()) {
                    int t = s.top();
                    s.pop();
                    if (t == -1 || A[t] > R) break;
                    res += i - t;
                    res %= mod;
                    if (s.empty()) break;
                    int nt = s.top();
                    res += (i - t) * (t -nt - 1);
                    res %= mod;
                }
                s.push(i);
            } else if (A[i] >= L && A[i] <= R) s.push(i);
        }
        return res;
    }
};