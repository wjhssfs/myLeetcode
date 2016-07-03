// 347. Top K Frequent Elements
// Given a non-empty array of integers, return the k most frequent elements.
// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numToCount;
        for (auto num : nums) {
            ++numToCount[num];
        }
        auto cmp = [](pair<int, int> &left, pair<int, int> &right) {
            return left.second > right.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto record : numToCount) {
            pq.push(record);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};