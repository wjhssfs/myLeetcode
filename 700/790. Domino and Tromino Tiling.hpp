// 790. Domino and Tromino Tiling

// We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.

// XX  <- domino

// XX  <- "L" tromino
// X
// Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.

// (In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)

// Example:
// Input: 3
// Output: 5
// Explanation: 
// The five different ways are listed below, different letters indicates different tiles:
// XYZ XXZ XYY XXY XYY
// XYZ YYZ XZZ XYY XXY
// Note:

// N  will be in range [1, 1000].

class Solution {
    void modAdd(int& x, int y)
    {
        const int mod = 1000000007;
        x += y;
        x %= mod;
    }
public:
    int numTilings(int N) {
            vector<vector<int>> dp(N + 2, vector<int>(3));
        dp[1] = {1, 0, 0};
        for (int i = 2; i <= N + 1; ++i) {
            modAdd(dp[i][0], dp[i-2][0]);
            modAdd(dp[i][0], dp[i-1][0]);
            modAdd(dp[i][0], dp[i-1][1]);
            modAdd(dp[i][0], dp[i-1][2]);
            modAdd(dp[i][1], dp[i-2][0]);
            modAdd(dp[i][1], dp[i-1][2]);
            modAdd(dp[i][2], dp[i-2][0]);
            modAdd(dp[i][2], dp[i-1][1]);
        }
        return dp[N + 1][0];
    }
};

// https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116581/Detail-and-explanation-of-O(n)-solution-why-dpn2*dn-1+dpn-3
 int numTilings(int N) {
    int md=1e9 + 7;
    vector<long long> v(1001,0);
    v[1]=1;
    v[2]=2;
    v[3]=5;
    if(N<=3)
        return v[N];
    for(int i=4;i<=N;++i){
        v[i]=2*v[i-1]+v[i-3]; 
        v[i]%=md;
    }
    return v[N];
    
}