// 39 Combination Sum
// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &num, int target) {
        t = target; s = 0; n = num.size();
        sort(num.begin(), num.end());
        gen(num, 0);
        return result;
    }
private:
    void gen(vector<int> &num, int start)
    {
        if (s == t){ result.push_back(can); return; }
        if (s > t) return;
        for (int index = start; index < n; index++)
        {
            int i = num[index];
            s += i;
            can.push_back(i);
            gen(num, index);
            can.pop_back();
            s -= i;
        }
    }

    int s, t, n;
    vector<int> can;
    vector<vector<int>>result;
};

class Solution2 {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> com;
        combinationSumRe(candidates, target, 0, com, res);
        return res;
    }

    void combinationSumRe(const vector<int> &num, int target, int start, vector<int> &com, vector<vector<int>> &res)
    {
        if (target == 0) {
            res.push_back(com);
            return;
        }
        for (int i = start; i < num.size() && target >= num[i]; ++i) {
            com.push_back(num[i]);
            combinationSumRe(num, target-num[i], i, com, res);
            com.pop_back();
        }
    }
};