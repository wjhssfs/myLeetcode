// 40 Combination Sum II 
// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
// A solution set is: 
// [1, 7] 
// [1, 2, 5] 
// [2, 6] 
// [1, 1, 6] 

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        can.clear(); result.clear(); m.clear(); s = 0; t = target;
        for (auto i : num)m[i]++;
        gen(0);
        return result;
    }
private:
    void gen(int index)
    {
        if (s == t) { result.push_back(can); return; }
        else if (s > t || index == m.size()) return;

        auto it = m.begin();
        int step = index;
        while (step--) it++;
        for (int i = 0; i < it->second; i++)
        {
            can.push_back(it->first);
            s += it->first;
            gen(index + 1);
        }

        for (int i = 0; i < it->second; i++)
        {
            s -= it->first;
            can.pop_back();
        }
        gen(index + 1);
    }

    int s, t;
    vector<int> can;
    vector<vector<int>>result;
    map<int, int> m;
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        vector<int> com;
        combinationSum2Re(num, target, 0, com, res);
        return res;
    }

    void combinationSum2Re(const vector<int> &num, int target, int start, vector<int> &com, vector<vector<int>> &res)
    {
        if (target == 0) {
            res.push_back(com);
            return;
        }
        for (int i = start; i < num.size() && num[i] <= target; ++i) {
            if (i > start && num[i] == num[i-1]) continue;
            com.push_back(num[i]);
            combinationSum2Re(num, target-num[i], i+1, com, res);
            com.pop_back();
        }
    }
};