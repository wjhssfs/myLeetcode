// 20 Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not

class Solution {
public:
    bool isValid(string s) {
        stack<char> ps;
        for (size_t i = 0; i < s.size(); i++)
        {
            char c = s[i];
            switch (c)
            {
            case ')':
                if (ps.empty() || ps.top() != '(') return false;
                ps.pop();
                break;
            case ']':
                if (ps.empty() || ps.top() != '[') return false;
                ps.pop();
                break;
            case '}':
                if (ps.empty() || ps.top() != '{') return false;
                ps.pop();
                break;
            default:
                ps.push(c);
                break;
            }
        }
        return ps.empty();
    }
};
