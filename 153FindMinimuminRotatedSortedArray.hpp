// 153 Find Minimum in Rotated Sorted Array
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// 
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// 
// Find the minimum element.
// 
// You may assume no duplicate exists in the array.

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
                l = m;
                m = (l + r) / 2;
            }
        }
        return -1;
    }
};