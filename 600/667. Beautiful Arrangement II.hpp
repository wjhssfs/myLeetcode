// 667. Beautiful Arrangement II
// Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement: 
// Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

// If there are multiple answers, print any of them.

// Example 1:
// Input: n = 3, k = 1
// Output: [1, 2, 3]
// Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
// Example 2:
// Input: n = 3, k = 2
// Output: [1, 3, 2]
// Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
// Note:
// The n and k are in the range 1 <= k < n <= 104.

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int cur = n;
        for (int i = k; i < n; ++i) {
            res.push_back(cur--);
        }
        int f = -1;
        while (res.size() < n) {
            res.push_back(res.back() + f * k);
            f = -f;
            --k;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res{1};
        int f = 1;
        while (res.size() < n) {
            if (k) {
                res.push_back(res.back() + f * k);
                f = -f;
                --k;
            } else {
                res.push_back(res.size() + 1);
            }
        }
        return res;
    }
};

//   i++ j-- i++ j--  i++ i++ i++ ...
// out: 1   9   2   8    3   4   5   6   7
// dif:   8   7   6   5    1   1   1   1 

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 1, j = n; i <= j; ) {
            if (k > 1) {
                res.push_back(k-- % 2 ? i++ : j--);
            }
            else {
                res.push_back(i++);
            }
        }
        return res;
    }
};