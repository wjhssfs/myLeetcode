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
        stack<char>op;
        stack<int>num;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') op.push('(');
            else if (S[i] == ')') {
                if (op.top() == '(') {
                    op.pop();
                    if (op.size() && op.top() == 'd') {
                        num.top() += 1;
                    } 
                    else {
                        num.push(1);
                        op.push('d');
                    }
                } else {
                    int n = num.top() * 2;
                    num.pop();
                    op.pop();
                    op.pop();
                    
                    if (op.size() && op.top() == 'd') {
                        num.top() += n;
                    }else {
                        op.push('d');
                        num.push(n);
                    }
                }
            }
        }
        return num.top();
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