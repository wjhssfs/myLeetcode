// 260 Single Number III

// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

// For example:

// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

// Note:
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0; // A^B
        for(int i  = 0; i < nums.size(); i++){
            xorAll ^= nums[i];
        }

        // Get the right most diff bit
        int groupMask = xorAll & ~(xorAll - 1); 

        // Split nums into 2 groups based on the bit above,
        // This way, A and B will be in different group. In each
        // group, other numbers still show up exactly twice
        int numA = 0, numB = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & groupMask){
                numA ^= nums[i];
            }
            else {
                numB ^= nums[i];
            }
        }

        return {numA, numB};  
    }
};