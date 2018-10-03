// 905. Sort Array By Parity
// Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

// You may return any answer array that satisfies this condition.

 

// Example 1:

// Input: [3,1,2,4]
// Output: [2,4,3,1]
// The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

// Note:

// 1 <= A.length <= 5000
// 0 <= A[i] <= 5000

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if (A.empty()) return A;
        vector<int> res(A.size());
        size_t left = 0, right = A.size() - 1;
        for (auto a : A) {
            if (a % 2) res[right--] = a;
            else res[left++] = a;
        }
        return res;
    }
};

 vector<int> sortArrayByParity(vector<int> &A) {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) swap(A[i++], A[j]);
        return A;
    }