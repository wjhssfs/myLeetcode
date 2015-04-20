// 22 Generate Parentheses 
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> results;
		generateParenthesisInner(n, 0, 0, "", results);
		return results;
	}

	void generateParenthesisInner(int n, int opened, int closed, string current, vector<string> &results){
		if (n == opened && n == closed){
			results.push_back(current);
			return;
		}
		if (closed < opened){
			generateParenthesisInner(n, opened, closed + 1, current + ")", results);
		}
		if (opened < n){
			generateParenthesisInner(n, opened + 1, closed, current + "(", results);
		}
	}
};