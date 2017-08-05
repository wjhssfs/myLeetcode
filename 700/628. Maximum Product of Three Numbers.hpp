// 628. Maximum Product of Three Numbers
// Given an integer array, find three numbers whose product is maximum and output the maximum product.

// Example 1:
// Input: [1,2,3]
// Output: 6
// Example 2:
// Input: [1,2,3,4]
// Output: 24
// Note:
// The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
// Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> m({INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MIN});
        for (auto num : nums) {
            if (num < m[0]) {
                m[1] = m[0];
                m[0] = num;
            } else if (num < m[1]) {
                m[1] = num;
            }
            
            if (num > m[4]) {
                m[2] = m[3];
                m[3] = m[4];
                m[4]= num;
            } else if (num > m[3]) {
                m[2] = m[3];
                m[3] = num;
            } else if (num > m[2]) {
                m[2] = num;
            }
        }
        return max(m[0] * m[1], m[2] * m[3]) * m[4];
    }
};