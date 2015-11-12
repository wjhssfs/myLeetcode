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
    NumArray(vector<int> &nums) {
        numSumsLTR.resize(nums.size());
        numSumsRTL.resize(nums.size());
        total = 0;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            int j = nums.size() -1 - i;
            numSumsLTR[i] = (i==0? 0:numSumsLTR[i-1]) + nums[i];
            numSumsRTL[j] = (i==0? 0:numSumsRTL[j+1]) + nums[j];
        }
    }

    int sumRange(int i, int j) {
        int result = total;
        result -= i < 1 ? 0:numSumsLTR[i-1];
        result -= j > numSumsLTR.size()-2 ? 0:numSumsRTL[j+1];
        return result;
    }
private:
    vector<int> numSumsLTR;
    vector<int> numSumsRTL;
    int total;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);