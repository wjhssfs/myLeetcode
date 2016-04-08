// 224 Basic Calculator 
// Implement a basic calculator to evaluate a simple expression string.
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
// You may assume that the given expression is always valid.
// Some examples:
// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23

// Example: 7 - ( 6 - 5 - ( 4 - 3 ) - 2 ) - ( 1 )
// Result: + 7 - 6 + 5 + 4 - 3 + 2 - 1
// The bold + - are signs just before '('. They are dealt with previous stack sign. They are saved in the stack to help decide the signs in the following parentheses
class Solution {
public:
    int calculate(string s) {
        stack<int> t;  //previous sign just before the '('
        t.push(1);  //for all the signs those are not in the parentheses
        int sum=0, temp=0, lastSign=1;
        for(auto c: s)
        {
            if(c=='(') t.push(lastSign); //save the sign just before the '('
            else if(c==')') t.pop();

            if(c>='0' && c<='9'){  
                temp=temp*10+c-'0';
            }

            if(c=='-'||c=='+')
            {
                sum+=lastSign*temp; //calculate the number before current sign
                temp=0;
                lastSign=(c=='-'?-1:1)*t.top();  //deal with the stack influencing sign
            }
        }
        sum+=lastSign*temp; //calculate the last number
        return sum;
    }
};
