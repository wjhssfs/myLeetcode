// 768. Max Chunks To Make Sorted II
// This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, the input array could be up to length 2000, and the elements could be up to 10**8.

// Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

// What is the most number of chunks we could have made?

// Example 1:

// Input: arr = [5,4,3,2,1]
// Output: 1
// Explanation:
// Splitting into two or more chunks will not return the required result.
// For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
// Example 2:

// Input: arr = [2,1,3,4,4]
// Output: 4
// Explanation:
// We can split into two chunks, such as [2, 1], [3, 4, 4].
// However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
// Note:

// arr will have length in range [1, 2000].
// arr[i] will be an integer in range [0, 10**8].

// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/discuss/113462/Java-solution-left-max-and-right-min.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        auto maxLeft = arr, minRight = arr;
        for (int i = 1; i < arr.size(); ++i) {
            maxLeft[i] = max(maxLeft[i - 1], arr[i]);
            minRight[arr.size() - 1 - i] = min(minRight[arr.size() - i], arr[arr.size() - 1 - i]);
        }
        int result = 0;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (maxLeft[i] <= minRight[i + 1]) ++result;
        }
        return result + 1;
    }
};