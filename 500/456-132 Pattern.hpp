// 456. 132 Pattern
// Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.
// Note: n will be less than 15,000.
// Example 1:
// Input: [1, 2, 3, 4]
// Output: False
// Explanation: There is no 132 pattern in the sequence.
// Example 2:
// Input: [3, 1, 4, 2]
// Output: True
// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
// Example 3:
// Input: [-1, 3, 2, 0]
// Output: True
// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

// https://discuss.leetcode.com/topic/67881/single-pass-c-o-n-space-and-time-solution-8-lines-with-detailed-explanation
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> rs;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            if (nums[i] < s3) return true;
            while (rs.size() && nums[i] > rs.top()) { // A number becomes a candidate for s3 if there is any number on the left bigger than it.
                s3 = rs.top(); rs.pop();
            }
            rs.push(nums[i]);
        }
        return false;
    }
};

// https://discuss.leetcode.com/topic/67605/c-solution-in-o-n
class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		if (nums.size() < 3) return false;
		vector<int> minHereBefore(nums);
		for (int i = 1; i < nums.size(); ++i) {
			minHereBefore[i] = min(minHereBefore[i], minHereBefore[i - 1]);
		}
		// dp, worst case 2n to build
		vector<int> closestLarger(nums.size(), -1);
		for (int i = 1; i < nums.size(); ++i) {
			int j = i - 1;
			while (j != -1 && nums[j] <= nums[i]) j = closestLarger[j];
			closestLarger[i] = j;
		}
		for (int i = 1; i < nums.size(); ++i) {
			int j = closestLarger[i];
			if (j > 0 && minHereBefore[j - 1] < nums[i]) return true;
		}
		return false;
	}
};