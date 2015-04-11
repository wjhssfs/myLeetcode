// 90 Subsets II 
// Given a collection of integers that might contain duplicates, S, return all possible subsets.
// 
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,2], a solution is:
// 
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

 
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        for (auto i : S) m[i]++;
        result.clear(); candidate.clear();
        recursiveGen(0);
        return result;
    }
private:
    void recursiveGen(int index)
    {
        if (index == m.size()) {
            result.push_back(candidate);
            return;
        }
        auto it = m.begin();
        for(int i = 0; i < index; i++) it++;
        recursiveGen(index+1);
        for (int i = 0; i < it->second; i++)
        {
            candidate.push_back(it->first);
            recursiveGen(index + 1);
        }
        for (int i = 0; i < it->second; i++)
            candidate.pop_back();        
    }

    vector<vector<int> > result;
    vector<int> candidate;
    map<int, int> m;
};

class Solution2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res(1, vector<int>());
        sort(S.begin(), S.end());
        vector<int> set;
        int N = S.size();
        for (int l = 1; l <= N; ++l)
            subsetsWithDupRe(S, l, 0, set, res);
        return res;
    }

    void subsetsWithDupRe(vector<int> &S, int L, int start, vector<int> &set, vector<vector<int>> &res)
    {
        int N = S.size(), M = set.size();
        if (M == L) {
            res.push_back(set);
            return;
        }
        for (int i = start; i <= N - (L - M); ++i) {
            if (i > start && S[i] == S[i-1]) continue;
            set.push_back(S[i]);
            subsetsWithDupRe(S, L, i + 1, set, res);
            set.pop_back();
        }
    }
};