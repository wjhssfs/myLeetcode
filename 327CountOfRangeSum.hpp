// 327. Count of Range Sum
// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

// Note:
// A naive algorithm of O(n2) is trivial. You MUST do better than that.

// Example:
// Given nums = [-2, 5, -1], lower = -2, upper = 2,
// Return 3.
// The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.


// https://leetcode.com/discuss/79083/share-my-solution
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		vector<long long> sums(nums.size() + 1);
		for (int i = 0; i < (int)nums.size(); i++) {
			sums[i + 1] = sums[i] + nums[i];
		}
		return countWhileMergeSort(sums, 0, sums.size(), lower, upper);
	}

	int countWhileMergeSort(vector<long long> &sums, int start, int end, int lower, int upper) {
		if (end - start <= 1)
			return 0;
		int mid = (end + start) / 2;
		int total = countWhileMergeSort(sums, start, mid, lower, upper) + 
			countWhileMergeSort(sums, mid, end, lower, upper);
		vector<long long> temp(sums.begin() + start, sums.begin() + end);
		int n = temp.size(), r = start, li = mid - start, ui = li, j = li;
		for (int i = 0; i < mid - start; ++i) {
			while (li < n && temp[li] - temp[i] < lower)
				++li;
			while (ui < n && temp[ui] - temp[i] <= upper)
				++ui;
			while (j < n && temp[j] < temp[i])
				sums[r++] = temp[j++];
			sums[r++] = temp[i];
			total += ui - li;
		}
		while(r < end)
			sums[r++] = temp[j++];
		return total;
	}
};