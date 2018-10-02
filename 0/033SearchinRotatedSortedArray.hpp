// 33 Search in Rotated Sorted Array
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.

class Solution {
public:
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};
 
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
            else
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
