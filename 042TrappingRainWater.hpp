// 42 Trapping Rain Water 
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        vector<int>b(n);
        vector<int>a(n);
        a[n - 1] = 0; b[0] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            a[i] = max(a[i+1], A[i + 1]);
        }
        for (int i = 1; i < n; i++)
        {
            b[i] = max(b[i-1], A[i - 1]);
        }
        int sumR = 0;
        for (int i = 0; i < n; i++)
            sumR = max(sumR, sumR + min(a[i], b[i]) - A[i]);
        return sumR;
    }
};

class Solution2 {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        int left[n];
        int right[n];

        int lmax = A[0];
        for (int i = 0; i < n; ++i)
        {
            lmax = max(lmax, A[i]);
            left[i] = lmax;
        }

        int rmax = A[n-1];
        for (int i = n - 1; i >= 0; --i)
        {
            rmax = max(rmax, A[i]);
            right[i] = rmax;
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
            res += min(left[i], right[i]) - A[i];

        return res;
    }
};