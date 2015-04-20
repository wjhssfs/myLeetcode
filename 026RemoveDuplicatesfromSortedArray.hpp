// 26 Remove Duplicates from Sorted Array 
// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this in place with constant memory.

// For example,
// Given input array A = [1,1,2],

// Your function should return length = 2, and A is now [1,2].
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int i = 0; int j = 0;
		while (j < n){
			while (j<n && A[i] == A[j]){
				j++;
			}
			if (j<n){
				i++;
				swap(A[i], A[j]);
				j++;
			}
		}
		return j>0? i+1:i;
	}
};

class Solution2 {
public:
    int removeDuplicates(int A[], int n) {
        int j = 0;
        for (int i = 0; i < n; ++i)
            if (i == 0 || A[i] != A[i-1])
                A[j++] = A[i];
        return j;
    }
};