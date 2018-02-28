// 15 3Sum 
// Given an array S of n integers, are there elements a, b, c in S such that
// a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},
//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end()); // faster without 
        int N = num.size();
        for (int i = 0; i < N-2 && num[i] <= 0; ++i)
        {
            if (i > 0 && num[i] == num[i-1])
                continue; // avoid duplicates
            int twosum = 0 - num[i];
            int l = i + 1, r = N - 1;
            while (l < r)
            {
                int sum = num[l] + num[r];
                if (sum < twosum)
                    l++;
                else if (sum > twosum)
                    r--;
                else {
                    res.push_back({num[i], num[l], num[r]});
                    l++; r--;
                    // dedupe in place, faster than doing res.erase(unique(res.begin(), res.end()), res.end());
                    while (l < r && num[l] == num[l-1]) l++;  // avoid duplicates  
                    while (l < r && num[r] == num[r+1]) r--;  // avoid duplicates
                }
            }
        }
        return res;
    }
};

public List<List<Integer>> threeSum(int[] num) {
    Arrays.sort(num);
    List<List<Integer>> res = new LinkedList<>(); 
    for (int i = 0; i < num.length-2; i++) {
        if (i == 0 || (i > 0 && num[i] != num[i-1])) {
            int lo = i+1, hi = num.length-1, sum = 0 - num[i];
            while (lo < hi) {
                if (num[lo] + num[hi] == sum) {
                    res.add(Arrays.asList(num[i], num[lo], num[hi]));
                    while (lo < hi && num[lo] == num[lo+1]) lo++;
                    while (lo < hi && num[hi] == num[hi-1]) hi--;
                    lo++; hi--;
                } else if (num[lo] + num[hi] < sum) lo++;
                else hi--;
           }
        }
    }
    return res;
}
