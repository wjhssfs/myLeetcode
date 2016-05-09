// 154 Find Minimum in Rotated Sorted Array II
// Follow up for "Find Minimum in Rotated Sorted Array":
// What if duplicates are allowed?
// Would this affect the run-time complexity? How and why?
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.

// Complexity becomes O(n). worst case scenario, all numbers are the same except the 2nd one, which is minimum.

class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size() - 1, m = (l + r) / 2;
        while (l<=r)
        {
            if (l==r) return num[l];
            if (l + 1 == r) return min(num[l], num[r]);
            if (num[l] < num[r]) return num[l];
            else if(num[l] == num[r]) {
                --r; 
                m = (l+r)/2;
            }
            else if (num[l] > num[m]){
                r = m;
                m = (l + r) / 2;
            }
            else if (num[m] > num[r]){
                l = m;
                m = (l + r) / 2;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;

        while(lo < hi) {
            mid = lo + (hi - lo) / 2;

            if (num[mid] > num[hi]) {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return num[lo];
    }
};