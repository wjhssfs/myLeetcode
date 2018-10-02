// 651. 4 Keys Keyboard

// Imagine you have a special keyboard with the following keys:

// Key 1: (A): Print one 'A' on screen.

// Key 2: (Ctrl-A): Select the whole screen.

// Key 3: (Ctrl-C): Copy selection to buffer.

// Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

// Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.

// Example 1:
// Input: N = 3
// Output: 3
// Explanation: 
// We can at most get 3 A's on screen by pressing following key sequence:
// A, A, A
// Example 2:
// Input: N = 7
// Output: 9
// Explanation: 
// We can at most get 9 A's on screen by pressing following key sequence:
// A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
// Note:
// 1 <= N <= 50
// Answers will be in the range of 32-bit signed integer.

class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            for (int j = i - 3; j > 0; --j) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
            dp[i] = max(dp[i], i);
        }
        
        return dp[N];
    }
};

public int maxA(int n) {
    int max = n;
    for (int i = 1; i <= n - 3; i++)
        max = Math.max(max, maxA(i) * (n - i - 1));
    return max;
}