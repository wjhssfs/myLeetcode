// 41 First Missing Positive
// Given an unsorted integer array, find the first missing positive integer.
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
// Your algorithm should run in O(n) time and uses constant space.

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n)
        {
            if (A[i] > 0 && A[i] < n -1 && A[i] != i+1) swap(A[i], A[A[i] - 1]);
            else i++;
        }
        for (i = 0; i < n && A[i] == i + 1; i++){}
        return i + 1;
    }
};