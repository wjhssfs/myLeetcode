// 354. Russian Doll Envelopes
// You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and
// only if both the width and height of one envelope is greater than the width and height of the other envelope.
// What is the maximum number of envelopes can you Russian doll? (put one inside other)
// Example:
// Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() <= 1) return envelopes.size();
        int maxEnvelopes = 1;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        for (int i = 1; i < (int)envelopes.size(); ++i) {
            for (int j = i - 1; j >=0; --j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxEnvelopes = max(maxEnvelopes, dp[i]);
        }
        return maxEnvelopes;
    }
};

// Sort the array. Ascend on width and descend on height if width are same.
// Find the longest increasing subsequence based on height.
// Since the width is increasing, we only need to consider height.
// [3, 4] cannot contains [3, 3], so we need to put [3, 4] before [3, 3] when sorting otherwise it will be counted as an increasing number if the order is [3, 3], [3, 4]
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) 
    {
        int size = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int>b){
            return a.first<b.first || (a.first==b.first && a.second>b.second);
        });
        vector<int> collector;
        for(auto& pair: envelopes)
        {
            auto iter = lower_bound(collector.begin(), collector.end(), pair.second);
            if(iter == collector.end()) collector.push_back(pair.second);
            else if(*iter > pair.second) *iter = pair.second;
        }
        return collector.size();
    }
};