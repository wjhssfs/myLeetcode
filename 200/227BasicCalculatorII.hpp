// 227 Basic Calculator II
// Implement a basic calculator to evaluate a simple expression string.
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
// You may assume that the given expression is always valid.
// Some examples:
// "3+2*2" = 7
// " 3/2 " = 1
// " 3+5 / 2 " = 5
class Solution {
public:
    int calculate(string s) {
        int result = 0, cur_res = 0;
        char op = '+';
        for(int pos = s.find_first_not_of(' '); pos < s.size(); pos = s.find_first_not_of(' ', pos)) {
            if(isdigit(s[pos])) {
                int tmp = s[pos] - '0';
                while(++pos < s.size() && isdigit(s[pos]))
                    tmp = tmp*10 + (s[pos] - '0');
                switch(op) {
                    case '+' : cur_res += tmp; break;
                    case '-' : cur_res -= tmp; break;
                    case '*' : cur_res *= tmp; break;
                    case '/' : cur_res /= tmp; break;
                }
            }
            else {
                if(s[pos] == '+' || s[pos] == '-') {
                    result += cur_res;
                    cur_res = 0;
                }
                op = s[pos++];
            }
        }
        return result + cur_res;
    }
};

// If you don't like the 44 - op ASCII trick, you can use op == '+' ? 1 : -1 instead
int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' || op == '-') {
            total += term;
            in >> term;
            term *= 44 - op;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}

class Solution {
    stack<int> nums;
    stack<char> ops;
public:
    int calculate(string s) {
        if (s.empty()) return 0;
        int index = 0, value = 0;
        char t = match(s, index, value);
        while (ops.empty() || ops.top()!='$'){
            if (t == '#'){
                nums.push(value);
            }
            else if (ops.empty() || pri(ops.top()) < pri(t)){
                ops.push(t);
            }
            else{
                while (!ops.empty() && pri(ops.top()) >= pri(t)){
                    int op2 = nums.top(); nums.pop();
                    int op1 = nums.top(); nums.pop();
                    if (ops.top() == '+') nums.push(op1 + op2);
                    if (ops.top() == '-') nums.push(op1 - op2);
                    if (ops.top() == '*') nums.push(op1 * op2);
                    if (ops.top() == '/') nums.push(op1 / op2);
                    ops.pop();
                }
                ops.push(t);
            }
            t = match(s, index, value);
        }

        return nums.top();
    }

    int pri(char c){
        if (c == '$') return 0;
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
    }

    char match(string &s, int &index, int &value){
        while (s[index] == ' ') ++index;
        if (index == s.size()) return '$';
        if (isdigit(s[index])){
            value = 0;
            while (index < s.size() && isdigit(s[index])){
                value *= 10;
                value += s[index] - '0';
                ++index;
            }
            return '#';
        }
        return s[index++];
    }
};