// 163 Missing Ranges
// Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.
// For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int nextExp = lower;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > nextExp) res.emplace_back(GetRange(nextExp, nums[i] - 1));
            if (nums[i] == INT_MAX) return res;
            nextExp = nums[i] + 1;
        }
        if (nextExp <= upper) res.emplace_back(GetRange(nextExp, upper));
        return res;
    }
private:
    string GetRange(int start, int end) {
        if (start == end) return to_string(start);
        else return to_string(start) + "->" + to_string(end);
    }
};