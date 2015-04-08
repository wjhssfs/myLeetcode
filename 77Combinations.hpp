// 77 Combinations 
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
// 
// For example,
// If n = 4 and k = 2, a solution is:
// 
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		results.clear();
		result.clear();
		if (k > n || n < 1 || k < 1) return results;
		dfs(n, k, 0, 0);
		return results;
	}
	void dfs(int n, int k, int c, int s){
		if (c == k){
			results.push_back(result);
			return;
		}
		for (int i = s; i < n - k + c+1; i++){
			result.push_back(i+1);
			dfs(n, k, c + 1, i+1);
			result.pop_back();
		}
	}
	vector<vector<int> > results;
	vector<int> result;
};