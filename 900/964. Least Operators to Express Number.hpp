// 964. Least Operators to Express Number
// Given a single positive integer x, we will write an expression of the form x (op1) x (op2) x (op3) x ... where each operator op1, op2, etc. is either addition, subtraction, multiplication, or division (+, -, *, or /).  For example, with x = 3, we might write 3 * 3 / 3 + 3 - 3 which is a value of 3.

// When writing such an expression, we adhere to the following conventions:

// The division operator (/) returns rational numbers.
// There are no parentheses placed anywhere.
// We use the usual order of operations: multiplication and division happens before addition and subtraction.
// It's not allowed to use the unary negation operator (-).  For example, "x - x" is a valid expression as it only uses subtraction, but "-x + x" is not because it uses negation.
// We would like to write an expression with the least number of operators such that the expression equals the given target.  Return the least number of operators used.

 

// Example 1:

// Input: x = 3, target = 19
// Output: 5
// Explanation: 3 * 3 + 3 * 3 + 3 / 3.  The expression contains 5 operations.
// Example 2:

// Input: x = 5, target = 501
// Output: 8
// Explanation: 5 * 5 * 5 * 5 - 5 * 5 * 5 + 5 / 5.  The expression contains 8 operations.
// Example 3:

// Input: x = 100, target = 100000000
// Output: 3
// Explanation: 100 * 100 * 100 * 100.  The expression contains 3 operations.
 

// Note:

// 2 <= x <= 100
// 1 <= target <= 2 * 10^8

// https://leetcode.com/problems/least-operators-to-express-number/discuss/208376/python2-O(log-target)-chinese
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        vector<int> ds;
        while (target) {
            ds.push_back(target % x);
            target /= x;
        }
        // pos the number of operations needed to get y % (x ^ (k+1))
        // neg the number of operations needed to get x ^ (k + 1) - y % (x ^ (k + 1))
        int pos = ds[0] * 2, neg = (x - ds[0]) * 2; // 46: 6 = 6 * (+x / x), -4 = 4 * (-x / x)
        for (int i = 1; i < ds.size(); ++i) {
            int nPos = min(ds[i] * i + pos /* 46 = 40 + 6 */, ds[i] * i + i + neg /* 46 = 40 + 10 - 4 */);
            int nNeg = min((x - ds[i]) * i + pos /* 46 = 100 [- 60 + 6] */,
                           (x - ds[i]) * i + i + neg - 2 * i /* 46 = 100 [- 60 + 10 - 6] */);
            pos = nPos;
            neg = nNeg;
        }
        return min(pos - 1, (int)ds.size() + neg - 1);
    }
};