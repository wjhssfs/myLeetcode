// 150 Evaluate Reverse Polish Notation
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto && token : tokens) {
            if (token == "+") {
                int op1 = s.top(); s.pop();
                s.top() += op1;
            } else if (token == "-") {
                int op1 = s.top(); s.pop();
                s.top() -= op1;
            } else if (token == "*") {
                int op1 = s.top(); s.pop();
                s.top() *= op1;
            } else if (token == "/") {
                int op1 = s.top(); s.pop();
                s.top() /= op1;
            } else {
                s.push(stoi(token));
            }
        }
        return s.size() ? s.top() : 0;
    }
};

int evalRPN(vector<string> &n) {
    string s = n.back(); n.pop_back();
    if ( s== "*" || s=="/" || s=="+" || s == "-" ){
        int r2 = evalRPN(n);
        int r1 = evalRPN(n);
        if ( s=="*") return r1*r2;
        if ( s=="/") return r1/r2;
        if ( s=="+") return r1+r2;
        if ( s=="-") return r1-r2;
    }
    else
        return atoi(s.c_str());
}