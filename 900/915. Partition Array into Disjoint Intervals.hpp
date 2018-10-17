// 915. Partition Array into Disjoint Intervals

// Given an array A, partition it into two (contiguous) subarrays left and right so that:

// Every element in left is less than or equal to every element in right.
// left and right are non-empty.
// left has the smallest possible size.
// Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

 

// Example 1:

// Input: [5,0,3,8,6]
// Output: 3
// Explanation: left = [5,0,3], right = [8,6]
// Example 2:

// Input: [1,1,1,0,6,12]
// Output: 4
// Explanation: left = [1,1,1,0], right = [6,12]
 

// Note:

// 2 <= A.length <= 30000
// 0 <= A[i] <= 10^6
// It is guaranteed there is at least one way to partition A as described.

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int leftMax = A[0], curMax = A[0], partition = 0, i = 1;
        for(; i < A.size(); ++i) {
            if (leftMax > A[i]) {
                leftMax = curMax;
                partition = i;
            }
            curMax = max(curMax, A[i]);
        }
        return partition + 1;
    }
};

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        auto minAfter = A;
        for (int i = minAfter.size() - 2; i >= 0; --i) minAfter[i] = min(minAfter[i], minAfter[i + 1]);
        int i = 0, maxBefore = A[0];
        for (; i < A.size(); ++i) {
            if (maxBefore <= minAfter[i]) break;
            maxBefore = max(A[i], maxBefore);
        }
        return max(1, i);
    }
};