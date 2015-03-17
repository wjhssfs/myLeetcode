// 188 Best Time to Buy and Sell Stock IV
// Say you have an array for which the ith element is the price of a given stock on day i.
// 
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
// 
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

// Use 2 DPs
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (k <= 0 || prices.empty()) return 0;
        if (k >= prices.size() / 2) return maxProfit(prices); //quick resolve

        // p[i][j] means max profit involving i transactions and till day j
        vector<vector<int>> p(k+1, vector<int>(prices.size())); //k+1 rows
        for (int i = 1; i <= k; i++){
            // maxProfitHolding is the maximum profit before day j if you have the stock
            // the profit if sell on day j will be prices[j] + maxProfitHolding
            // set to -prices[0] for the first day since we need prices[0] to have the stock.
            int maxProfitHolding = -prices[0]; 
            for (int j = 1; j < prices.size(); j++){
                p[i][j] = max(p[i][j - 1], prices[j] + maxProfitHolding);
                maxProfitHolding = max(maxProfitHolding, p[i - 1][j - 1] - prices[j]);
            }
        }
        return p[k][prices.size() - 1];
    }

    int maxProfit(vector<int> &prices) {
        int totalProfit = 0;
        for (size_t i = 0; i < prices.size() - 1; i++){
            if (prices[i] < prices[i + 1]) totalProfit += prices[i + 1] - prices[i];
        }
        return totalProfit;
    }
};