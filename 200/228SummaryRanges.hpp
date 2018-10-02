// 228 Summary Ranges 
// Given a sorted integer array without duplicates, return the summary of its ranges.
// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> r;
        if(nums.empty()) return r;
        int start = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] + 1 == nums[i]) continue;
            if(i == start + 1) r.push_back(to_string(nums[start]));
            else r.push_back(string()+to_string(nums[start])+"->"+to_string(nums[i-1]));
            start = i;
        }
        if(nums.size() == start + 1) r.push_back(to_string(nums[start]));
        else r.push_back(to_string(nums[start])+"->"+to_string(nums.back()));
    }
}; 

vector<string> summaryRanges(vector<int>& nums) {
    const int size_n = nums.size();
    vector<string> res;
    if ( 0 == size_n) return res;
    for (int i = 0; i < size_n;) {
        int start = i, end = i;
        while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
        if (end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        else res.push_back(to_string(nums[start]));
        i = end+1;
    }
    return res;
}