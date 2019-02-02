// 977. Squares of a Sorted Array
// Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

// Example 1:

// Input: [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Example 2:

// Input: [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
 

// Note:

// 1 <= A.length <= 10000
// -10000 <= A[i] <= 10000
// A is sorted in non-decreasing order.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res (A.size());
        for(int l = 0, r = A.size() - 1, t = r; t >= 0; --t) {
            res[t] = abs(A[l]) < abs(A[r]) ? A[r--] : A[l++];
            res[t] *= res[t];
        }
        return res;
    }
};