// 967. Numbers With Same Consecutive Differences
// Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

// Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

// You may return the answer in any order.

 

// Example 1:

// Input: N = 3, K = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.
// Example 2:

// Input: N = 2, K = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

// Note:

// 1 <= N <= 9
// 0 <= K <= 9

class Solution {
    void dfs(int N, int cur, int k, vector<int>& buf, vector<int>& res) {
        if (cur == N) {
            int t = 0;
            for (auto d : buf) t = t * 10 + d;
            res.push_back(t);
            return;
        }
        if (buf.back() + k < 10) {
            buf.push_back(buf.back() + k);
            dfs(N, cur + 1, k, buf, res);
            buf.pop_back();
        }
        if (buf.back() - k >= 0 && k != 0) {
            buf.push_back(buf.back() - k);
            dfs(N, cur + 1, k, buf, res);
            buf.pop_back();
        }
    }
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> buf, res;
        for (int i = 1; i <= 9; ++i) {
            buf.push_back(i);
            dfs(N, 1, K, buf, res);
            buf.pop_back();
        }
        return res;
    }
};