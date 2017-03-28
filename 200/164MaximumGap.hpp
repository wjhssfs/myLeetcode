// 164 Maximum Gap 
// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
// Try to solve it in linear time/space.
// Return 0 if the array contains less than 2 elements.
// You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

// The key is to use the fact that the lower bound of the gap is (maxV - minV )/ (sSize - 1).
// Put all numbers in buckets with size (maxV - minV )/ (sSize - 1)
// Apply pigeonhole principle, the max gap cannot be inside a bucket.

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        auto minMax = minmax_element(nums.begin(), nums.end());
        int minV = *minMax.first, maxV = *minMax.second;
        if (nums.size() == 2 || maxV == minV) return maxV - minV;
        int bucketSize = max(1, (int)((maxV - minV) / (nums.size() - 1)));
        vector<pair<int, int>> buckets((maxV - minV)/bucketSize + 1, pair<int, int>(INT_MAX, INT_MIN));
        for_each(nums.begin(), nums.end(), [&](int n) {
           int p = (n - minV) / bucketSize;
           buckets[p].first = min(buckets[p].first, n); 
           buckets[p].second = max(buckets[p].second, n);
        });
        
        auto it = find_if(buckets.begin(), buckets.end(), [](pair<int, int> &b){
            return b.first <= b.second;
        });
        auto p = *it;
        int maxGap = 0;
        for_each(it + 1, buckets.end(), [&](pair<int, int> &b) {
           if (b.first <= b.second) {
               maxGap = max(maxGap, b.first - p.second);
               p = b;
           }
        });
        return maxGap;
    }
};

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int m = num.size();
        if (m < 2) return 0;
        auto minmax = minmax_element(num.begin(), num.end());
        int minV = *minmax.first, maxV = *minmax.second;
        if (m == 2) return maxV - minV;        
        int bucketSize = std::floor(double(maxV - minV) / (m - 1));
        // need to get the size this way to make sure no out of range indexing
        vector<Bucket> buckets((maxV - minV)/bucketSize + 1);
        for_each(num.begin(), num.end(), [&](int n){
            int p = (n - minV) / bucketSize;
            buckets[p].lower = min(buckets[p].lower, n);
            buckets[p].upper = max(buckets[p].upper, n);
        });
        auto it = find_if(buckets.begin(), buckets.end(), [](Bucket & b)
        {return b.lower <= b.upper; });         
        Bucket pre = *it;
        int maxGap = 0;
        for_each(it+1, buckets.end(), [&](Bucket & b){
            if (b.lower <= b.upper){
                maxGap = max(maxGap, b.lower - pre.upper);
                pre = b;
            }
        });
        return maxGap;        
    }
    struct Bucket
    {
        Bucket() :upper(INT_MIN), lower(INT_MAX){};
        int upper, lower;
    };
};