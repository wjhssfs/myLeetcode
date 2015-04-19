// 16 3Sum Closest 
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

//     For example, given array S = {-1 2 1 -4}, and target = 1.

//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int sz = num.size();
        sort(num.begin(), num.end());
        bool init = false;
        int minDiff = 0;
        int fsum = 0;
        for (int i = 0; i < sz - 2; i++)
        {
            int j = i + 1;
            int k = sz - 1;
            while (j < k)
            {
                int sum3 = num[i] + num[j] + num[k];
                if (init)
                {
                    int cDiff = abs(sum3 - target);
                    if (cDiff == 0)
                    {
                        return target;
                    }
                    if (minDiff > cDiff)
                    {
                        minDiff = cDiff;
                        fsum = sum3;
                    }

                    if (sum3 > target)
                    {
                        k--;
                    }
                    else
                    {
                        j++;
                    }
                }
                else
                {
                    fsum = sum3;
                    minDiff = abs(sum3 - target);
                    if (minDiff == 0)
                    {
                        return target;
                    }
                    init = true;
                    if (sum3 > target)
                    {
                        k--;
                    }
                    else
                    {
                        j++;
                    }
                }
            }
        }
        return fsum;
    }
};

class Solution2 {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res = INT_MAX;
        int N = num.size();
        sort(num.begin(), num.end());
        for (int i = 0; i < N-2; ++i)
        {
            int l = i + 1, r = N - 1;
            while (l < r)
            {
                int threesum = num[i] + num[l] + num[r];
                if (threesum == target) return target;
                else if (threesum < target) l++;
                else r--;
                if (res == INT_MAX || abs(threesum - target) < abs(res - target))
                    res = threesum;
            }
        }
        return res;
    }
};