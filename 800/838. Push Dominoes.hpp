// 838. Push Dominoes
// There are N dominoes in a line, and we place each domino vertically upright.

// In the beginning, we simultaneously push some of the dominoes either to the left or to the right.



// After each second, each domino that is falling to the left pushes the adjacent domino on the left.

// Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

// When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

// For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

// Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.

// Return a string representing the final state. 

// Example 1:

// Input: ".L.R...LR..L.."
// Output: "LL.RR.LLRRLL.."
// Example 2:

// Input: "RR.L"
// Output: "RR.L"
// Explanation: The first domino expends no additional force on the second domino.
// Note:

// 0 <= N <= 10^5
// String dominoes contains only 'L', 'R' and '.'

// https://leetcode.com/problems/push-dominoes/discuss/132332/C++JavaPython-Two-Pointers
class Solution {
public:
    string pushDominoes(string d) {
        d = 'L' + d + 'R';
        string res = "";
        for (int i = 0, j = 1; j < d.length(); ++j) {
            if (d[j] == '.') continue;
            int lenMiddle = j - i - 1;
            if (i > 0) res += d[i];
            if (d[i] == d[j]) res += string(lenMiddle, d[i]);
            else if (d[i] == 'L' && d[j] == 'R') res += string(lenMiddle, '.');
            else res += string(lenMiddle / 2, 'R') + string(lenMiddle % 2,'.') + string(lenMiddle / 2, 'L');
            i = j;
        }
        return res;
    }
};