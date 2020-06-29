// 945. Minimum Increment to Make Array Unique

// Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

// Return the least number of moves to make every value in A unique.

 

// Example 1:

// Input: [1,2,2]
// Output: 1
// Explanation:  After 1 move, the array could be [1, 2, 3].
// Example 2:

// Input: [3,2,1,2,1,7]
// Output: 6
// Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
// It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
 

// Note:

// 0 <= A.length <= 40000
// 0 <= A[i] < 40000

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        sort(begin(A), end(A));
        int nD = 0, res = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i - 1]) {
                ++nD;  
            } else {
                for (int j = A[i - 1] + 1; j < A[i] && nD; ++j) {
                    res += nD--;
                }
                res += nD;
            }
        }
        return res + (nD + 1) * nD / 2;
    }
};