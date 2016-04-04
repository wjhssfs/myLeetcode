// 238 Product of Array Except Self 
// Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
// Solve it without division and in O(n).
// For example, given [1,2,3,4], return [24,12,8,6].
// Follow up:
// Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productBefore(nums.size()), productAfter(nums.size()), res(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i==0) {
                productBefore[i] = 1;
                productAfter[nums.size()-1 - i] = 1;
            }
            else {
                productBefore[i] = productBefore[i-1] * nums[i-1];
                productAfter[nums.size() -1 -i] = productAfter[nums.size() -i] * nums[nums.size() -i];
            }
        }
        for(int i = 0; i < nums.size(); i++){
            res[i] = productBefore[i] * productAfter[i]; 
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++) res[i] = i == 0? 1 : res[i-1] * nums[i-1];
        int productAfter = 1;
        for(int i = nums.size() -1 ; i >= 0; i--){
            res[i] = res[i] * productAfter;
            productAfter *= nums[i];
        }
        return res;
    }
};