// 823. Binary Trees With Factors
// Given an array of unique integers, each integer is strictly greater than 1.

// We make a binary tree using these integers and each number may be used for any number of times.

// Each non-leaf node's value should be equal to the product of the values of it's children.

// How many binary trees can we make?  Return the answer modulo 10 ** 9 + 7.

// Example 1:

// Input: A = [2, 4]
// Output: 3
// Explanation: We can make these trees: [2], [4], [4, 2, 2]
// Example 2:

// Input: A = [2, 4, 5, 10]
// Output: 7
// Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 

// Note:

// 1 <= A.length <= 1000.
// 2 <= A[i] <= 10 ^ 9.


class Solution {
    const static long long MOD = 1000000007;
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_map<int, long long> m;
        int result = 0;
        for (int i = 0; i < A.size(); ++i) {
            m[A[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0 && m.count(A[i] / A[j]) > 0) {
                    m[A[i]] += (m[A[j]] * m[A[i] / A[j]]) % MOD;
                    m[A[i]] %= MOD;
                }
            }
            result += m[A[i]];
            result %= MOD;
        }
        return result;
    }
};

    int numFactoredBinarydps(vector<int>& A) {
        long res = 0, mod = pow(10, 9) + 7;
        sort(A.begin(), A.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j)
                if (A[i] % A[j] == 0 && dp.count(A[i] / A[j]) == 1)
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
        }
        for (auto &it : dp) res = (res + it.second) % mod;
        return res;
    }