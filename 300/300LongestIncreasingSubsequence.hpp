// 300 Longest Increasing Subsequence
// Given an unsorted array of integers, find the length of longest increasing subsequence.
// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
// Your algorithm should run in O(n2) complexity.
// Follow up: Could you improve it to O(n log n) time complexity?

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> lenSubseq(nums.size(), 1);
        int maxSubseq = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) lenSubseq[i] = max(lenSubseq[i],lenSubseq[j] + 1);
            }
            maxSubseq = max(maxSubseq, lenSubseq[i]);
        }
        return maxSubseq;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return (int)nums.size();
        vector<int> m(1,nums[0]);
        for(int i = 0; i < nums.size(); i++){
            m[0] = min(m[0], nums[i]);
            for(int j = (int)m.size() - 1; j >= 0; j--){
                if(nums[i] > m[j]) {
                    if(j == m.size() - 1) m.push_back(nums[i]);
                    else m[j+1] = min(m[j+1], nums[i]);
                    break;
                }
            }
        }
        return (int)m.size();
    }
};

// https://leetcode.com/discuss/67554/9-lines-c-code-with-o-nlogn-complexity
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for (int i = 0; i < nums.size(); i++) {
            if (LIS.size() == 0 || LIS[LIS.size() - 1] < nums[i]) {
                LIS.push_back(nums[i]);
            }
            else {
                int l = 0, r = LIS.size() - 1;
                while (l < r) {
                    int m = (l + r) / 2;
                    if (LIS[m] >= nums[i]) {
                        r = m;
                    }
                    else {
                        l = m + 1;
                    }
                }
                LIS[l] = nums[i];
            }
        }
        return LIS.size();
    }
};

// n2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> m;
        for (auto num : nums) {
            if (m.empty() || num > m.back()) m.push_back(num);
            else {
                int i = m.size() - 1;
                while (i > 0 && m[i-1] >= num) --i;
                m[i] = num;
            }
        }
        return m.size();
    }
};