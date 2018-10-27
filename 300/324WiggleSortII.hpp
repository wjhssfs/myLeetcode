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
// Make M apart most, at most can have n/2 M
// Example nums = [1,2,...,7]      Example nums = [1,2,...,8] 

// Small half:  4 . 3 . 2 . 1      Small half:  4 . 3 . 2 . 1 .
// Large half:  . 7 . 6 . 5 .      Large half:  . 8 . 7 . 6 . 5
// --------------------------      --------------------------
// Together:    4 7 3 6 2 5 1      Together:    4 8 3 7 2 6 1 5
// Small half:  M . M . S . S      Small half:  M . S . S . S .
// Large half:  . L . L . M .      Large half:  . L . M . M . M
// --------------------------      --------------------------
// Together:    M L M L S M S      Together:    M L S M S M S M

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

// https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)+O(1)-after-median-Virtual-Indexing
void wiggleSort(vector<int>& nums) {
    int n = nums.size();

    // Find a median.
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    // Index-rewiring.
    #define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
}