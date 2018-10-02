// 697. Degree of an Array

// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

// Example 1:
// Input: [1, 2, 2, 3, 1]
// Output: 2
// Explanation: 
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.
// Example 2:
// Input: [1,2,2,3,1,4,2]
// Output: 6
// Note:

// nums.length will be between 1 and 50,000.
// nums[i] will be an integer between 0 and 49,999.

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, vector<int>> m;
		int maxD = 0, minLen = 1;
		for (int i = 0; i < nums.size(); ++i) {
			if (m.count(nums[i])) {
				m[nums[i]] = { m[nums[i]][0] + 1, m[nums[i]][1], i };
				if (m[nums[i]][0] > maxD)
				{
					maxD = m[nums[i]][0];
					minLen = INT_MAX;
				}
				if (m[nums[i]][0] >= maxD)
				{
					minLen = min(minLen, m[nums[i]][2] - m[nums[i]][1] + 1);
				}
			}
			else {
				m[nums[i]] = { 1, i, i };
			}
		}
		return minLen;
	}
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> freq;
        map<int, int> minidx;
        map<int, int> maxidx;
        int b = 0;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            b = max(b, freq[nums[i]]);
            if (minidx.find(nums[i]) == minidx.end()) {
                minidx[nums[i]] = i;
            }
            maxidx[nums[i]] = i;
        }
        int res = nums.size();
        for (auto item : freq) {
            if (item.second == b) {
                res = min(res, maxidx[item.first] - minidx[item.first] + 1);
            }
        }
        return res;
    }
};