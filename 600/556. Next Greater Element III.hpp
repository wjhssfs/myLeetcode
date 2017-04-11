// 556. Next Greater Element III
// Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

// Example 1:
// Input: 12
// Output: 21
// Example 2:
// Input: 21
// Output: -1

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 1;
        while (i > 0 && s[i-1] >= s[i]) --i;
        if (i == 0) return -1;
        int j = s.size() - 1;
        while (s[j] <= s[i-1]) --j;
        swap(s[i-1], s[j]);
        j = s.size() - 1;
        while (i < j) swap(s[i++], s[j--]);
        long long ll = stoll(s);
        return ll > INT_MAX ? -1 : ll;
    }
};

int nextGreaterElement(int n) {
    auto digits = to_string(n);
    next_permutation(begin(digits), end(digits));
    auto res = stoll(digits);
    return (res > INT_MAX || res <= n) ? -1 : res;
}