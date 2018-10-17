// 918. Maximum Sum Circular Subarray
// Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

// Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

// Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

// Example 1:

// Input: [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3
// Example 2:

// Input: [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
// Example 3:

// Input: [3,-1,2,-1]
// Output: 4
// Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
// Example 4:

// Input: [3,-2,2,-3]
// Output: 3
// Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
// Example 5:

// Input: [-2,-3,-1]
// Output: -1
// Explanation: Subarray [-1] has maximum sum -1
 

// Note:

// -30000 <= A[i] <= 30000
// 1 <= A.length <= 30000

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int start = 0, curSum = 0, res = A[0];
        for (int i = 0; i < A.size() * 2 - 1 && start < A.size(); ++i) {
            if (curSum + A[i % A.size()] <= A[i % A.size()]) {
                start = i;
                curSum = A[i % A.size()];
            } else curSum = curSum + A[i % A.size()];
            res = max(res, curSum);
            if (i - start + 1 == A.size()) {
                while(start < i && A[start] >= 0) curSum -= A[start++];
                while (start < i && A[start] <= 0) curSum -= A[start++];
                i = start - 1;
                curSum = 0;
            }
        }
        return res;
    }
};

// https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/C++JavaPython-One-Pass
// max subarray circular sum equals to max(the max subarray sum, the total sum - the min subarray sum)
   int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = -30000, curMax = 0, minSum = 30000, curMin = 0;
        for (int a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }