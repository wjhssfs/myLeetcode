// 740. Delete and Earn
// Given an array nums of integers, you can perform operations on the array.

// In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

// You start with 0 points. Return the maximum number of points you can earn by applying such operations.

// Example 1:
// Input: nums = [3, 4, 2]
// Output: 6
// Explanation: 
// Delete 4 to earn 4 points, consequently 3 is also deleted.
// Then, delete 2 to earn 2 points. 6 total points are earned.
// Example 2:
// Input: nums = [2, 2, 3, 3, 3, 4]
// Output: 9
// Explanation: 
// Delete 3 to earn 3 points, deleting both 2's and the 4.
// Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
// 9 total points are earned.
// Note:

// The length of nums is at most 20000.
// Each element nums[i] is an integer in the range [1, 10000].


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        for (auto num : nums) m[num] += num;
        int pre = -1, deletePre = 0, nonDeletePre = 0;
        for (auto&& r : m) {
            auto t = nonDeletePre;
            nonDeletePre = max(deletePre, nonDeletePre);
            deletePre = r.second + (r.first - pre != 1 ? nonDeletePre : t);
            pre = r.first;
        }
        
        return max(deletePre, nonDeletePre);
    }
};

// If we sort all the numbers into buckets indexed by these numbers, this is essentially asking you to repetitively take an bucket while giving up the 2 buckets next to it. (the range of these numbers is [1, 10000])

// The optimal final result can be derived by keep updating 2 variables skip_i, take_i, which stands for:
// skip_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you skip the ith bucket.
// take_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you take the ith bucket.

// DP formula:
// take[i] = skip[i-1] + values[i];
// skip[i] = Math.max(skip[i-1], take[i-1]);
// take[i] can only be derived from: if you skipped the [i-1]th bucket, and you take bucket[i].
// skip[i] through, can be derived from either take[i-1] or skip[i-1], whatever the bigger;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};