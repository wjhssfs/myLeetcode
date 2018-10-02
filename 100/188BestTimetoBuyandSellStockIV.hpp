// 188 Best Time to Buy and Sell Stock IV
// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


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

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int sz = prices.size(), maxProfit = 0;
        vector<bool> hold(sz);//whether you hold stock at prices i

        for (int t = 0; t < k; t++){
            int c = 0, start = 0, newStart = 0, end = 0, cmax = 0;
            for (int i = 0; i < sz-1; i++){
                if (i>0 && hold[i] != hold[i - 1]) { c = 0; newStart = i; }
                c += prices[i+1] - prices[i];
                if (!hold[i] && c <= 0 || hold[i] && c >= 0){
                    c = 0; newStart = i + 1;
                }
                else if (cmax < abs(c)){
                    cmax = abs(c); start = newStart; end = i;
                }
            }
            if (cmax == 0) break;
            maxProfit += cmax;
            for (int i = start; i <= end; i++) hold[i] = !hold[i];
        }
        return maxProfit;
    }
};

// Solution 2:
// https://leetcode.com/discuss/26745/c-solution-with-o-n-klgn-time-using-max-heap-and-stack
// The key point is when there are two v/p pairs (v1, p1) and (v2, p2), satisfying v1 <= v2 and p1 <= p2, 
// we can either make one transaction at [v1, p2], or make two at both [v1, p1] and [v2, p2]. 
// The trick is to treat [v1, p2] as the first transaction, and [v2, p1] as the second.
// Then we can guarantee the right max profits in both situations,
// p2 - v1 for one transaction and p1 - v1 + p2 - v2 for two.
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