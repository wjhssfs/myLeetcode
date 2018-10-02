// 898. Bitwise ORs of Subarrays

// We have an array A of non-negative integers.

// For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j), we take the bitwise OR of all the elements in B, obtaining a result A[i] | A[i+1] | ... | A[j].

// Return the number of possible results.  (Results that occur more than once are only counted once in the final answer.)


// Example 1:

// Input: [0]
// Output: 1
// Explanation: 
// There is only one possible result: 0.
// Example 2:

// Input: [1,1,2]
// Output: 3
// Explanation: 
// The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
// These yield the results 1, 1, 2, 1, 3, 3.
// There are 3 unique values, so the answer is 3.
// Example 3:

// Input: [1,2,4]
// Output: 6
// Explanation: 
// The possible results are 1, 2, 3, 4, 6, and 7.
 

// Note:

// 1 <= A.length <= 50000
// 0 <= A[i] <= 10^9

// https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss/165881/C++JavaPython-O(30N)
// This solution has only O(30N)

// The reason is that, B[0][i] >= B[1][i] >= ... >= B[i][i].
// B[0][i] covers all bits of B[1][i]
// B[1][i] covers all bits of B[2][i]
// ....

// There are at most 30 bits for a positive number 0 <= A[i] <= 10^9.
// So there are at most 30 different values for B[0][i], B[1][i], B[2][i], ..., B[i][i].
// Finally cur.size() <= 30 and res.size() <= 30 * A.length()

// In a worst case, A = {1,2,4,8,16,..., 2 ^ 29}

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, cur, cur2;
        for (int i: A) {
            cur2 = {i};
            for (int j: cur) cur2.insert(i|j);
            res.insert(cur2.begin(), cur2.end());
            swap(cur, cur2);
        }
        return res.size();
    }
};