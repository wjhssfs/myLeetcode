// 4 Median of Two Sorted Arrays 
// There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// O(log(m+n))
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        double ret = findKthElement(A, m, B, n, (m+n)/2 + 1);
        if((m+n)%2 == 0) ret = (ret + findKthElement(A, m, B, n, (m+n)/2))/2;
        return ret;
    }
    
private:
    int findKthElement(int A[], int m, int B[], int n, int k)
    {
        if(m > n) return findKthElement(B, n, A, m, k);
        if(m == 0) return B[k-1];
        if(k == 1) return min(A[0], B[0]);
        int i = min(m, k/2);
        int j = k - i;
        if(A[i-1] < B[j-1]) return findKthElement(A+i, m-i, B, n, k-i);
        else if(A[i-1]>B[j-1]) return findKthElement(A, m, B+j, n-j, k-j);
        else return A[i-1];
    }
};

/*
Solution: 1. O(m+n)
          2. O(logm + logn)
*/
class Solution2 {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArrays_1(A, m, B, n);
    }

    double findMedianSortedArrays_1(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int m1 = 0, m2 = 0;
        int total = m + n;

        for (int k = 0; k <= total / 2; ++k)
        {
            int a = (i == m) ? INT_MAX : A[i];
            int b = (j == n) ? INT_MAX : B[j];

            m1 = m2;
            m2 = min(a, b);

            if (a < b) i++;
            else j++;
        }

        if (total & 0x1) return m2;
        else return (m1 + m2) / 2.0;
    }

    double findMedianSortedArrays_2(int A[], int m, int B[], int n) {
        return findMedian(A, m, B, n, max(0, (m + n) / 2 - n), min(m - 1, (m + n) / 2));
    }

    double findMedian(int A[], int m, int B[], int n, int l, int r) {
        if (l > r)
            return findMedian(B, n, A, m, max(0, (m + n) / 2 - m), min(n, (m + n) / 2));

        int i = (l + r) / 2;
        int j = (m + n) / 2 - i;

        int Ai_1 = (i == 0) ? INT_MIN : A[i-1];
        int Bj_1 = (j == 0) ? INT_MIN : B[j-1];
        int Ai = (i == m) ? INT_MAX : A[i];
        int Bj = (j == n) ? INT_MAX : B[j];

        if (Ai < Bj_1) return findMedian(A, m, B, n, i+1, r);
        if (Ai > Bj) return findMedian(A, m, B, n, l, i-1);

        if ((m + n) % 2 == 1) return Ai;
        else return (Ai + max(Ai_1, Bj_1)) / 2.0;
    }
};

// https://leetcode.com/discuss/15790/share-my-o-log-min-m-n-solution-with-explanation
class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if (m > n) return findMedianSortedArrays(B, n, A, m);
    int minLengthL = 0, maxLengthL = m, i, j, num1, mid = (m + n + 1) >> 1,num2;
    // i = n elements in A left
    // j = n elements in B left
    while (minLengthL <= maxLengthL)
    {
      i = (minLengthL + maxLengthL) >> 1;
      j = mid - i;
      if (i<m && j>0 && B[j-1] > A[i]) minLengthL = i + 1;
      else if (i>0 && j<n && B[j] < A[i-1]) maxLengthL = i - 1;
      else
      {
        if (i == 0) num1 = B[j-1];
        else if (j == 0) num1 = A[i - 1];
        else num1 = max(A[i-1],B[j-1]);
        break;
      }
    }
    if (((m + n) & 1)) return num1;
    if (i == m) num2 = B[j];
    else if (j == n) num2 = A[i];
    else num2 = min(A[i],B[j]);
    return (num1 + num2) / 2.;
  }
};

// https://leetcode.com/discuss/41621/very-concise-iterative-solution-with-detailed-explanation
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        if (sz1 < sz2) return findMedianSortedArrays(nums2, nums1);
        if (!sz2) return ((double)nums1[(sz1 - 1) / 2] + (double)nums1[sz1 / 2]) / 2.0;
        int l = 0, h = sz2;
        while (l <= h) {
            int c2 = (l + h) / 2;
            int c1 = (sz1 + sz2) / 2 - c2;

            int l1 = (c1 == 0) ? INT_MIN : nums1[c1-1];
            int r1 = (c1 == sz1) ? INT_MAX : nums1[c1];
            int l2 = (c2 == 0) ? INT_MIN : nums2[c2-1];
            int r2 = (c2 == sz2) ? INT_MAX : nums2[c2];

            if (l1 > r2) {
                l = c2 + 1;
            }
            else if (r1 < l2) {
                h = c2 - 1;
            }
            else {
                return ((sz1 + sz2) % 2 == 0) ? ((double)max(l1, l2) + min(r1, r2)) / 2.0 : min(r1, r2);
            }
        }
        return -1;
    }
};