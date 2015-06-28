// 213 House Robber II 

// Note: This is an extension of House Robber.

// After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		int rabStraightWithoutFirst = robStraight(vector<int>(nums.begin() + 1, nums.end()));
		int rabStraightWithoutLast = robStraight(vector<int>(nums.begin(), nums.end() - 1));
		return max(rabStraightWithoutFirst, rabStraightWithoutLast);
	}

	int robStraight(const vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> noRob(nums.size()), rob(nums.size());
		noRob[0] = 0; rob[0] = nums[0];
		for (int i = 1; i < nums.size(); i++){
			noRob[i] = max(rob[i - 1], noRob[i - 1]);
			rob[i] = noRob[i - 1] + nums[i];
		}
		return max(noRob.back(), rob.back());
	}
};