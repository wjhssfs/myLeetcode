// 717. 1-bit and 2-bit Characters
// We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

// Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

// Example 1:
// Input: 
// bits = [1, 0, 0]
// Output: True
// Explanation: 
// The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
// Example 2:
// Input: 
// bits = [1, 1, 1, 0]
// Output: False
// Explanation: 
// The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
// Note:

// 1 <= len(bits) <= 1000.
// bits[i] is always 0 or 1.

// https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/108967/JAVA-check-only-the-end-of-array
// In problem statement, the given string will always end with a zero.
// so just check if # of 1s before 0 is odd/even
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int count1 = 0;
        for (int i = bits.size() - 2; i >= 0 && bits[i] != 0; --i) count1++;
        return count1 % 2 == 0;
    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        bool isSingle = false;
        while (i < bits.size()) {
            if (bits[i] == 0) {
                isSingle = true;
                ++i;
            } else { i+= 2; isSingle = false;}
        }
        return isSingle;
    }
};