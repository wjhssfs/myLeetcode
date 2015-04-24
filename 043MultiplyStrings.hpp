// 43 Multiply Strings 
// Given two numbers represented as strings, return multiplication of the numbers as a string.

// Note: The numbers can be arbitrarily large and are non-negative.

class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(),0);
        num1.assign(num1.rbegin(), num1.rend());
        num2.assign(num2.rbegin(), num2.rend());
        for_each(num1.begin(), num1.end(), [](char&c){c -= '0'; });
        for_each(num2.begin(), num2.end(), [](char&c){c -= '0'; });
        int i, j;
        for (i = 0; i < num2.size(); i++){
            int preCarry = 0;
            for (j = 0; j < num1.size(); j++){
                int r = result[i+j] + num2[i] * num1[j] + preCarry;
                result[i + j] = r % 10;
                preCarry = r / 10;
            }
            result[i + j] = preCarry;
        }
        while (result.size() > 1 && result[result.size() - 1] == 0) result.erase(result.size() - 1);
        result.assign(result.rbegin(), result.rend());
        for_each(result.begin(), result.end(), [](char &c){c += '0'; });
        return result;
    }
};

class Solution2 {
public:
    string multiply(string num1, string num2) {
        int N = num1.size(), M = num2.size();
        string res(N+M, '0');
        for (int i = N - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = M - 1; j >= 0; --j)
            {
                int sum = carry + (res[i+j+1] - '0') + 
                          (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            res[i] += carry;
        }
        while (res.size() > 1 && res[0] == '0')
            res.erase(res.begin());
        return res;
    }
};
