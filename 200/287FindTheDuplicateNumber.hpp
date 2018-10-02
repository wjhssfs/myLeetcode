// 287 Find the Duplicate Number
// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

// Note:
// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated more than once.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty()) return -1;
        int l = 1, h = (int)nums.size() - 1;
        while(l < h) {
            int m = (l+h)/2, nlem = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= m) nlem++;
            }
            if(nlem <= m) l = m+1;
            else h = m;
        }
        return l;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
            if(nums.empty()) return 0;
            int slow=0, fast=0;
            slow = nums[slow];
            fast = nums[nums[fast]];
            while(slow != fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while(slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
    }
};
	
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = -1;
        for(int i = 0; i < nums.size(); i++) {
            n = std::abs(nums[i]);
            if(nums[n] < 0) {
                break;
            }
            else {
                nums[n] *= -1;
            }
        }
        for(int j = 0; j < nums.size(); j++) {
            nums[j] = std::abs(nums[j]);
        }
        return n;
    }
};