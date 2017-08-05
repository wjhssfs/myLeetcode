// 624. Maximum Distance in Arrays

// Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

// Example 1:
// Input: 
// [[1,2,3],
//  [4,5],
//  [1,2,3]]
// Output: 4
// Explanation: 
// One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
// Note:
// Each given array will have at least 1 number. There will be at least two non-empty arrays.
// The total number of the integers in all the m arrays will be in the range of [2, 10000].
// The integers in the m arrays will be in the range of [-10000, 10000].

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mi = arrays[0].front(), ma = arrays[0].back(), res = 0;
        for (size_t i = 1; i < arrays.size(); ++i) {
            res = max(res, abs(arrays[i].front() - ma));
            res = max(res, abs(arrays[i].back() - mi));
            ma = max(ma, arrays[i].back());
            mi = min(mi, arrays[i].front());
        }
        return res;
    }
};