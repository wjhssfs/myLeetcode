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

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

// O(n)
public List<Integer> topKFrequent(int[] nums, int k) {

    List<Integer>[] bucket = new List[nums.length + 1];
    Map<Integer, Integer> frequencyMap = new HashMap<Integer, Integer>();

    for (int n : nums) {
        frequencyMap.put(n, frequencyMap.getOrDefault(n, 0) + 1);
    }

    for (int key : frequencyMap.keySet()) {
        int frequency = frequencyMap.get(key);
        if (bucket[frequency] == null) {
            bucket[frequency] = new ArrayList<>();
        }
        bucket[frequency].add(key);
    }

    List<Integer> res = new ArrayList<>();

    for (int pos = bucket.length - 1; pos >= 0 && res.size() < k; pos--) {
        if (bucket[pos] != null) {
            res.addAll(bucket[pos]);
        }
    }
    return res;
}

class Solution(object):        
    def topKFrequent(self, nums, k):
        bucket = [[] for _ in nums]
        for num, freq in collections.Counter(nums).items():
            bucket[len(nums) - freq].append(num)
        return list(itertools.chain(*bucket))[:k]