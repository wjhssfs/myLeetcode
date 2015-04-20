// 27 Remove Element 
// Given an array and a value, remove all instances of that value in place and return the new length.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int j = n-1;
        int i = 0; 
        while(i <= j)
        {
            if(A[i] == elem){
                swap(A[i], A[j]);
                j--;
            }
            else i++;
        }
        return i;
    }
};

class Solution2 {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        for (int j = 0; j < n; ++j)
            if (A[j] != elem)
                A[i++] = A[j];
        return i;
    }
};
