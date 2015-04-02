// 138 Single Number II
// Given an array of integers, every element appears three times except for one. Find that single one.
// 
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

class Solution {
public:
    int singleNumber(int A[], int n) {
        		int result = 0;
		int size = sizeof(int)* 8;
		for (int j = 0; j < size; j++)
		{
			int bitCount = 0;
			for (int i = 0; i < n; i++)
			{
				bitCount += (A[i] & (1 <<j)) != 0;
			}
			result |= ((bitCount % 3) << j);
		}
		return result;
    }
};

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