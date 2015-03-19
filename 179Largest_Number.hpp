// 179 Largest Number 
// Given a list of non negative integers, arrange them such that they form the largest number.
// 
// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
// 
// Note: The result may be very large, so you need to return a string instead of an integer.
// 

class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), [](int a, int b){
            string aStr = to_string(a), bStr = to_string(b);
            return aStr + bStr < bStr + aStr;
        });
        string result;
        for_each(num.rbegin(), num.rend(), [&result](int n){result += to_string(n); });
        int i = 0;
        while (i < result.size() - 1 && result[i] == '0')i++;
        return result.substr(i);
    }
};