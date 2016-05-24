// 77 Combinations 
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
// For example,
// If n = 4 and k = 2, a solution is:
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

//  C(n,k)=C(n-1,k-1)+C(n-1,k).
vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res,res1;
        if(k==n || k==0)
        {
            vector<vector<int> > res2;
            vector<int> curr;
            for(int i=1;i<=k;i++)
                curr.push_back(i);
            res2.push_back(curr);
            return res2;
        }
        res = combine(n-1,k-1);
        for(auto itr=res.begin();itr!=res.end();itr++)
        {
            itr->push_back(n);
        }

        res1 = combine(n-1,k);
        res.insert(res.end(),res1.begin(),res1.end());
        return res;
    }


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while (i >= 0) {
            p[i]++;
            if (p[i] > n) --i;
            else if (i == k - 1) result.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return result;
    }
};