// 80 Remove Duplicates from Sorted Array II 
// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
// 
// For example,
// Given sorted array A = [1,1,1,2,2,3],
// 
// Your function should return length = 5, and A is now [1,1,2,2,3].

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int j = 2;
        for (int i = 2; i < n; ++i)
            if (A[i] != A[j-1] || A[i] != A[j-2])
                A[j++] = A[i];
        return j;
    }
};