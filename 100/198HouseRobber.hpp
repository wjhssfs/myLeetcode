// 198 House Robber 
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of
// them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> noRob(nums.size()), rob(nums.size());
        noRob[0] = 0; rob[0] = nums[0]; 
        for(int i = 1; i < nums.size(); i++){
            noRob[i] = max(rob[i-1], noRob[i-1]);
            rob[i] = noRob[i-1] + nums[i];
        }
        return max(noRob.back(), rob.back());
    }
};

public int rob(int[] num) {
    int prevNo = 0;
    int prevYes = 0;
    for (int n : num) {
        int temp = prevNo;
        prevNo = Math.max(prevNo, prevYes);
        prevYes = n + temp;
    }
    return Math.max(prevNo, prevYes);
}