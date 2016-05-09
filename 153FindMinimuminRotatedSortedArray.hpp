// 153 Find Minimum in Rotated Sorted Array
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.
// You may assume no duplicate exists in the array.

// Looking at subarray with index [start,end]. We can find out that if the first member is less than the last member, there's no
// rotation in the array. So we could directly return the first element in this subarray.
// If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element.
// If value of the element in the middle is larger than the first element, we know the rotation is at the second half of this array. Else, it is in the first half in the array.
 int findMin(vector<int> &num) {
        int start=0,end=num.size()-1;

        while (start<end) {
            if (num[start]<num[end])
                return num[start];

            int mid = (start+end)/2;

            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }

        return num[start];
    }

class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size() - 1, m = (l + r) / 2;
        while (l<=r)
        {
            if (l + 1 == r) return min(num[l], num[r]);
            if (num[l] <= num[r]) return num[l];
            else if (num[l] > num[m]){
                r = m;
                m = (l + r) / 2;
            }
            else if (num[m] > num[r]){
                l = m + 1;
                m = (l + r) / 2;
            }
        }
        return -1;
    }
};