// 465. Optimal Account Balancing
// A group of friends went on holiday and sometimes lent each other money. For example, Alice paid for Bill's lunch for $10. Then later Chris gave Alice $5 for a taxi ride. We can model each transaction as a tuple (x, y, z) which means person x gave person y $z. Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can be represented as [[0, 1, 10], [2, 0, 5]].

// Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.

// Note:

// A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
// Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6.
// Example 1:

// Input:
// [[0,1,10], [2,0,5]]

// Output:
// 2

// Explanation:
// Person #0 gave person #1 $10.
// Person #2 gave person #0 $5.

// Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
// Example 2:

// Input:
// [[0,1,10], [1,0,1], [1,2,5], [2,0,5]]

// Output:
// 1

// Explanation:
// Person #0 gave person #1 $10.
// Person #1 gave person #0 $1.
// Person #1 gave person #2 $5.
// Person #2 gave person #0 $5.

// Therefore, person #1 only need to give person #0 $4, and all debt is settled.

// The question can be transferred to a 3-partition problem, which is NP-Complete.
// https://leetcode.com/problems/optimal-account-balancing/discuss/95355/11-liner-9ms-DFS-solution-(detailed-explanation)

public:
    int minTransfers(vector<vector<int>>& trans) {
        unordered_map<int, long> bal; // each person's overall balance
        for(auto& t: trans) bal[t[0]] -= t[2], bal[t[1]] += t[2];
        for(auto& p: bal) if(p.second) debt.push_back(p.second);
        return dfs(0);
    }
    
private:
    int dfs(int s) { // min number of transactions to settle starting from debt[s]
    	while (s < debt.size() && !debt[s]) ++s; // get next non-zero debt
    	int res = INT_MAX;
    	for (long i = s+1, prev = 0; i < debt.size(); ++i)
    	  if (debt[i] != prev && debt[i]*debt[s] < 0) // skip already tested or same sign debt
    	    debt[i] += debt[s], res = min(res, 1+dfs(s+1)), prev = debt[i]-=debt[s];
    	return res < INT_MAX? res : 0;
    }
    
    vector<long> debt; // all non-zero balances
    
class Solution {
public:
	int minTransfers(vector<vector<int>>& transactions) {
		vector<int> balance;
		for (auto && transaction : transactions) {
			size_t minSize = max(transaction[0], transaction[1]) + 1;
			balance.resize(max(balance.size(), minSize));
			balance[transaction[0]] -= transaction[2];
			balance[transaction[1]] += transaction[2];
		}
		balance.erase(remove(balance.begin(), balance.end(), 0), balance.end());
		return dfs(balance, 0);
	}
private:
	int dfs(vector<int> &balance, int start) {
		while (start < balance.size() && !balance[start]) ++start;
		if (start == balance.size()) return 0;
		int result = INT_MAX;
		for (int i = start + 1; i < balance.size(); ++i) {
			if ((balance[start] > 0 && balance[i] < 0) ||
				(balance[start] < 0 && balance[i] > 0)) {
				balance[i] = balance[i] + balance[start];
				result = min(result, 1 + dfs(balance, start + 1));
				balance[i] = balance[i] - balance[start];
			}
		}
		return result;
	}
};

// 3ms
class Solution {
public:
	int minTransfers(vector<vector<int>>& transactions) {
		vector<int> balance;
		for (auto && transaction : transactions) {
			size_t minSize = max(transaction[0], transaction[1]) + 1;
			balance.resize(max(balance.size(), minSize));
			balance[transaction[0]] -= transaction[2];
			balance[transaction[1]] += transaction[2];
		}
		return dfs(balance, 0);
	}
private:
	int dfs(vector<int> &balance, int start) {
		while (start < balance.size() && !balance[start]) ++start;
		if (start == balance.size()) return 0;
		int result = INT_MAX;
		// shortcut, if there is matching pos/neg, they should be matched.
		for (int i = start + 1; i < balance.size(); ++i) {
		    if (balance[start] + balance[i] == 0) {
		        int temp = 0;
		        swap(temp, balance[i]);
		        result = 1 + dfs(balance, start + 1);
		        swap(temp, balance[i]);
		        return result;
		    }
		}
		for (int i = start + 1; i < balance.size(); ++i) {
			if ((balance[start] > 0 && balance[i] < 0) ||
				(balance[start] < 0 && balance[i] > 0)) {
				balance[i] = balance[i] + balance[start];
				result = min(result, 1 + dfs(balance, start + 1));
				balance[i] = balance[i] - balance[start];
			}
		}
		return result;
	}
};

public:
    int minTransfers(vector<vector<int>>& trans) {
        unordered_map<int, long> bal; // each person's overall balance
        for(auto& t: trans) bal[t[0]] -= t[2], bal[t[1]] += t[2];
        for(auto& p: bal) if(p.second) debt.push_back(p.second);
        return dfs(0, 0);
    }
    
private:
    int dfs(int s, int cnt) { // min number of transactions to settle starting from debt[s]
    	while (s < debt.size() && !debt[s]) ++s; // get next non-zero debt
    	int res = INT_MAX;
    	for (long i = s+1, prev = 0; i < debt.size(); ++i)
    	  if (debt[i] != prev && debt[i]*debt[s] < 0) // skip already tested or same sign debt
    	    debt[i] += debt[s], res = min(res, dfs(s+1,cnt+1)), prev = debt[i]-=debt[s];
    	return res < INT_MAX? res : cnt;
    }
    
    vector<long> debt; // all non-zero balances