// 772. Basic Calculator III
// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

// The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

// Some examples:

// "1 + 1" = 2
// " 6-4 / 2 " = 4
// "2*(5+5*2)/3+(6/2+8)" = 21
// "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 

// Note: Do not use the eval built-in library function.

// https://leetcode.com/problems/basic-calculator-iii/discuss/113592/Development-of-a-generic-solution-for-the-series-of-the-calculator-problems
class Solution {
    //parse to the end of to next ')'
    int eval(string& s, int& i) {
        int res = 0, cur = 0, v = 0;
        char lastOp = '+';
        while (i < s.size()) {
            if (s[i] == ')') {++i; break;}
            if (s[i] == ' ') {++i; continue;}
            bool calc = false;
            if (isdigit(s[i])) {
                calc = true;
                v = 0;
                while (i < s.size() && isdigit(s[i])) {
                    v = v * 10 + s[i++] - '0';
                }
             } else if (s[i] == '(') {
                v = eval(s, ++i);
                calc = true;
            }
            
            if (calc) {
                if (lastOp == '+') cur = v;
                if (lastOp == '-') cur = -v;
                if (lastOp == '*') cur *= v;
                if (lastOp == '/') cur /= v;
            }
            
            if (s[i] == '+' || s[i] == '-') {
                res += cur;
                lastOp = s[i++];
            } else if (s[i] == '*' || s[i] == '/') {
                lastOp = s[i++];
            }
        }
        return res + cur;
    }
public:
    int calculate(string s) {
        int i = 0;
        return eval(s, i);
    }
};

class Solution {
    bool Parse(const string& s, int& i, char& op, int &num) {
        op = 'X';
        num = 0;
        while (isspace(s[i]) && i < s.size()) ++i;
        if (i == s.size()) return false;
        op = s[i];
        if (isdigit(s[i])) {
            while (isdigit(s[i]) && i < s.size()) {
                num = num * 10 + s[i++] - '0';
            }
        } else ++i;
        //cout << op << " " << num << endl;;
        return true;
    }
    void cal(stack<char>& ops, stack<int>& nums) {
        int num2 = nums.top(); nums.pop();
        int num1 = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        if (op == '+') nums.push(num1 + num2);
        else if (op == '-') nums.push(num1 - num2);
        else if (op == '*') nums.push(num1 * num2);
        else nums.push(num1 / num2);
        //cout << "cal: " << num1 << " " << num2 << " " << nums.top() << endl;
    }
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        int i = 0, num;
        char op;
        while(Parse(s, i, op, num)) {
            if (op == '(') ops.push(op);
            else if (op == ')') {
                while (ops.top() != '(') cal(ops, nums);
                ops.pop();
            } else if (op == '*' || op == '/') {
                while (ops.size() && (ops.top() == '*' || ops.top() == '/')) cal(ops, nums);
                ops.push(op);
            } else if(op == '+' || op == '-') {
                while(ops.size() && ops.top() != '(') cal(ops, nums);
                ops.push(op);
            } else {
                nums.push(num);
            }
        }
        
        while (ops.size()) cal(ops, nums);
        return nums.empty() ? 0 : nums.top();
    }
};