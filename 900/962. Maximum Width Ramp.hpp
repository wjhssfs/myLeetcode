// 962. Maximum Width Ramp
// Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  The width of such a ramp is j - i.

// Find the maximum width of a ramp in A.  If one doesn't exist, return 0.

 

// Example 1:

// Input: [6,0,8,2,1,5]
// Output: 4
// Explanation: 
// The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.
// Example 2:

// Input: [9,8,1,0,1,9,4,0,4,1]
// Output: 7
// Explanation: 
// The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.
 

// Note:

// 2 <= A.length <= 50000
// 0 <= A[i] <= 50000
 // O(N)
 // Constructing a stack and popping it gradually
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i)
            if (s.empty() || A[s.top()] > A[i])
                s.push(i);
        for (int i = n - 1; i > res; --i)
            while (!s.empty() && A[s.top()] <= A[i])
                res = max(res, i - s.top()), s.pop();
        return res;
    }

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<int> decJ {0}, decN {A[0]};
        int res = 0;
        for (int j = 1; j < A.size(); ++j) {
            if (A[j] < decN.back()) {decJ.push_back(j); decN.push_back(A[j]);}
            else {
                auto it = lower_bound(begin(decN), end(decN), A[j], std::greater<int>());
                int i = decJ[it - begin(decN)];
                res = max(res, j - i);
            }
        }
        return res;
    }
};