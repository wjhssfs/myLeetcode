// 629. K Inverse Pairs Array

// Given two integers n and k, find how many different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs.

// We define an inverse pair as following: For ith and jth element in the array, if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's not.

// Since the answer may be very large, the answer should be modulo 109 + 7.

// Example 1:
// Input: n = 3, k = 0
// Output: 1
// Explanation: 
// Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.
// Example 2:
// Input: n = 3, k = 1
// Output: 2
// Explanation: 
// The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
// Note:
// The integer n is in the range [1, 1000] and k is in the range [0, 1000].

// dp[n][k] = dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...+dp[n-1][k+1-n+1]+dp[n-1][k-n+1]
// dp[n][k+1] = dp[n-1][k+1]+dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...+dp[n-1][k+1-n+1]
class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k > n * (n - 1) / 2 || k < 0) return 0;
        if (k == 0 || k == n * (n - 1) / 2) return 1;
        int mod = 1000000007;
        vector<vector<long>> m(n + 1, vector<long>(k+1));
        m[2][0] = 1;
        m[2][1] = 1;
        for (int i = 3; i <=n; ++i) {
            m[i][0] = 1;
            for (int j = 1; j <= min(k, i * (i - 1) / 2); ++j) {
                m[i][j] = m[i][j - 1] + m[i-1][j];
                if (j >= i) m[i][j] -= m[i-1][j-i];
                m[i][j] %= mod;
            }
        }
        return m[n][k];
    }
};

int dp[1005][2005];

class Solution {
public:
    int MOD = 1e9+7;
    int kInversePairs(int n, int k) {
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        for(int i=2;i<=n;i++) {
            int v = 0;
            for(int u=0;u<=k;u++) {
                v += dp[i-1][u];
                if(v>=MOD) v -= MOD;
                
                if(u>=i) { v = v + (MOD - dp[i-1][u-i]); v %= MOD; }    
                dp[i][u] = v;
                
            }
        }
        return dp[n][k];
    }
};

public class Solution {
    public int kInversePairs(int n, int k) {
        long[] dp = new long[k+n+2];
        int mod = 1000000007;
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = dp.length-1-i;j >= 0;j--){
                dp[j+i] -= dp[j];
                if(dp[j+i] < 0)dp[j+i] += mod;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < dp.length-1;j++){
                dp[j+1] += dp[j];
                dp[j+1] %= mod;
            }
        }
        return (int)dp[k];
    }
}