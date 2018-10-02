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

class Solution {
    bool dfs(vector<int>& A, int nLeft, int target, int cur, int start) {
        if (nLeft == 0) return cur == target;
        for (size_t i = start; i < A.size() && A[i] + cur <= target; ++i) {
            if (i > start && A[i] == A[i-1]) continue;
            if (dfs(A, nLeft - 1, target, cur + A[i], i + 1)) return true;
        }
        return false;
    }
public:
    bool splitArraySameAverage(vector<int>& A) {
        auto sz = A.size();
        sort(A.begin(), A.end());
        auto total = accumulate(A.begin(), A.end(), 0);
        for (size_t i = 1; i <= sz / 2; ++i) {
            if (total * i % sz != 0) continue;
            int sumA = total * i / sz;
            if (dfs(A, i, sumA, 0, 0)) return true;
        }
        return false;
    }
};