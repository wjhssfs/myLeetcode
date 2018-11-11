// 935. Knight Dialer
// A chess knight can move as indicated in the chess diagram below:


// This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

// Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

// How many distinct numbers can you dial in this manner?

// Since the answer may be large, output the answer modulo 10^9 + 7.

 

// Example 1:

// Input: 1
// Output: 10
// Example 2:

// Input: 2
// Output: 20
// Example 3:

// Input: 3
// Output: 46
 

// Note:

// 1 <= N <= 5000

class Solution {
public:
    int knightDialer(int N) {
        int mod = 1e9 + 7;
        vector<vector<int>> nextStep = {{4, 6},
                                        {6, 8}, {7, 9}, {4, 8}, 
                                        {0, 3, 9}, {}, {0, 1, 7},
                                        {2, 6}, {1, 3}, {2, 4}};
        vector<int> dp(10, 1);
        for (int i = 0; i < N - 1; ++i) {
            auto newDP = vector<int>(10, 0);
            for (int j = 0; j <= 9; ++j) {
                for (auto c : nextStep[j]) {
                    newDP[c] = ((long long)dp[j] + newDP[c]) % mod;
                }
            }
            swap(dp, newDP);
        }
        long long res = 0;
        for (int i = 0; i <= 9; ++i) {
            res = (res + dp[i]) % mod;
        }
        return res;
    }
};

// https://math.stackexchange.com/questions/1890620/finding-path-lengths-by-the-power-of-adjacency-matrix-of-an-undirected-graph
// The power of matrix reveals the number of walks in an undirected graph.
    def knightDialer(self, N):
        mod = 10**9 + 7
        if N == 1: return 10
        M = np.matrix([[0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
                       [0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
                       [0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
                       [0, 0, 0, 0, 1, 0, 0, 0, 1, 0],
                       [1, 0, 0, 1, 0, 0, 0, 0, 0, 1],
                       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                       [1, 1, 0, 0, 0, 0, 0, 1, 0, 0],
                       [0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
                       [0, 1, 0, 1, 0, 0, 0, 0, 0, 0],
                       [0, 0, 1, 0, 1, 0, 0, 0, 0, 0]])
        res, N = 1, N - 1
        while N:
            if N % 2: res = res * M % mod
            M = M * M % mod
            N /= 2
        return int(np.sum(res)) % mod