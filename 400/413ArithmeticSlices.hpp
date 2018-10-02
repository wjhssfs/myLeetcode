// 413. Arithmetic Slices
// A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
// For example, these are arithmetic sequence:
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.
// 1, 1, 2, 5, 7
// A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
// A slice (P, Q) of array A is called arithmetic if the sequence:
// A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
// The function should return the number of arithmetic slices in the array A.
// Example:
// A = [1, 2, 3, 4]
// return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sz = A.size();
        int start = 0, total = 0;
        while (start < sz - 2) {
            int diff = A[start + 1] - A[start];
            int end = start + 2;
            while (end < sz && A[end] - A[end - 1] == diff) ++end;
            int len = end - start;
            total += (len - 2) * (len - 1) / 2;
            start = end - 1;
        }
        return total;
    }
};

public int numberOfArithmeticSlices(int[] A) {
    int curr = 0, sum = 0;
    for (int i=2; i<A.length; i++)
        if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
            curr += 1;
            sum += curr;
        } else {
            curr = 0;
        }
    return sum;
}