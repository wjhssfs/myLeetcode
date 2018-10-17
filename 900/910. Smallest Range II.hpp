// 910. Smallest Range II
// Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

// After this process, we have some array B.

// Return the smallest possible difference between the maximum value of B and the minimum value of B.

 

// Example 1:

// Input: A = [1], K = 0
// Output: 0
// Explanation: B = [1]
// Example 2:

// Input: A = [0,10], K = 2
// Output: 6
// Explanation: B = [2,8]
// Example 3:

// Input: A = [1,3,6], K = 3
// Output: 3
// Explanation: B = [4,6,3]
 

// Note:

// 1 <= A.length <= 10000
// 0 <= A[i] <= 10000
// 0 <= K <= 10000

// https://leetcode.com/problems/smallest-range-ii/discuss/173389/simple-C++-solution-with-explanation
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(begin(A), end(A));
        int rDiff = A.back() - A.front(), minR = A[0] + 2 * K;
        for (int i = 0; i < A.size() - 1; ++i) {
            int curR = A[i] + 2 * K;
            int minV = min(minR, A[i + 1]);
            int maxV = max(curR, A.back());
            rDiff = min(rDiff, maxV - minV);
        }
        return rDiff;
    }
};