// 523. Continuous Subarray Sum

// Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

// Example 1:
// Input: [23, 2, 4, 6, 7],  k=6
// Output: True
// Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
// Example 2:
// Input: [23, 2, 6, 4, 7],  k=6
// Output: True
// Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
// Note:
// The length of the array won't exceed 10,000.
// You may assume the sum of all the numbers is in the range of a signed 32-bit integer.


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        int sum = nums[0];
        unordered_set<int> m;
        m.insert(0);
        for (int i = 1; i < nums.size(); ++i) {
            int temp = sum;
            sum += nums[i];
            if (m.count(k ? sum % k : sum)) return true;
            m.insert(k ? temp % k : temp);
        }
        return false;
    }
};

public boolean checkSubarraySum(int[] nums, int k) {
    Map<Integer, Integer> map = new HashMap<Integer, Integer>(){{put(0,-1);}};;
    int runningSum = 0;
    for (int i=0;i<nums.length;i++) {
        runningSum += nums[i];
        if (k != 0) runningSum %= k; 
        Integer prev = map.get(runningSum);
        if (prev != null) {
            if (i - prev > 1) return true;
        }
        else map.put(runningSum, i);
    }
    return false;
}


Bug 
[1, 2147483646]
0
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        k = abs(k);
        if (!k) k = INT_MAX;
        int sum = nums[0];
        unordered_set<int> m;
        m.insert(0);
        for (int i = 1; i < nums.size(); ++i) {
            int temp = sum;
            sum += nums[i];
            if (m.count(sum % k)) return true;
            m.insert(temp % k);
        }
        return false;
    }
};