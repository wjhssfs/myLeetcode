// 33 Search in Rotated Sorted Array
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

class Solution {
public:
    int search(int A[], int n, int target) {
        return bsearch(A, n, target, 0, n);
    }

    int bsearch(int A[], int n, int target, int left, int right)
    {
        if (left >= right) return -1;//empty
        int middle = (left + right) / 2;
        if (target == A[middle]) return middle;
        if (A[left] <= A[right-1]){//whole array sorted in order
            if (target < A[middle])
                return bsearch(A, n, target, left, middle);
            else`
                return bsearch(A, n, target, middle+1, right);
        } else{

            if (A[left] <= A[middle]){//left sorted
                if (target >= A[left] && target < A[middle]){
                    return bsearch(A, n, target, left, middle);
                }
                else
                {
                    return bsearch(A, n, target, middle+1, right);
                }
            }
            else{//right sorted
                if (target > A[middle] && target <= A[right-1]){
                    return bsearch(A, n, target, middle+1, right);
                }
                else
                {
                    return bsearch(A, n, target, left, middle);
                }
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int search(int A[], int n, int target) {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (A[mid] == target)
                return mid;
            if (A[i] <= A[mid])
            {
                if (A[i] <= target && target < A[mid])
                    j = mid - 1;
                else
                    i = mid + 1;
            }
            else
            {
                if (A[mid] < target && target <= A[j])
                    i = mid + 1;
                else
                    j = mid - 1;
            }
        }
        return -1;
    }
};
