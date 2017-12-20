// 123 Best Time to Buy and Sell Stock III 
// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
	int maxProfit(vector<int> &prices){
		return maxProfit(prices, 2);
	}
	int maxProfit(vector<int> &prices, int k) {
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

// Traverse the array two times. First from right to left, second from left to right.
class Solution2 {
public:
	int maxProfit(vector<int> &prices) {
        int sz = prices.size();
        if(sz <2)  return 0;
        vector<int> maxProfitAfterI(sz);

        int maxSofar = prices[sz-1];
        maxProfitAfterI[sz-1] = 0;
        for(int i = sz-2; i >=0; i--){
            maxSofar = max(maxSofar, prices[i]);
            maxProfitAfterI[i] = max(maxProfitAfterI[i+1], maxSofar - prices[i]);
        }
        
        int maxProfit = 0;
        int minSofar = prices[0];
        for(int i = 1; i < sz; i++){
            minSofar = min(minSofar, prices[i]);
            maxProfit = max(maxProfit,  prices[i] - minSofar + maxProfitAfterI[i]);
        }
        
        return maxProfit;
	}
};

// Solution: dp.  max profit =  max { l2r[0...i] + r2l[i+1...N-1] }. (almost same as solution 2)
class Solution3 {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if (N <= 1) return 0;
        
        int l2r[N], r2l[N];
        l2r[0] = 0;
        r2l[N-1] = 0;
        
        int minn = prices[0];
        for (int i = 1; i < N; ++i)
        {
            minn = min(minn, prices[i]);
            l2r[i] = max(l2r[i-1], prices[i] - minn);
        }
        
        int maxx = prices[N-1];
        for (int i = N-2; i >= 0; --i)
        {
            maxx = max(maxx, prices[i]);
            r2l[i] = max(r2l[i+1], maxx - prices[i]);
        }
        
        int res = l2r[N-1];
        for (int i = 0; i < N-1; ++i)
            res = max(res, l2r[i] + r2l[i+1]);
        return res;
    }
};
