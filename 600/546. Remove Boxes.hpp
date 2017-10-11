// 546. Remove Boxes

// Given several boxes with different colors represented by different positive numbers. 
// You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
// Find the maximum points you can get.

// Example 1:
// Input:

// [1, 3, 2, 2, 2, 3, 4, 3, 1]
// Output:
// 23
// Explanation:
// [1, 3, 2, 2, 2, 3, 4, 3, 1] 
// ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
// ----> [1, 3, 3, 3, 1] (1*1=1 points) 
// ----> [1, 1] (3*3=9 points) 
// ----> [] (2*2=4 points)
// Note: The number of boxes n would not exceed 100.

// https://discuss.leetcode.com/category/701/remove-boxes
// m[l][r][k] the largest number we can get using lth to rth (inclusive) boxes with k same colored boxes as rth box appended at the end.
// Example, m[l][r][3] represents the solution for this setting: [b_l, ..., b_r, A,A,A] with b_r==A.
class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
	    if (boxes.empty()) return 0;
		int m[100][100][100]= {};
		return dfs(boxes, m, 0, boxes.size() - 1, 0);
	}
private:
    int dfs(vector<int>& boxes, int m[100][100][100], int l, int r, int k) {
        if (l > r) return 0;
        if (m[l][r][k] != 0) return m[l][r][k];
        while (r > l && boxes[r] == boxes[r - 1]) {
            --r;
            ++k;
        }
        m[l][r][k] = max(m[l][r][k], dfs(boxes, m, l, r - 1, 0) + (k + 1) * (k + 1));
        for (int i = l; i < r - 1; ++i) {
            if (boxes[i] == boxes[r] && boxes[i + 1] != boxes[r]) {
            	// if we found same color box,
                // then we have a chance to get a higher value by group boxes[l]~boxes[i] and boxes[r] together, plus the 
                // value from boxes[i+1]~boxes[r-1]
                m[l][r][k] = max(m[l][r][k], dfs(boxes, m, l, i, k + 1) + dfs(boxes, m, i + 1, r - 1, 0));
            }
        }
        return m[l][r][k];
    }
};

// https://discuss.leetcode.com/topic/84687/java-top-down-and-bottom-up-dp-solutions/2
// modify the definition of the problem to absorb the external information so that the new one is self-contained.
// Bottom-up DP
public int removeBoxes(int[] boxes) {
    int n = boxes.length;
    int[][][] dp = new int[n][n][n];
        
    for (int j = 0; j < n; j++) {
        for (int k = 0; k <= j; k++) {
            dp[j][j][k] = (k + 1) * (k + 1);
        }
    }
        
    for (int l = 1; l < n; l++) {
        for (int j = l; j < n; j++) {
            int i = j - l;
                
            for (int k = 0; k <= i; k++) {
                int res = (k + 1) * (k + 1) + dp[i + 1][j][0];
                    
                for (int m = i + 1; m <= j; m++) {
                    if (boxes[m] == boxes[i]) {
                        res = Math.max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                    }
                }
                    
                dp[i][j][k] = res;
            }
        }
    }
    
    return (n == 0 ? 0 : dp[0][n - 1][0]);
}

// "leetcode 312. Burst Balloons", the external information to subarray nums[i, j] is the two numbers (denoted as left and right) adjacent to nums[i] and nums[j], respectively. 