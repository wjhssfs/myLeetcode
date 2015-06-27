// 224 Basic Calculator 
// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

// You may assume that the given expression is always valid.

// Some examples:
// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23


class Solution {
public:
    enum TokenType{
        End,
        LeftP,
        RightP,
        Plus,
        Minus,
        Num
    };

    int calculate(string s) {
        if (s.empty()) return 0;
        int i = 0, value = 0;
        vector<TokenType> tokens;
        stack<int> nums;
        TokenType t;
        while ((t = match(s, i, value)) != TokenType::End)
        {
            tokens.push_back(t);
            if (t == TokenType::Num) nums.push(value);
            while (1)
            {
                if (tokens.size() > 2)
                {
                    if (tokens[tokens.size() - 1] == TokenType::Num && (tokens[tokens.size() - 2] == TokenType::Plus || tokens[tokens.size() - 2] == TokenType::Minus))
                    {
                        int op2 = nums.top();
                        nums.pop();
                        tokens[tokens.size() - 2] == TokenType::Plus ? nums.top() += op2 : nums.top() -= op2;
                        tokens.pop_back();
                        tokens.pop_back();
                    }
                    else if (tokens[tokens.size() - 1] == TokenType::RightP)
                    {
                        tokens.pop_back();
                        tokens.pop_back();
                        tokens.back() = TokenType::Num;
                    }
                    else
                        break;
                }
                else
                    break;
            }
        }
        return nums.top();
    }
    TokenType match(const string &s, int& i, int &value){
        value = 0;
        while (i < s.size() && (s[i] == ' ')) i++;
        if (i == s.size()) return TokenType::End;
        if (s[i] == '(') { ++i; return TokenType::LeftP; }
        if (s[i] == ')') { ++i; return TokenType::RightP; }
        if (s[i] == '+') { ++i; return TokenType::Plus; }
        if (s[i] == '-') { ++i; return TokenType::Minus; }
        value = s[i] - '0';
        ++i;
        while (i < s.size() && isdigit(s[i])){
            value *= 10;
            value += s[i] - '0';
            ++i;
        }
        return TokenType::Num;
    }
};