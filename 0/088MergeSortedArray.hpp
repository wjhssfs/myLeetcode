// 88 Merge Sorted Array 
// Given two sorted integer arrays A and B, merge B into A as one sorted array.
// Note:
// You may assume that A has enough space (size that is greater or equal to m + n) to hold
// additional elements from B. The number of elements initialized in A and B are m and n respectively.

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int left = m+n;
        while(left > 0){
            if(m==0 || (n>0 && A[m-1] < B[n-1])) {
                A[left-1] = B[n-1];
                n--;
            }else{
                A[left-1] = A[m-1];
                m--;
            }
            left--;
        }
    }
};

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        copy(B, B + n, A + m); inplace_merge(A, A + m, A + m + n);
    }
};

while(n>0) A[m+n-1] = (m==0||B[n-1] > A[m-1]) ? B[--n] : A[--m];