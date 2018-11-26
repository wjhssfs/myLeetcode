// 877. Stone Game

// Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

// Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

 

// Example 1:

// Input: [5,3,4,5]
// Output: true
// Explanation: 
// Alex starts first, and can only take the first 5 or the last 5.
// Say he takes the first 5, so that the row becomes [3, 4, 5].
// If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
// If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
 

// Note:

// 2 <= piles.length <= 500
// piles.length is even.
// 1 <= piles[i] <= 500
// sum(piles) is odd.

    bool stoneGame(vector<int>& p) {
        return true;
    }
    
// Alex is first to pick pile.
// piles.length is even, and this lead to an interesting fact:
// Alex can always pick odd piles or always pick even piles!
// Follow-up:

// What if piles.length can be odd?
// What if we want to know exactly the diffenerce of score?
// Then we need to solve it with DP.


// dp[i][j] means the biggest number of stones you can get more than opponent picking piles in piles[i] ~ piles[j].

    bool stoneGame(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = p[i];
        for (int d = 1; d < n; d++)
            for (int i = 0; i < n - d; i++)
                dp[i][i + d] = max(p[i] - dp[i + 1][i + d], p[i + d] - dp[i][i + d - 1]);
        return dp[0][n - 1] > 0;
    }
    
 bool stoneGame(vector<int>& p) {
        vector<int> dp = p;
        for (int d = 1; d < p.size(); d++)
            for (int i = 0; i < p.size() - d; i++)
                dp[i] = max(p[i] - dp[i + 1], p[i + d] - dp[i]);
        return dp[0] > 0;
    }
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<int> s{0};
        for (auto p : piles) s.push_back(s.back() + p);
        vector<int> dp(piles.size());
        for (int l = 1; l <= piles.size(); ++l) {
            for (int i = 0; i + l <= piles.size(); ++i) {
                dp[i] = s[i + l] - s[i] - min(dp[i], dp[i + 1]);
            }
        }
        return dp[0] > s.back() / 2;
    }
};