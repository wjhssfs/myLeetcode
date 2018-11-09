// 852. Peak Index in a Mountain Array
// Let's call an array A a mountain if the following properties hold:

// A.length >= 3
// There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
// Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

// Example 1:

// Input: [0,1,0]
// Output: 1
// Example 2:

// Input: [0,2,1,0]
// Output: 1
// Note:

// 3 <= A.length <= 10000
// 0 <= A[i] <= 10^6
// A is a mountain, as defined above.

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) if (A[i] > A[i + 1]) return i;
        return -1;
    }
};

int peakIndexInMountainArray(vector<int>& A) {
    int l = 0, r = A.size() - 1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (A[mid] < A[mid + 1]) l = mid + 1;
        else r = mid;
    }
    return l;
}

// https://www.youtube.com/watch?v=VBFuqglVW3c
// Approach 4, Golden-section search
// It's gurentee only one peak, we can apply golden-section search.

    def peakIndexInMountainArray(self, A):
        def gold1(l, r):
            return l + int(round((r - l) * 0.382))

        def gold2(l, r):
            return l + int(round((r - l) * 0.618))
        l, r = 0, len(A) - 1
        x1, x2 = gold1(l, r), gold2(l, r)
        while x1 < x2:
            if A[x1] < A[x2]:
                l = x1
                x1 = x2
                x2 = gold1(x1, r)
            else:
                r = x2
                x2 = x1
                x1 = gold2(l, x2)
        return x1