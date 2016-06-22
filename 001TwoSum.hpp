// 1 Two Sum
// Given an array of integers, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target,
// where index1 must be less than index2. Please note that your returned answers
// (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution.
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

// Hash map, O(n) space, O(n) time
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int,int> m;
		for (size_t i = 0; i != numbers.size(); i++){
			if (m.count(numbers[i])) return{ m[numbers[i]]+1, (int)i +1};
			else m[target - numbers[i]] = i;
		}
	}
};

// Sort first. O(nlgn) time, reuse space used by parameter.
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

class Solution2 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int>> nums(numbers.size());
        for (int i = 0; i < numbers.size(); ++i)
            nums[i] = make_pair(numbers[i], i+1);
        sort(nums.begin(), nums.end(), compare);
        
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[l].first + nums[r].first;
            if (sum == target) break;
            else if (sum < target) l++;
            else r--;
        }

        return {min(nums[l].second, nums[r].second), max(nums[l].second, nums[r].second)};
    }
};
