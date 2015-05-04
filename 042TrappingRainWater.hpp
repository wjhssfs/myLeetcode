// 42 Trapping Rain Water 
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        vector<int>left(n), right(n);
        right[n - 1] = left[0] = 0;
        for (int i = n - 2; i >= 0; i--) right[i] = max(right[i+1], A[i + 1]);
        for (int i = 1; i < n; i++) left[i] = max(left[i-1], A[i - 1]);
        int sumR = 0;
        for (int i = 0; i < n; i++)  sumR = max(sumR, sumR + min(left[i], right[i]) - A[i]);
        return sumR;
    }
};