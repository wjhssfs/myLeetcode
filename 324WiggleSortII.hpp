// 324. Wiggle Sort II

// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

// Example:
// (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
// (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

// Note:
// You may assume all input has valid answer.

// Follow Up:
// Can you do it in O(n) time and/or in-place with O(1) extra space?

//https://leetcode.com/discuss/76965/3-lines-python-with-explanation-proof
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> buf(nums);
		sort(buf.begin(), buf.end());
		int middle = ((int)nums.size() - 1) / 2;
		for (int i = middle, j = 0; i >= 0; --i) {
			nums[j] = buf[i];
			j += 2;
		}
		for (int i = (int) nums.size() - 1, j = 1; i > middle; --i) {
			nums[j] = buf[i];
			j += 2;
		}
	}
};