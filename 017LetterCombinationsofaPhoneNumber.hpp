// 17 Letter Combinations of a Phone Number 
// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.

// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
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
