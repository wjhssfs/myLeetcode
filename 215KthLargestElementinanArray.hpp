// 215 Kth Largest Element in an Array 

// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.

// https://leetcode.com/discuss/36966/solution-explained


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		// shuffle to reduce O(n) worst case.
		std::srand(unsigned(std::time(0)));
		std::random_shuffle(nums.begin(), nums.end());
		return findKthLargestRanged(nums, 0, nums.size() - 1, k);
	}

	int findKthLargestRanged(vector<int>& nums, int start, int end, int k) {
		int newPivot = partition(nums, start, end);
		if (newPivot - start == k - 1) { return nums[newPivot]; }
		if (newPivot - start < k - 1) return findKthLargestRanged(nums, newPivot + 1, end, k - (newPivot - start + 1));
		else return findKthLargestRanged(nums, start, newPivot - 1, k);
	}

	// use start as pivot
	int partition(vector<int>& nums, int start, int end){
		int pivot = start++;
		while (1){
			while (start < end && nums[start] > nums[pivot]) start++;
			while (start < end && nums[end] <= nums[pivot]) end--;
			if (start < end){
				swap(nums[start], nums[end]);
			}
			else if (start == end && nums[start] > nums[pivot]) start++; // this is to ensure nums[start-1] is last num that >= num[pivot]
			else break;
		}
		swap(nums[pivot], nums[start-1]);
		return start - 1;
	}
};
