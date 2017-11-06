// 477. Total Hamming Distance

// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Now your job is to find the total Hamming distance between all pairs of the given numbers.

// Example:
// Input: 4, 14, 2

// Output: 6

// Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
// showing the four bits relevant in this case). So the answer will be:
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
// Note:
// Elements of the given array are in the range of 0 to 10^9
// Length of the array will not exceed 10^4.

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> nBit(32);
        for (auto num : nums) {
            unsigned mask = 1 << 31;
            for (int i = 31; i >= 0; --i) {
                if (num & mask) ++nBit[i];
                mask >>= 1;
            }
        }
        int sz = nums.size(), total = 0;
        for (int i = 0; i < 32; ++i) {
            total += (sz - nBit[i]) * nBit[i];
        }
        return total; 
    }
};

public int totalHammingDistance(int[] nums) {
    int total = 0, n = nums.length;
    for (int j=0;j<32;j++) {
        int bitCount = 0;
        for (int i=0;i<n;i++) 
            bitCount += (nums[i] >> j) & 1;
        total += bitCount*(n - bitCount);
    }
    return total;
}