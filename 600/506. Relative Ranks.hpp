// 506. Relative Ranks

// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

// Example 1:
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
// For the left two athletes, you just need to output their relative ranks according to their scores.
// Note:
// N is a positive integer and won't exceed 10,000.
// All the scores of athletes are guaranteed to be unique.
// Show Company Tags

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size());
        vector<int> seq;
        for (int i = 0; i < nums.size(); ++i) seq.push_back(i);
        sort(seq.begin(), seq.end(), [&](int a, int b) {return nums[a] > nums[b];});
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) res[seq[i]] = "Gold Medal";
            else if (i == 1) res[seq[i]] = "Silver Medal";
            else if (i == 2) res[seq[i]] = "Bronze Medal";
            else res[seq[i]] = to_string(i + 1);
        }
        return res;
    }
};