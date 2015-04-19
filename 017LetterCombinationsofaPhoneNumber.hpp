// 17 Letter Combinations of a Phone Number 
// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.

// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        static char const dTL[8][4] = {
            { 'a', 'b', 'c' },
            { 'd', 'e', 'f' },
            { 'g', 'h', 'i' },
            { 'j', 'k', 'l' },
            { 'm', 'n', 'o' },
            { 'p', 'q', 'r', 's' },
            { 't', 'u', 'v' },
            { 'w', 'x', 'y', 'z' },
        };
        _result.clear();
        _digits.swap(digits);
        _dTL = &dTL;
        doWork(0);
        return _result;
    }

private:
    void doWork(int curDigits)
    {
        if ((_digits.size() == curDigits))
        {
            _result.push_back(_strBuff);
        }
        else
        {
            int digitIndex = _digits[curDigits] - '2';
            assert(digitIndex >= 0 && digitIndex < 8);
            for (size_t j = 0; j < 4 && (*_dTL)[digitIndex][j] != 0; j++)
            {
                _strBuff.push_back((*_dTL)[digitIndex][j]);
                doWork(curDigits + 1);
                _strBuff.pop_back();
            }
        }
    }

    string _strBuff;
    string _digits;
    vector<string> _result;
    char const (*_dTL)[8][4];
};

class Solution2 {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        string mapping[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.clear();
        string s;
        letterCombinationsRe(digits, mapping, s);
        return res;
    }

    void letterCombinationsRe(const string &digits, string mapping[], string &s)
    {
        if (s.size() == digits.size())
        {
            res.push_back(s);
            return;
        }
        string &letters = mapping[digits[s.size()]-'2'];
        for (int i = 0; i < letters.size(); ++i)
        {
            s.push_back(letters[i]);
            letterCombinationsRe(digits, mapping, s);
            s.pop_back();
        }
    }
};
