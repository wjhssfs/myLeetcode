// 842. Split Array into Fibonacci Sequence
// Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

// Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

// 0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
// F.length >= 3;
// and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
// Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

// Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

// Example 1:

// Input: "123456579"
// Output: [123,456,579]
// Example 2:

// Input: "11235813"
// Output: [1,1,2,3,5,8,13]
// Example 3:

// Input: "112358130"
// Output: []
// Explanation: The task is impossible.
// Example 4:

// Input: "0123"
// Output: []
// Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
// Example 5:

// Input: "1101111"
// Output: [110, 1, 111]
// Explanation: The output [11, 0, 11, 11] would also be accepted.
// Note:

// 1 <= S.length <= 200
// S contains only digits.

class Solution {
    bool dfs(vector<int>& array, string& S, size_t idx) {
        if (idx == S.size() && array.size() > 2) return true;
        for (size_t i = idx; i < S.size(); ++i) {
            if (S[idx] == '0' && i > idx) break;
            long num = 0;
            num = stol(S.substr(idx, i - idx + 1));
            if (num > INT_MAX) break;
            if (array.size() > 1 && array[array.size() - 2] + array.back() < num) break;
            if (array.size() < 2 || array[array.size() - 2] + array.back() == num) {
                array.push_back(num);
                if (dfs(array, S, i + 1)) return true;
                array.pop_back();
            }
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> array;
        dfs(array, S, 0);
        return array;
    }
};