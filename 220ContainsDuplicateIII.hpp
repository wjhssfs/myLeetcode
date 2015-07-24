// 220 Contains Duplicate III 

// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        if(nums.empty() || k <= 0 || t < 0) return false;
        for(int i = 0; i < nums.size(); i++){
        	if(i>k) s.erase(nums[i-k-1]);
        	auto itLow = s.lower_bound(nums[i]-t);
        	if(itLow != s.end() && *itLow >= (long long)nums[i] - t && *itLow <= (long long)nums[i]+t) return true;
        	s.insert(nums[i]);
        }
        return false;
    }
};