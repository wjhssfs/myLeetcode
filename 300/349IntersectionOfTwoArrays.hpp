// 349. Intersection of Two Arrays
// Given two arrays, write a function to compute their intersection.
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
// Note:
// Each element in the result must be unique.
// The result can be in any order.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] == nums2[j]) {
                ret.push_back(nums1[i]);
                while (i < nums1.size() && nums1[i] == ret.back()) ++i;
                while (j < nums2.size() && nums2[j] == ret.back()) ++j;
            } else {
                ++j;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        for (auto num : s1) {
            if (s2.count(num)) {
                ret.push_back(num);
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        sort(begin(nums1), end(nums1));
        unordered_set<int> s;
        for (auto num : nums2) {
            if (binary_search(begin(nums1), end(nums1), num)) s.insert(num);
        }
        return vector<int>{begin(s), end(s)};
    }
};