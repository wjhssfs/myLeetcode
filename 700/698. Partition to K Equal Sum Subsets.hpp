// 698. Partition to K Equal Sum Subsets

// Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

// Example 1:
// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
// Note:

// 1 <= k <= len(nums) <= 16.
// 0 < nums[i] < 10000.

class Solution {
public:
    bool dfs(vector<int> &nums, int idx, vector<int> &sums, int n, int k, int sum) {
        if (n == idx) {
            return true;
        }
        for (int i = 0; i < k; i++) {
            if (sums[i] + nums[idx] > sum) {
                continue;
            }
            sums[i] += nums[idx];
            if (dfs(nums, idx + 1, sums, n, k, sum)) {
                return true;
            }
            sums[i] -= nums[idx];
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % k != 0) {
            return false;
        }
        sum /= k;
        sort(nums.rbegin(), nums.rend());
        vector<int> sums(k);
        return dfs(nums, 0, sums, nums.size(), k, sum);
    }
};

int d[1 << 16];
vector<int> a;

int doit(int bit, int sum)
{
	int i, j, tot, tmp, ans;
	if (bit == 0) return 1;
	if (d[bit] != -1) return d[bit];
	ans = 0;
	for (i = (1 << a.size()) - 1; i >= 0; i--)
	{
		i &= bit;
		tot = 0;
		for (j = 0; j<a.size(); j++)
			if (((1 << j)&i) != 0)
				tot += a[j];
		if (tot == sum)
		{
			tmp = doit(bit^i, sum);
			if (tmp == 1)
			{
				ans = 1; break;
			}
		}
	}
	d[bit] = ans;
	return ans;
}

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int i, sum;
		sum = 0;
		for (i = 0; i<nums.size(); i++)
			sum += nums[i];
		//cout<<sum<<endl;
		if (sum%k != 0) return false;
		sum /= k;
		memset(d, -1, sizeof(d));
		a = nums;		return doit((1 << a.size()) - 1, sum);
	}
};