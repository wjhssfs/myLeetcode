// 719. Find K-th Smallest Pair Distance
// Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

// Example 1:
// Input:
// nums = [1,3,1]
// k = 1
// Output: 0 
// Explanation:
// Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.
// Note:
// 2 <= len(nums) <= 10000.
// 0 <= nums[i] < 1000000.
// 1 <= k <= len(nums) * (len(nums) - 1) / 2.

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int right = nums.back() - nums.front(), left = 0;
        while (left < right) {
            int middle = left + (right - left) / 2;
            int n = 0;
            for (int i = 0; i < nums.size(); ++i) {
                auto it = upper_bound(nums.begin() + i, nums.end(), middle + nums[i]);
                n += it - (nums.begin() + i) - 1;
            }
            if (n < k) {
                left = middle + 1;
            } else {
                right = middle; 
            }
        }
        return left;
    }
};

class Solution {
    // Returns index of first index of element which is greater than key
    private int upperBound(int[] a, int low, int high, int key) {
        if (a[high] <= key) return high + 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (key >= a[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    
    // Returns number of pairs with absolute difference less than or equal to mid.
    private int countPairs(int[] a, int mid) {
        int n = a.length, res = 0;
        for (int i = 0; i < n; i++) {
            res += upperBound(a, i, n - 1, a[i] + mid) - i - 1;
        }
        return res;
    }

    public int smallestDistancePair(int a[], int k) {
        int n = a.length;
        Arrays.sort(a);

        // Minimum absolute difference
        int low = a[1] - a[0];
        for (int i = 1; i < n - 1; i++)
            low = Math.min(low, a[i + 1] - a[i]);

        // Maximum absolute difference
        int high = a[n - 1] - a[0];

        // Do binary search for k-th absolute difference
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countPairs(a, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
}

// https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115819/Summary-of-solutions-for-problems-%22reducible%22-to-LeetCode-378
In this case there is only one array nums as input, so both a and b will refer to nums. After sorting nums in ascending order, we have matrix[i][j] = nums[i] - nums[n - 1 - j], where n = nums.length. Note that the mapping for column index is chosen to be "negative" in order to make sure the columns are sorted in ascending order. Also note that our matrix will contain all pair distances (including negative ones) while the original problem asks for the Kth smallest pair distance out of absolute pair distances (there are n(n-1)/2 such pairs). So we need to shift the rank up to K' = K + n(n+1)/2. The Kth smallest pair distance then will be the K'th smallest element in the matrix.