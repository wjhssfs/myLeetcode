// 312 Burst Balloons

// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons wisely.

// Note: 
// (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

// Example:

// Given [3, 1, 5, 8]

// Return 167

//     nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        _nums.clear();
        memset(cache, 0, sizeof(cache));
        _nums.reserve(nums.size()+1);
        _nums.push_back(1);
        for(auto &&n:nums) 
            if(n)
                _nums.push_back(n);
        _nums.push_back(1);
        return maxCoinsForEnds(0, _nums.size()-1);
    }
    
private:
    int maxCoinsForEnds(int left, int right){
        if(cache[left][right] > 0) return cache[left][right];
        int result = 0;
        for(int i = left + 1; i < right; i++){
            int cur = _nums[left] * _nums[i] * _nums[right];
            cur += maxCoinsForEnds(left, i);
            cur += maxCoinsForEnds(i, right);
            result = max(result, cur);
            cache[left][right] = result;
        }
        return result;
    }
    vector<int> _nums;
    int cache[502][502];
};

// https://leetcode.com/discuss/72216/share-some-analysis-and-explanations