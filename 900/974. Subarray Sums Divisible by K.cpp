// 974. Subarray Sums Divisible by K
// Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

// Example 1:

// Input: A = [4,5,0,-2,-3,1], K = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by K = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

// Note:

// 1 <= A.length <= 30000
// -10000 <= A[i] <= 10000
// 2 <= K <= 10000

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0, sum = 0;
        for (auto a : A) {
        	sum = ((sum + a) % K + K) % K;    
        	res += m[sum];
        	++m[sum];
        }
        return res;
    }
};