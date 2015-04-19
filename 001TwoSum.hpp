// 1 Two Sum
// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2


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

/*
 Solution: 1. Sort first. O(nlgn)
           2. Hash table. O(n)
           
 Note:  Hash Table solution has been updated.  In case that the two elements are the same, 
        all the indices should be stored in the map.
 */

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        return twoSum_1(numbers, target);
    }
    
    vector<int> twoSum_1(vector<int> &numbers, int target) {
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

        vector<int> res;
        res.push_back(min(nums[l].second, nums[r].second));
        res.push_back(max(nums[l].second, nums[r].second));
        return res;
    }
    
    typedef unordered_map<int, vector<int> > MAP;
    
    vector<int> twoSum_2(vector<int> &numbers, int target) {
        MAP map;
        for (int i = 0; i < numbers.size(); ++i)
            map[numbers[i]].push_back(i+1);
        
        for (int i = 0; i < numbers.size(); ++i)
        {
            MAP::iterator it = map.find(target - numbers[i]);
            if (it == map.end()) continue;
            
            int index1 = it->second[0], index2 = i + 1;
            
            if (numbers[i] == target - numbers[i]) { // two elements are the same
                if (it->second.size() == 1) continue;
                index2 = it->second[1];
            }
            
            vector<int> res;
            res.push_back(min(index1, index2));
            res.push_back(max(index1, index2));
            return res;
        }
    }
};
