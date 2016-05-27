// 66 Plus One 
// Given a non-negative number represented as an array of digits, plus one to the number.
// The digits are stored such that the most significant digit is at the head of the list.
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        int carry = 1;
        for(int i = digits.size() - 1; i>=0; i--){
            if(carry){
                digits[i]++;
                if(digits[i]==10){
                    digits[i]=0;
                    carry = 1;
                }else{
                    carry = 0;
                }
            }
            result.push_back(digits[i]);
        }
        if(carry)result.push_back(1);
        vector<int> ret(result.rbegin(), result.rend());
        return ret;
    }
};

class Solution2 {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1, N = digits.size();
        for (int i = N-1; i >= 0 && carry; --i)
        {
            int sum = carry + digits[i];
            carry = sum / 10;
            digits[i] = sum % 10;
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

void plusone(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return;
        }
    }
        digits[0] =1;
        digits.push_back(0);

}