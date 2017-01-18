// 368. Largest Divisible Subset
// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj)
// of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
// If there are multiple solutions, return any subset is fine.
// Example 1:
// nums: [1,2,3]
// Result: [1,2] (of course, [1,3] will also be ok)
// Example 2:
// nums: [1,2,4,8]
// Result: [1,2,4,8]

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<int> nSetSize(nums.size(), 1), pre(nums.size(), -1);
        int maxSize = 1, maxEnd = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && nSetSize[i] < 1 + nSetSize[j]){
                    nSetSize[i] = 1 + nSetSize[j];
                    pre[i] = j;
                    if (nSetSize[i] > maxSize) {
                        maxSize = nSetSize[i];
                        maxEnd = i;
                    }
                }
            }
        }
        vector<int> ret(maxSize);
        int cur = maxEnd;
        for (int i = maxSize - 1; i >=0; --i) {
            ret[i] = nums[cur];
            cur = pre[cur];
        }
        return ret;
    }
};

// any interger % -1 = 0
def largestDivisibleSubset(self, nums):
    S = {-1: set()}
    for x in sorted(nums):
        S[x] = max((S[d] for d in S if x % d == 0), key=len) | {x}
    return list(max(S.values(), key=len))