// 61 Unique Paths 
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below). 
// The robot can only move either down or right at any point in time. The robot is trying to reach
// the bottom-right corner of the grid 
// How many possible unique paths are there?
// Note: m and n will be at most 100.

/*
 Solution: 
 1. Use formula C(x,t) = t!/(x!*(t-x)!) (x should be large for calculation).
 2. Dynamic programming. UP(i,j) = UP(i-1,j) + UP(i,j-1).
 */
class Solution {
public:
    int uniquePaths_1(int m, int n) {
        if (m == 1  || n == 1) return 1;
        int t = (m-1)+(n-1);
        int x = (m > n) ? (m-1) : (n-1);
        
        long long res = 1;
        for (int i = t; i > x; i--)
            res *= i;
        for (int i = t-x; i > 1; i--)
            res /= i;
        
        return res;
    }

    int uniquePaths_2(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};

// https://leetcode.com/discuss/38353/0ms-5-lines-dp-solution-in-c-with-explanations
class Solution {
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
}; 