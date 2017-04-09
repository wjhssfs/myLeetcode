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