// 856. Score of Parentheses

// Given a balanced parentheses string S, compute the score of the string based on the following rule:

// () has score 1
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.
 

// Example 1:

// Input: "()"
// Output: 1
// Example 2:

// Input: "(())"
// Output: 2
// Example 3:

// Input: "()()"
// Output: 2
// Example 4:

// Input: "(()(()))"
// Output: 6
 

// Note:

// S is a balanced parentheses string, containing only ( and ).
// 2 <= S.length <= 50

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        s.push(0);
        for (auto c : S) {
            if (c == '(') s.push(0);
            else {
                auto cur = s.top();s.pop();
                s.top() += max(cur * 2, 1);
            }
        }
        return s.top();
    }
};

    int scoreOfParentheses(string S) {
        // res[i] result at ith current open '('
        // when '(' is closed, its result is added to previous '(' or
        // the final result which is at res[0]
        int res[30] = {0}, i = 0;
        for (char c : S)
            if (c == '(') res[++i] = 0;
            else res[i - 1] += max(res[i] * 2, 1), i--;
        return res[0];
    }