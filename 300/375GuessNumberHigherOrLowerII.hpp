// 375. Guess Number Higher or Lower II
// We are playing the Guess Game. The game is as follows:
// I pick a number from 1 to n. You have to guess which number I picked.
// Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
// However, when you guess a particular number x, and you guess wrong, you pay $x.
// You win the game when you guess the number I picked.
// Example:
// n = 10, I pick 8.
// First round:  You guess 5, I tell you that it's higher. You pay $5.
// Second round: You guess 7, I tell you that it's higher. You pay $7.
// Third round:  You guess 9, I tell you that it's lower. You pay $9.
// Game over. 8 is the number I picked.
// You end up paying $5 + $7 + $9 = $21.
// Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
// Hint:
// The best strategy to play the game is to minimize the maximum loss you could possibly face.
// Another strategy is to minimize the expected loss. Here, we are interested in the first scenario.
// Take a small example (n = 3). What do you end up paying in the worst case?
// Check out this article if you're still stuck. https://en.wikipedia.org/wiki/Minimax
// The purely recursive implementation of minimax would be worthless for even a small n.
// You MUST use dynamic programming.
// As a follow-up, how would you modify your code to solve the problem of minimizing the expected loss,
// instead of the worst-case loss?

class Solution {
public:
    int getMoneyAmount(int n) {
        return recursive(1, n);
    }
private:
    int recursive(int l, int h) {
        if (l >= h) return 0;
        if (l + 1 == h) return l;
        int minV = INT_MAX;
        for (int i = l + 1; i < h; ++i) {
            int maxV = max(recursive(l, i - 1), recursive(i + 1, h));
            minV = min(minV, maxV + i);
        }
        return minV;
    }
};

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> m(n+1, vector<int>(n+1));
        for (int j = 2; j <= n; ++j) {
            m[j - 1][j] = j - 1;
            for (int i = j - 2; i > 0; --i) {
                m[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    int worstCostAtK = k + max(m[i][k - 1], m[k + 1][j]);
                    m[i][j] = min(m[i][j], worstCostAtK);
                }
            }
        }
        return m[1][n];
    }
};

for worst case:

dp(i,j) denotes for the minimum loss to guarantee a win

dp(i,j) = min_k { k + max( dp(i,k-1), dp(k+1,j) ) };

return for dp(1,n);

for expected case:

dp(i,j) denotes for the minimum sum of loss to guarantee a win for every pick.

dp(i,j) = min_k { (j-i) * k + dp(i,k-1) + dp(k+1,j ) };

return for dp(1,n)/n;

In fact, we should design a guessing strategy to minimize the loss of worst case/ expected case.

// https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84817/Minimizing-the-expected-loss-instead-of-worst-case-loss
class Solution2
{
public:
    int getMoneyAmount(int n)
    {
        vector< vector<int> > dp(n+1, vector<int>(n+1, 0));
        record.resize(n+1, vector<int>(n+1, 0));
        for(int interval = 1; interval < n; interval ++)
        {
            for(int i = 1; i< n && i+interval <=n; i++)
            {
                int j = i+interval;
                dp[i][j] = INT_MAX;
                for(int k = i; k<=j; k++)
                {
                    int tmp =(j-i)*k+ (i<k-1?dp[i][k-1]:0) +  (k+1<j? dp[k+1][j]: 0);
                    dp[i][j] = dp[i][j] < tmp? dp[i][j]: (record[i][j] = k,tmp);
                }
            }
        }
        return dp[1][n] / n;
    }
    vector< vector<int> > record;
};