// 421. Maximum XOR of Two Numbers in an Array
// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
// Could you do this in O(n) runtime?
// Example:
// Input: [3, 10, 5, 25, 2, 8]
// Output: 28
// Explanation: The maximum result is 5 ^ 25 = 28.

// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// def findMaximumXOR(self, nums):
//     answer = 0
//     for i in range(32)[::-1]:
//         answer <<= 1
//         prefixes = {num >> i for num in nums}
//         answer += any(answer^1 ^ p in prefixes for p in prefixes)
//     return answer

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int answer = 0;
        unordered_set<int> prefixes;
        for (int i = 31; i >=0; --i) {
            answer <<= 1;
            for (auto num : nums) prefixes.insert(num >> i);
            for (auto prefix : prefixes) {
                if (prefixes.count(answer ^ 1 ^ prefix)) {
                    ++answer;
                    break;
                }
            }
            prefixes.clear();
        }
        return answer;
    }
};