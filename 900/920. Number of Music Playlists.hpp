// 920. Number of Music Playlists

// Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.  You create a playlist so that:

// Every song is played at least once
// A song can only be played again only if K other songs have been played
// Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.

 

// Example 1:

// Input: N = 3, L = 3, K = 1
// Output: 6
// Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
// Example 2:

// Input: N = 2, L = 3, K = 0
// Output: 6
// Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
// Example 3:

// Input: N = 2, L = 3, K = 1
// Output: 2
// Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
 

// Note:

// 0 <= K < N <= L <= 100

class Solution {
public:
   int numMusicPlaylists(int N, int L, int K) {
   	// dp[i][j] length i and exactly j unique songs
        long dp[L + 1][N + 1] = {}, mod = 1e9 + 7;
        dp[0][0] = 1;
        for (int i = 1; i <= L; ++i)
            for (int j = 1; j <= N; ++j) {
                dp[i][j] += dp[i-1][j-1] * (N-j+1);
                dp[i][j] += dp[i-1][j] * max(j-K, 0);
                dp[i][j] %= mod;
            }
        return (int) dp[L][N];
    }
};

class Solution {
public:
   int numMusicPlaylists(int N, int L, int K) {
        long dp[N + 1][L + 1], mod = 1e9 + 7;
        for (int i = K + 1; i <= N; ++i)
            for (int j = i; j <= L; ++j)
                if ((i == j) || (i == K + 1))
                // If N == L, every song is played at least once, then the result equals to the number of permutation of N music.
				// If N == K + 1, then we need to repeat the N first music, still the result equals to the number of permutation of N music.
                    dp[i][j] = factorial(i);
                else
                    dp[i][j] = (dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - K))  % mod;
        return (int) dp[N][L];
    }

    long factorial(int n) {
        return n ? factorial(n - 1) * n % (long)(1e9 + 7) : 1;
    }
};