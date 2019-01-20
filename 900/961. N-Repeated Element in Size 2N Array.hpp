// 961. N-Repeated Element in Size 2N Array

// In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

// Return the element repeated N times.

 

// Example 1:

// Input: [1,2,3,3]
// Output: 3
// Example 2:

// Input: [2,1,2,5,3,2]
// Output: 2
// Example 3:

// Input: [5,1,5,2,5,3,5,4]
// Output: 5
 

// Note:

// 4 <= A.length <= 10000
// 0 <= A[i] < 10000
// A.length is even

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int n1 = -1, c1 = 0, n2 = -1, c2 = 0;
        for (auto a : A) {
            if (!c1) {
                n1 = a;
                c1 = 1;
            } else if (n1 == a) {
                ++c1;
            } else {
                --c1;
                if (!c1) n2 = a;
            }
        }
        for (auto a : A) {
            if (a == n1) c1++;
            else if (a == n2) c2++;
            if (c1 > 1) return n1;
            else if (c2 > 1) return n2;
        }
        return n1;
    }
};