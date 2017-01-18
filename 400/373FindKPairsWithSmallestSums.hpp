// 373. Find K Pairs with Smallest Sums
// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
// Define a pair (u,v) which consists of one element from the first array and one element from the second array.
// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
// Example 1:
// Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
// Return: [1,2],[1,4],[1,6]
// The first 3 pairs are returned from the sequence:
// [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// Example 2:
// Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
// Return: [1,1],[1,1]
// The first 2 pairs are returned from the sequence:
// [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// Example 3:
// Given nums1 = [1,2], nums2 = [3],  k = 3 
// Return: [1,3],[2,3]
// All possible pairs are returned from the sequence:
// [1,3],[2,3]
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ret;
        if (nums1.empty() || nums2.empty()) return ret;
        auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {
        	return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        set<pair<int, int>> s;
        q.push(make_pair(0, 0));
        while(!q.empty() && ret.size() < k) {
        	auto top = q.top(); q.pop();
        	ret.push_back(make_pair(nums1[top.first], nums2[top.second]));
        	if (top.first < nums1.size() - 1 && !s.count(make_pair(top.first+1, top.second))) {
        		q.push(make_pair(top.first+1, top.second));
        		s.insert(make_pair(top.first+1, top.second));
        	}
        	if (top.second < nums2.size() - 1 && !s.count(make_pair(top.first, top.second + 1))) {
        		q.push(make_pair(top.first, top.second + 1));
        		s.insert(make_pair(top.first, top.second + 1));
        	}
        }
        return ret;
    }
};

// get rid of set
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ret;
        if (nums1.empty() || nums2.empty()) return ret;
        auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {
        	return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        q.push(make_pair(0, 0));
        while(!q.empty() && ret.size() < k) {
        	auto top = q.top(); q.pop();
        	ret.push_back(make_pair(nums1[top.first], nums2[top.second]));
        	if (top.second < nums2.size() - 1) {
        		q.push(make_pair(top.first, top.second + 1));
        	}
        	if (top.second == 0 && top.first < nums1.size() - 1) {
        		q.push(make_pair(top.first + 1, top.second));
        	}
        }
        return ret;
    }
};

class Solution {
private:
    struct mycompare{
        bool operator()(pair<int, int>& p1, pair<int, int>& p2){
            return p1.first + p1.second < p2.first + p2.second;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        priority_queue<pair<int,int>, vector<pair<int, int> >, mycompare> pq;
        for(int i = 0; i < min((int)nums1.size(), k); i++){
            for(int j = 0; j < min((int)nums2.size(), k); j++){
                if(pq.size() < k)
                    pq.push(make_pair(nums1[i], nums2[j]));
                else if(nums1[i] + nums2[j] < pq.top().first + pq.top().second){
                    pq.push(make_pair(nums1[i], nums2[j]));
                    pq.pop();
                }
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

class Solution {
public:
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        k = min(k, m * n);
        vector<int> indice(m, 0);
        while(k-- > 0){
            int tmp_index = 0;
            long tmp_sum = LONG_MAX;
            for(int i = 0; i < m; i++){
                if(indice[i] < n && tmp_sum >= nums1[i] + nums2[indice[i]]){
                    tmp_index = i;
                    tmp_sum = nums1[i] + nums2[indice[i]];
                }
            }
            res.push_back(make_pair(nums1[tmp_index], nums2[indice[tmp_index]]));
            indice[tmp_index]++;
        }
        return res;
    }
};

// https://discuss.leetcode.com/topic/50450/slow-1-liner-to-fast-solutions/2
def kSmallestPairs(self, nums1, nums2, k):
    queue = []
    def push(i, j):
        if i < len(nums1) and j < len(nums2):
            heapq.heappush(queue, [nums1[i] + nums2[j], i, j])
    push(0, 0)
    pairs = []
    while queue and len(pairs) < k:
        _, i, j = heapq.heappop(queue)
        pairs.append([nums1[i], nums2[j]])
        push(i, j + 1)
        if j == 0: // If we don't do anything against duplicates, then for example cell (5, 5) could get reached from (4, 5) or from (5, 4), right? I just made a decision. Only (5, 4) leads to (5, 5). I only expand in rows and in the first column (where j=0).
            push(i + 1, 0)
    return pairs

// It turns each row into a generator of triples [u+v, u, v], only computing the next when asked for one.
// http://stackoverflow.com/questions/20860181/itertools-imap-vs-map-over-the-entire-iterable
 def kSmallestPairs(self, nums1, nums2, k):
    streams = map(lambda u: ([u+v, u, v] for v in nums2), nums1)
    stream = heapq.merge(*streams)
    return [suv[1:] for suv in itertools.islice(stream, k)]

// for 3 nums
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, vector<int> &nums3) {
        vector<vector<int>> res;
        auto cmp = [&](const vector<int> &a, const vector<int> &b){
            int sumA = nums1[a[0]] + nums2[a[1]] + nums3[a[2]];
            int sumB = nums1[b[0]] + nums2[b[1]] + nums3[b[2]];
            return sumA > sumB;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            vector<int> top = pq.top(); pq.pop();
            int i = top[0], j = top[1], k = top[2];
            res.push_back({nums1[i], nums2[j], nums3[k]});
            if (k + 1 < (int)nums3.size())pq.push({i, j, k+1});
            if (j == 0 && k == 0 && i + 1 < (int)nums1.size()) {
                pq.push({i + 1, j, k});
            }
            if (k == 0 && j + 1 < nums2.size()) {
                pq.push({i, j + 1, k});
            }
        }
        return res;
    }
};