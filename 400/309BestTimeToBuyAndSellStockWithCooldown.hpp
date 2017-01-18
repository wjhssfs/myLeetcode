// 309 Best Time to Buy and Sell Stock with Cooldown

// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
// Example:

// prices = [1, 2, 3, 0, 2]
// maxProfit = 3
// transactions = [buy, sell, cooldown, buy, sell]

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (!n) return 0;
		vector<int> hold(n), nothold(n);
		for (int i = 0; i < n; i++) {
			hold[i] = max(i > 0 ? hold[i - 1] : INT_MIN, (i > 1 ? nothold[i - 2] : 0) - prices[i]);
			nothold[i] = max(i > 0 ? nothold[i - 1] : 0, i > 0 ? hold[i - 1] + prices[i] : INT_MIN);
		}
		return nothold[n-1];
	}
};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (!n) return 0;
		int hold = -prices[0], notHold1 = 0, notHold2 = 0;
		for (int i = 1; i < n; i++) {
			int preHold = hold;
			hold = max(preHold, notHold2 - prices[i]);
			notHold2 = notHold1;
			notHold1 = max(notHold1, preHold + prices[i]);
		}
		return notHold1;
	}
};