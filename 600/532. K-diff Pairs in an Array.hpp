// 532. K-diff Pairs in an Array

// Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

// Example 1:
// Input: [3, 1, 4, 1, 5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.
// Example 2:
// Input:[1, 2, 3, 4, 5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
// Example 3:
// Input: [1, 3, 1, 5, 4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).
// Note:
// The pairs (i, j) and (j, i) count as the same pair.
// The length of the array won't exceed 10,000.
// All the integers in the given input belong to the range: [-1e7, 1e7].
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0, j = 1; i < nums.size(); ++i) {
		    for (j = max(i+1, j); j < nums.size() && nums[j] - nums[i] < k; ++j);
		    if (j < nums.size() && nums[j] - nums[i] == k) ++res;
		    while (i + 1 < nums.size() && nums[i] == nums[i+1]) ++i;
		}
		return res;
	}
};

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;
		unordered_map<int, int> m;
		for (auto num : nums) ++m[num];
		int total = 0;
		for (auto &&entry : m) {
			if (k == 0 && entry.second > 1) ++total;
			else if (k > 0 && m.count(entry.first + k)) ++total;
		}
		return total;
	}
};


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_set<int> m, n;
        for (auto num : nums) {
            if (m.count(num - k)) {
                if (!n.count(num - k)) n.insert(num - k);
            }
            if (k && m.count(num + k)) {
                if (!n.count(num)) n.insert(num);
            }
            m.insert(num);
        }
        return n.size();
    }
};