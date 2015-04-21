// 34 Search for a Range
// Given a sorted array of integers, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lowBound = -1;
        int highBound = -1;
        int high = n;
        int low = 0;
        int mid;

        while (high > low) {
            mid = (high + low) / 2;
            if (A[mid] < target) {
                if (mid + 1 == n) return{ -1, -1 };
                if (A[mid + 1] == target)
                {
                    lowBound = mid + 1;
                    break;
                }
                else if (A[mid + 1] >target) return{ -1, -1 };
                else low = mid + 1;
            }
            else
            {
                if (A[mid] == target){
                    if (mid == 0){
                        lowBound = 0;
                        break;
                    }
                }
                high = mid;
            }
        }

        high = n;
        low = max(0, lowBound);
        while (high > low) {
            mid = (high + low) / 2;
            if (A[mid] > target) {
                if (mid == 0) return{ -1, -1 };
                if (A[mid - 1] == target)
                {
                    highBound = mid - 1;
                    break;
                }
                else if (A[mid-1] > target) high = mid;
                else return{ -1, -1 };
            }
            else
            {
                if (A[mid] == target){
                    if (mid == n - 1){
                        highBound = n - 1;
                        break;
                    }
                }

                low = mid + 1;
            }
        }

        return { lowBound, highBound };
    }
};

class Solution2 {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(A[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        if(A[low] != target) return {-1, -1};
        int lowBound = low;
        low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(A[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return {lowBound, high};
    }
};
