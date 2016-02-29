// 303 Range Sum Query - Immutable

// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// Example:
// Given nums = [-2, 0, 3, -5, 2, -1]

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
// Note:
// You may assume that the array does not change.
// There are many calls to sumRange function.

class NumArray {
public:
    NumArray(vector<int> &nums) : _nums(nums){
        for(int i = 1; i < (int)_nums.size(); i++) _nums[i] += _nums[i-1];
    }

    int sumRange(int i, int j) {
        int sum = _nums[j];
        if(i) sum -= _nums[i-1];
        return sum;
    }
    vector<int> _nums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);