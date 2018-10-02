// 738. Monotone Increasing Digits
// Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

// (Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

// Example 1:
// Input: N = 10
// Output: 9
// Example 2:
// Input: N = 1234
// Output: 1234
// Example 3:
// Input: N = 332
// Output: 299
// Note: N is an integer in the range [0, 10^9].

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        size_t i = 0;
        for (; i + 1 < str.size() && str[i] <= str[i + 1]; ++i) ;
        if (i + 1 == str.size()) return N;
        while (i > 0 && str[i - 1] == str[i]) --i;
        --str[i++];
        while(i < str.size()) str[i++] = '9';
        return stoi(str);
    }
};

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string n_str = to_string(N);
        
        int marker = n_str.size();
        for(int i = n_str.size()-1; i > 0; i --) {
            if(n_str[i] < n_str[i-1]) {
                marker = i;
                n_str[i-1] = n_str[i-1]-1;
            }
        }
        
        for(int i = marker; i < n_str.size(); i ++) n_str[i] = '9';
        
        return stoi(n_str);
    }
};