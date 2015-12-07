// 163 Missing Ranges

// Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

// For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> r;
        if(nums.empty()) {
            addToResult(r, lower, upper);
            return r;
        }
        
        if(lower < nums[0]) {
            addToResult(r, lower, nums[0]-1);
        }
        for(int i = 1; i < (int)nums.size(); i++){
            if(nums[i] > nums[i-1]+1) addToResult(r, nums[i-1] + 1, nums[i]-1);
        }
        if(upper > nums.back()){
            addToResult(r, nums.back()+1, upper);
        }
        return r;
    }
private:
    void addToResult(vector<string> &r, int start, int end){
        string s;
        if(start == end){
            s = to_string(start);   
        } else {
            s = to_string(start) + "->" + to_string(end);
        }
        r.push_back(s);
    }
};