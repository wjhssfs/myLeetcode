// 78 Subsets 
// Given a set of distinct integers, S, return all possible subsets.
// 
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,3], a solution is:
// 
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        result.clear(); candidate.clear();
        recursiveGen(S, 0);
        return result;
    }
private:
    void recursiveGen(vector<int> &S, int index)
    {
        if (index == S.size()) {
            result.push_back(candidate);
            return;
        }
        candidate.push_back(S[index]);
        recursiveGen(S, index+1);
        candidate.pop_back();
        recursiveGen(S, index + 1);

    }
    vector<vector<int> > result;
    vector<int> candidate;
};