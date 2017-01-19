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