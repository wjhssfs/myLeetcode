// 138 Single Number II
// Given an array of integers, every element appears three times except for one. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) 
        {
            int count = 0, bit = 1 << i;
            for (int j = 0; j < n; ++j)
                if (A[j] & bit)
                    count++;
            if (count % 3 != 0)
                res |= bit;
        }
        return res;
    }
};

//https://leetcode.com/discuss/9763/accepted-proper-explaination-does-anyone-have-better-idea
// https://leetcode.com/discuss/6632/challenge-me-thx
public int singleNumber(int[] A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.length; i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}