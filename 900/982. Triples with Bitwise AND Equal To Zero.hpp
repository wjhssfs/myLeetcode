// 982. Triples with Bitwise AND Equal To Zero
// Given an array of integers A, find the number of triples of indices (i, j, k) such that:

// 0 <= i < A.length
// 0 <= j < A.length
// 0 <= k < A.length
// A[i] & A[j] & A[k] == 0, where & represents the bitwise-AND operator.
 

// Example 1:

// Input: [2,1,3]
// Output: 12
// Explanation: We could choose the following i, j, k triples:
// (i=0, j=0, k=1) : 2 & 2 & 1
// (i=0, j=1, k=0) : 2 & 1 & 2
// (i=0, j=1, k=1) : 2 & 1 & 1
// (i=0, j=1, k=2) : 2 & 1 & 3
// (i=0, j=2, k=1) : 2 & 3 & 1
// (i=1, j=0, k=0) : 1 & 2 & 2
// (i=1, j=0, k=1) : 1 & 2 & 1
// (i=1, j=0, k=2) : 1 & 2 & 3
// (i=1, j=1, k=0) : 1 & 1 & 2
// (i=1, j=2, k=0) : 1 & 3 & 2
// (i=2, j=0, k=1) : 3 & 2 & 1
// (i=2, j=1, k=0) : 3 & 1 & 2
 

// Note:

// 1 <= A.length <= 1000
// 0 <= A[i] < 2^16

// Tricky:
// We initialize the dp[(1<<16) - 1] to 1 because the AND result of every number with (1<<16) - 1 is the number itself.

// https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/discuss/226778/C++-20-lines56msenumerate-with-memory-(with-Chinese-translation)
// https://www.acwing.com/solution/leetcode/content/876/
class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size(), ans = 0;
        vector<int> f(1 << 16, -1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int x = A[i] & A[j];
                if (f[x] == -1) {
                    f[x] = 0;
                    for (int k = 0; k < n; k++)
                        if ((x & A[k]) == 0)
                            f[x]++;
                }
                ans += f[x];
            }

        return ans;
    }
};

// DP 
class Solution {
public:
    int countTriplets(vector<int>& A) {
        int N = 1 << 16;
        auto dp = vector<int>(N);
        dp[N - 1] = 1;
        for (int i = 0; i < 3; i++) {
            auto temp = vector<int>(N);
            for (int k = 0; k < N; k++) {
                for (int a : A) {
                    temp[k & a] += dp[k];
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};
