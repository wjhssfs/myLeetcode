// 150 Evaluate Reverse Polish Notation
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		if (tokens.size() == 0) return 0;
		stack<int> operands;
		for (int i = 0; i < tokens.size(); i++){
			char firstChar = *(tokens[i].c_str());
			if (!isdigit(firstChar) && tokens[i].size()==1){
				int result;
				int rightOperand = operands.top();
				operands.pop();
				int leftOperand = operands.top();
				operands.pop();
				switch (firstChar){
				case '+':
					result = leftOperand + rightOperand;
					break;
				case '-':
					result = leftOperand - rightOperand;
					break;
				case '*':
					result = leftOperand * rightOperand;
					break;
				case '/':
					result = leftOperand / rightOperand;
					break;
				}
				operands.push(result);
			}
			else{
				operands.push(atoi(tokens[i].c_str()));
			}
		}
		return operands.top();
	}
};

import java.util.Stack;

public class Solution {
    public int evalRPN(String[] tokens) {
        int a,b;
        Stack<Integer> S = new Stack<Integer>();
        for (String s : tokens) {
            if(s.equals("+")) {
                S.add(S.pop()+S.pop());
            }
            else if(s.equals("/")) {
                b = S.pop();
                a = S.pop();
                S.add(a / b);
            }
            else if(s.equals("*")) {
                S.add(S.pop() * S.pop());
            }
            else if(s.equals("-")) {
                b = S.pop();
                a = S.pop();
                S.add(a - b);
            }
            else {
                S.add(Integer.parseInt(s));
            }
        }   
        return S.pop();
    }
}

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