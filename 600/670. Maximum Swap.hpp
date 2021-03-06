// 670. Maximum Swap

// Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

// Example 1:
// Input: 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
// Example 2:
// Input: 9973
// Output: 9973
// Explanation: No swap.
// Note:
// The given number is in the range [0, 108]

class Solution {
public:
    int maximumSwap(int num) {
        auto n = to_string(num);
        vector<int> dp(n.size());
        dp.back() = n.size() - 1;
        for (int i = (int)n.size() - 2; i >= 0; --i) {
            if (n[i] <= n[dp[i + 1]]) dp[i] = dp[i + 1];
            else dp[i] = i;
        }
        for (int i = 0; i < n.size(); ++i) if (n[i] < n[dp[i]]) {
            swap(n[i], n[dp[i]]);
            break;
        }
        return stoi(n);
    }
};


// Use buckets to record the last position of digit 0 ~ 9 in this num.
// Loop through the num array from left to right. For each position, we check whether there exists a larger
// digit in this num (start from 9 to current digit). We also need to make sure the position of this larger
// digit is behind the current one. If we find it, simply swap these two digits and return the result.
class Solution {
    public int maximumSwap(int num) {
        char[] digits = Integer.toString(num).toCharArray();
        
        int[] buckets = new int[10];
        for (int i = 0; i < digits.length; i++) {
            buckets[digits[i] - '0'] = i;
        }
        
        for (int i = 0; i < digits.length; i++) {
            for (int k = 9; k > digits[i] - '0'; k--) {
                if (buckets[k] > i) {
                    char tmp = digits[i];
                    digits[i] = digits[buckets[k]];
                    digits[buckets[k]] = tmp;
                    return Integer.valueOf(new String(digits));
                }
            }
        }
        
        return num;
    }
}
