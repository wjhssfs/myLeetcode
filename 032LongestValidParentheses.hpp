// 32 Longest Valid Parentheses 
// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// For "(()", the longest valid parentheses substring is "()", which has length = 2.

// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

// DP
class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> m(s.size());
		int maxL = 0;
		for (size_t i = 1; i < s.size(); i++){
			if (s[i] == ')'){
				int j = i-1 - m[i - 1];
				if (j>=0 &&s[j] == '('){
					m[i] = m[i - 1] + 2;
					if (j>0) m[i] += m[j - 1];
					maxL = max(maxL, m[i]);
				}
			}
		}
		return maxL;
	}
};

class Solution2 {
public:
    int longestValidParentheses(string s) {
        return longestValidParentheses_1(s);
    }
    
    // Solution 1, from fuwutu. Smart!
    // push the length of last valid parentheses into stack.
    int longestValidParentheses_1(string s) {
        stack<int> stk;
        int res = 0, count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(count);
                count = 0;
            } else if (!stk.empty()) {
                count += (1 + stk.top());
                stk.pop();
                res = max(res, count);
            } else {
                count = 0;
            }
        }
        return res * 2;
    } 
    
    // Solution 2, my original version.
    // Traverse the string twice, taking O(n) time.
    // First time, mark all the matching parentheses as '*' (push the index of '(' into <stack>).
    // Second time, count the longest consecutive '*'.
    int longestValidParentheses_2(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (!stk.empty()) {
                s[stk.top()] = '*';
                s[i] = '*';
                stk.pop();
            }
        }
        int res = 0, part = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                part++;
            } else {
                res = max(res, part);
                part = 0;
            }
        }
        res = max(res, part);
        return res;
    }
};