// 645. Set Mismatch

// The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]
// Note:
// The given array size will in the range [2, 10000].
// The given array's numbers won't have any order.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);  // duplicate, missing
        //For each number we found, set nums[number-1] to its negative value (<0)
        for(int i=0; i<nums.size(); i++) {
            int idx = abs(nums[i]) - 1; //since index starts from 0, and the set starts from 1
            if(nums[idx] > 0) nums[idx] = -nums[idx];
            else res[0] = idx+1; //have already been found
        }
        // At this point, only nums[missingNumber-1] > 0
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0) nums[i] = -nums[i]; //restore the original values
            else res[1]=i+1;//since index starts from 0, and the set starts from 1
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            // target position should be taken by current number, can't use nums[i] != i + 1 directly
            while(nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] != i + 1) return {nums[i], i + 1};
        }
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> result;
        for (auto num : nums) {
            if (s.count(num) != 0) result.push_back(num);
            s.insert(num);
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (s.count(i) == 0) result.push_back(i);
        }
        return result;
    }
};