// 121 Best Time to Buy and Sell Stock
// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (ie, buy one and sell one
// share of the stock), design an algorithm to find the maximum profit.
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int maxProfit = 0;
		int minPrice = INT_MAX;
		for (int i = 0; i != prices.size(); i++){
			minPrice = min(minPrice, prices[i]);
			maxProfit = max(maxProfit, prices[i] - minPrice);
		}
		return maxProfit;
	}
};