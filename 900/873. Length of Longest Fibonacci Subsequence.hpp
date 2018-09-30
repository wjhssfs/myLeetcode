// 873. Length of Longest Fibonacci Subsequence

// A sequence X_1, X_2, ..., X_n is fibonacci-like if:

// n >= 3
// X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
// Given a strictly increasing array A of positive integers forming a sequence, find the length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.

// (Recall that a subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)

 

// Example 1:

// Input: [1,2,3,4,5,6,7,8]
// Output: 5
// Explanation:
// The longest subsequence that is fibonacci-like: [1,2,3,5,8].
// Example 2:

// Input: [1,3,7,11,12,14,18]
// Output: 3
// Explanation:
// The longest subsequence that is fibonacci-like:
// [1,11,12], [3,11,14] or [7,11,18].
 

// Note:

// 3 <= A.length <= 1000
// 1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                int  a = A[i], b = A[j], l = 2;
                while (s.count(a + b))
                    b = a + b, a = b - a, l++;
                res = max(res, l);
            }
        }
        return res > 2 ? res : 0;
    }
};

    int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int, int> m;
        int N = A.size(), res = 0;
        int dp[N][N];
        for (int j = 0; j < N; ++j) {
            m[A[j]] = j;
            for (int i = 0; i < j; ++i) {
                int k = m.find(A[j] - A[i]) == m.end() ? -1 : m[A[j] - A[i]];
                dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? dp[k][i] + 1 : 2;
                res = max(res, dp[i][j]);
            }
        }
        return res > 2 ? res : 0;
    }

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        vector<vector<int>> d;
        unordered_map<int, unordered_set<int>> m;
        int maxL = 0; 
        for (int i = 1; i < A.size(); ++i) {
            //cout << A[i] << endl;
            auto s = m[A[i]];
            m[A[i]].clear();
            for (int n : s) {
                m[A[i] + d[n][1]].insert(n);
                d[n][1] = A[i];
                maxL = max(maxL, ++d[n][0]);
                //cout << "Add seq:" << n << " len:" << d[n][0] << endl;
            }
            for (int j = 0; j < i; ++j) {
                d.push_back({2, A[i]});
                int exp = A[i] + A[j];
                m[exp].insert(d.size() - 1);
                //cout << "Seq:" << d.size() << " Exp:" << exp << " i:" << i << " j:" << j << endl;
            }
        }
        return maxL;
    }
};