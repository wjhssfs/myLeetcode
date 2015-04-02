// 136 Single Number 
// 
// Given an array of integers, every element appears twice except for one. Find that single one.
// 
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


class Solution {
public:
    int singleNumber(int A[], int n) {
        		if (n == 1) return A[0];
		int ret = A[0];
		for (int i = 1; i != n; i++)
		{
			ret ^= A[i];
		}
		return ret;
    }
};

class Solution2 {
public:
    int singleNumber(int A[], int n) {
        for (int i = 1; i < n; ++i)
            A[0] ^= A[i];
        return A[0];
    }
};