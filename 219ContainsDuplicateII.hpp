// 219 Contains Duplicate II 
// Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m; //num[i] and i
        for(int i = 0; i < nums.size(); i++){
            if(m.count(nums[i])){
                if(i - m[nums[i]] <= k) return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};