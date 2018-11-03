// 416. Partition Equal Subset Sum
// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.
// Example 1:

// Input: [1, 5, 11, 5]

// Output: true

// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: [1, 2, 3, 5]

// Output: false

// Explanation: The array cannot be partitioned into equal sum subsets.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (auto num : nums) totalSum += num;
        if (totalSum % 2) return false;
        
        sort(nums.rbegin(), nums.rend());
        return canPartition(nums, 1, nums[0], totalSum / 2);
    }
private:
    bool canPartition(vector<int>& nums, int start, int sum, int target) {
        if (start == nums.size()) return sum == target;
        if (sum + nums[start] <= target) {
            if (canPartition(nums, start + 1, sum + nums[start], target)) return true;
        } 
        return canPartition(nums, start + 1, sum, target);
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int half = sum >> 1;
        
        vector<bool> accessibility(half + 1, false);
        accessibility[0] = true;    // '0' is always reachable
        //For all num in nums, check the accessibility from half - num to 0. 
        //If 'i' is accessible by former numbers, then 'i + num' is also accessible. (DP Algorithm)
        for(auto num : nums) 
       //Below here we must start from 'half' downto 'num', otherwise current 'num' might be multiply used. 
       //e.g.: If num == 2, then we will have 2, 4, 6... will all be accessible and lead to wrong answer. 
            for(int i = half; i >= num; i--){
                if (accessibility[i - num] == true){
                    accessibility[i] = true;
                }
            }
        return accessibility[half];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bits |= bits << n;
        }
        return !(sum % 2) && bits[sum / 2];
    }
};

// 0/1 knapsack
// Base case: dp[0][0] is true; (zero number consists of sum 0 is true)
// The transition function is dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
public boolean canPartition(int[] nums) {
    int sum = 0;
    
    for (int num : nums) {
        sum += num;
    }
    
    if ((sum & 1) == 1) {
        return false;
    }
    sum /= 2;

    int n = nums.length;
    boolean[][] dp = new boolean[n+1][sum+1];
    for (int i = 0; i < dp.length; i++) {
        Arrays.fill(dp[i], false);
    }
    
    dp[0][0] = true;
    
    for (int i = 1; i < n+1; i++) {
        dp[i][0] = true;
    }
    for (int j = 1; j < sum+1; j++) {
        dp[0][j] = false;
    }
    
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < sum+1; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= nums[i-1]) {
                dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
            }
        }
    }
   
    return dp[n][sum];
}