// 128 Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
// 
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
// 
// Your algorithm should run in O(n) complexity.

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_map<int, int> uii;
		int maxlen=0;
		for (auto &val : num) {
			if (uii.find(val) != uii.end()) continue;
			uii[val] = 1;
			int leftbound = 0;
			if (val != INT_MIN && uii.find(val - 1)!=uii.end()) leftbound = uii[val - 1];
			int rightbound = 0;
			if (val != INT_MAX && uii.find(val + 1) != uii.end()) rightbound = uii[val + 1];
			uii[val - leftbound] = uii[val + rightbound] = 1 + leftbound + rightbound;
			maxlen = max(maxlen, 1 + leftbound + rightbound);
		}
		return maxlen;
	}
};

