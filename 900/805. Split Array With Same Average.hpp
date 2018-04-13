// 805. Split Array With Same Average

// In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)

// Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.

// Example :
// Input: 
// [1,2,3,4,5,6,7,8]
// Output: true
// Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
// Note:

// The length of A will be in the range [1, 30].
// A[i] will be in the range of [0, 10000].

// https://leetcode.com/problems/split-array-with-same-average/discuss/120667/C++-Solution-with-explanation-early-termination-(Updated-for-new-test-case)
// sums[i+1][j] = sums[i][j] “join” (sums[i][j-1] + A[i+1])

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), m = n/2, totalSum = accumulate(A.begin(), A.end(), 0);
        // early pruning
        bool isPossible = false;
        for (int i = 1; i <= m && !isPossible; ++i) 
            if (totalSum*i%n == 0) isPossible = true;
        if (!isPossible) return false;
        // DP like knapsack
        vector<unordered_set<int>> sums(m+1);
        sums[0].insert(0);
        for (int num: A) {
            for (int i = m; i >= 1; --i) 
                for (const int t: sums[i-1]) 
                    sums[i].insert(t + num);
        }
        for (int i = 1; i <= m; ++i) 
            if (totalSum*i%n == 0 && sums[i].find(totalSum*i/n) != sums[i].end()) return true;
        return false;
    }
};