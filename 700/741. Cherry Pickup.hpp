// 741. Cherry Pickup
// In a N x N grid representing a field of cherries, each cell is one of three possible integers.

// 0 means the cell is empty, so you can pass through;
// 1 means the cell contains a cherry, that you can pick up and pass through;
// -1 means the cell contains a thorn that blocks your way.
// Your task is to collect maximum number of cherries possible by following the rules below:

// Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
// After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
// When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
// If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
// Example 1:
// Input: grid =
// [[0, 1, -1],
//  [1, 0, -1],
//  [1, 1,  1]]
// Output: 5
// Explanation: 
// The player started at (0, 0) and went down, down, right right to reach (2, 2).
// 4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
// Then, the player went left, up, up, left to return home, picking up one more cherry.
// The total number of cherries picked up is 5, and this is the maximum possible.
// Note:

// grid is an N by N 2D array, with 1 <= N <= 50.
// Each grid[i][j] is an integer in the set {-1, 0, 1}.
// It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.

// https://leetcode.com/problems/cherry-pickup/discuss/109906/Annotated-C++-DP-Solution

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        // dp holds maximum # of cherries two k-length paths can pickup.
        // The two k-length paths arrive at (i, k - i) and (j, k - j), 
        // respectively.
        vector<vector<int>> dp(n, vector<int>(n, -1));

        dp[0][0] = grid[0][0]; // length k = 0
        
        // maxK: number of steps from (0, 0) to (n-1, n-1).
        const int maxK = 2 * (n - 1); 
        
        for (int k = 1; k <= maxK; k++) { // for every length k
            vector<vector<int>> curr(n, vector<int>(n, -1));
        
            // one path of length k arrive at (i, k - i) 
            for (int i = 0; i < n && i <= k; i++) {
                if ( k - i >= n) continue;
                // another path of length k arrive at (j, k - j)
                for (int j = 0; j < n && j <= k; j++) {
                    if (k - j >= n) continue;
                    if (grid[i][k - i] < 0 || grid[j][k - j] < 0) { // keep away from thorns
                        continue;
                    }
                    
                    int cherries = dp[i][j]; // # of cherries picked up by the two (k-1)-length paths.
                    
                    // See the figure below for an intuitive understanding
                    if (i > 0) cherries = std::max(cherries, dp[i - 1][j]);
                    if (j > 0) cherries = std::max(cherries, dp[i][j - 1]);
                    if (i > 0 && j > 0) cherries = std::max(cherries, dp[i - 1][j - 1]);
                    
                    // No viable way to arrive at (i, k - i)-(j, k-j).
                    if (cherries < 0) continue;
                    
                    // Pickup cherries at (i, k - i) and (j, k -j ) if i != j.
                    // Otherwise, pickup (i, k-i). 
                    cherries += grid[i][k - i] + (i == j ? 0 : grid[j][k - j]);
                
                    curr[i][j] = cherries;
                }
            }
            dp = std::move(curr); 
        }
        
        return std::max(dp[n-1][n-1], 0); 
    }
};

// https://leetcode.com/problems/cherry-pickup/discuss/109903/Step-by-step-guidance-of-the-O(N3)-time-and-O(N2)-space-solution
public int cherryPickup(int[][] grid) {
    int N = grid.length, M = (N << 1) - 1;
    int[][] dp = new int[N][N];
    dp[0][0] = grid[0][0];
        
    for (int n = 1; n < M; n++) {
    for (int i = N - 1; i >= 0; i--) {
        for (int p = N - 1; p >= 0; p--) {
        int j = n - i, q = n - p;
                
        if (j < 0 || j >= N || q < 0 || q >= N || grid[i][j] < 0 || grid[p][q] < 0) {
                    dp[i][p] = -1;
                    continue;
                 }
         
         if (i > 0) dp[i][p] = Math.max(dp[i][p], dp[i - 1][p]);
         if (p > 0) dp[i][p] = Math.max(dp[i][p], dp[i][p - 1]);
         if (i > 0 && p > 0) dp[i][p] = Math.max(dp[i][p], dp[i - 1][p - 1]);
         
         if (dp[i][p] >= 0) dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0)
             }
     }
    }
    
    return Math.max(dp[N - 1][N - 1], 0);
}