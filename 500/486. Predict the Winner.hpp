// 486. Predict the Winner

// Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

// Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

// Example 1:
// Input: [1, 5, 2]
// Output: False
// Explanation: Initially, player 1 can choose between 1 and 2. 
// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
// Hence, player 1 will never be the winner and you need to return False.
// Example 2:
// Input: [1, 5, 233, 7]
// Output: True
// Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
// Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
// Note:
// 1 <= length of the array <= 20.
// Any scores in the given array are non-negative integers and will not exceed 10,000,000.
// If the scores of both players are equal, then player 1 is still the winner.
// Show Company Tags
// Show Tags
// Show Similar Problems

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		if (n % 2) return true;
		vector<vector<int>> dp(n, vector<int>(n));
		vector<int> sums{ 0 };
		for (int i = 0; i < n; ++i) sums.push_back(sums.back() + nums[i]);
		for (int i = n-1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				if (i == j) dp[j][j] = nums[j];
				else {
					int left = sums[j + 1] - sums[i + 1] - dp[i + 1][j] + nums[i];
					int right = sums[j] - sums[i] - dp[i][j - 1] + nums[j];
					dp[i][j] = max(left, right);
				}
			}
		}
		return sums[n] <= dp[0][n - 1] * 2;
	}
};

public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        return helper(nums, 0, nums.length-1)>=0;
    }
    private int helper(int[] nums, int s, int e){        
        return s==e ? nums[e] : Math.max(nums[e] - helper(nums, s, e-1), nums[s] - helper(nums, s+1, e));
    }
}

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()% 2 == 0) return true; // keep picking odd or even.
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int myBest = utill(nums, dp, 0, n-1);
        return 2*myBest >= accumulate(nums.begin(), nums.end(), 0);
    }
    
    int utill(vector<int>& v, vector<vector<int>> &dp, int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = v[i] + min(utill(v,dp, i+1, j-1), utill(v, dp, i+2, j));
        int b = v[j] + min(utill(v,dp,i, j-2), utill(v,dp, i+1, j-1));
        dp[i][j] = max(a, b);
                        
        return dp[i][j];
    }
};


// The dp[i][j] saves how much more scores that the first-in-action player will get from i to j than the second player.
// First-in-action means whomever moves first. You can still make the code even shorter but I think it looks clean in this way.
public boolean PredictTheWinner(int[] nums) {
    int n = nums.length;
    int[][] dp = new int[n][n];
    for (int i = 0; i < n; i++) { dp[i][i] = nums[i]; }
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= 0;
}
Here is the code for O(N) space complexity:


public boolean PredictTheWinner(int[] nums) {
    if (nums == null) { return true; }
    int n = nums.length;
    if ((n & 1) == 0) { return true; } // Improved with hot13399's comment.
    int[] dp = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i] = nums[i];
            } else {
                dp[j] = Math.max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
    }
    return dp[n - 1] >= 0;
}