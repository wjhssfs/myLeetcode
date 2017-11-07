// 448. Find All Numbers Disappeared in an Array

// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements of [1, n] inclusive that do not appear in this array.

// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

// Example:

// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [5,6]

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int cur = 0;
        while (cur < nums.size()) {
            if (/*nums[cur] != cur + 1 && */nums[nums[cur]-1] != nums[cur]) swap(nums[cur], nums[nums[cur] - 1]);
            else ++cur;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1) res.push_back(i + 1);
        }
        return res;
    }
};


    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ret = new ArrayList<Integer>();
        
        for(int i = 0; i < nums.length; i++) {
            int val = Math.abs(nums[i]) - 1;
            if(nums[val] > 0) {
                nums[val] = -nums[val];
            }
        }
        
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] > 0) {
                ret.add(i+1);
            }
            else {
                nums[i] = -nums[i];
            }
        }
        return ret;
    }