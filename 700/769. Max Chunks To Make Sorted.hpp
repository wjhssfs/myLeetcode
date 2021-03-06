// 769. Max Chunks To Make Sorted
// Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

// What is the most number of chunks we could have made?

// Example 1:

// Input: arr = [4,3,2,1,0]
// Output: 1
// Explanation:
// Splitting into two or more chunks will not return the required result.
// For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
// Example 2:

// Input: arr = [1,0,2,3,4]
// Output: 4
// Explanation:
// We can split into two chunks, such as [1, 0], [2, 3, 4].
// However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
// Note:

// arr will have length in range [1, 10].
// arr[i] will be a permutation of [0, 1, ..., arr.length - 1].

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int next = 0, result = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (next != arr[i]) {
                do {
                    next = max(next, arr[i]);
                } while (i++ < next);
                --i;
            }
            ++result;
            ++next;
        }
        return result;
    }
};

// Algorithm: Iterate through the array, each time all elements to the left are smaller (or equal) to
// all elements to the right, there is a new chunck.
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int[] maxOfLeft = new int[n];
        int[] minOfRight = new int[n];

        maxOfLeft[0] = arr[0];
        for (int i = 1; i < n; i++) {
            maxOfLeft[i] = Math.max(maxOfLeft[i-1], arr[i]);
        }

        minOfRight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minOfRight[i] = Math.min(minOfRight[i + 1], arr[i]);
        }

        int res = 0;
        for (int i = 0; i < n - 1; i++) { // leave last element out
            if (maxOfLeft[i] <= minOfRight[i + 1]) res++;
        }

        return res + 1; // +1 for the whole array
    }
}