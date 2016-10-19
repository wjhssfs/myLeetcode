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
    vector<vector<int>> combine(int n, int k) {
        res.clear(), com.clear(), N = n, K = k;
        if (K < 1 || N < 1 || K > N) return res;
        dfs(1);
        return res;
    }
private:
    int N, K;
    vector<vector<int>> res;
    vector<int> com;
    void dfs(int s) {
        if (com.size() == K) {
            res.emplace_back(com);
            return;
        }
        for (int i = s; i <= N; ++i) {
            com.push_back(i);
            dfs(i+1);
            com.pop_back();
        }
    }
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