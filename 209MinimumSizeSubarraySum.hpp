// 209 Minimum Size Subarray Sum
// Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint. 
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0, sum = 0, len = INT_MAX;
        while(end < nums.size()){
            sum += nums[end++];
            if(sum < s) continue;
            while(sum >= s){
                len = min(len, end - start);
                sum -= nums[start];
                start++;
            }
        }
        if(len==INT_MAX) return 0;
        else return len;
    }
};