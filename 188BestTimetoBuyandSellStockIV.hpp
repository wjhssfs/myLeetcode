// 188 Best Time to Buy and Sell Stock IV
// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
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

// Solution 2:
// https://leetcode.com/discuss/26745/c-solution-with-o-n-klgn-time-using-max-heap-and-stack
class Solution2 {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = (int)prices.size(), ret = 0, v, p = 0;
        priority_queue<int> profits;
        stack<pair<int, int> > vp_pairs;
        while (p < n) {
            // find next valley/peak pair
            for (v = p; v < n - 1 && prices[v] >= prices[v+1]; v++);
            for (p = v + 1; p < n && prices[p] >= prices[p-1]; p++);
            // save profit of 1 transaction at last v/p pair, if current v is lower than last v
            while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first]) {
                profits.push(prices[vp_pairs.top().second-1] - prices[vp_pairs.top().first]);
                vp_pairs.pop();
            }
            // save profit difference between 1 transaction (last v and current p) and 2 transactions (last v/p + current v/p),
            // if current v is higher than last v and current p is higher than last p
            while (!vp_pairs.empty() && prices[p-1] >= prices[vp_pairs.top().second-1]) {
                profits.push(prices[vp_pairs.top().second-1] - prices[v]);
                v = vp_pairs.top().first;
                vp_pairs.pop();
            }
            vp_pairs.push(pair<int, int>(v, p));
        }
        // save profits of the rest v/p pairs
        while (!vp_pairs.empty()) {
            profits.push(prices[vp_pairs.top().second-1] - prices[vp_pairs.top().first]);
            vp_pairs.pop();
        }
        // sum up first k highest profits
        for (int i = 0; i < k && !profits.empty(); i++) {
            ret += profits.top();
            profits.pop();
        }
        return ret;
    }
};