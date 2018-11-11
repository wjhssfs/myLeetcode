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

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.empty()) return vector<string>();
    static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");   // add a seed for the initial case
    for(int i = 0 ; i < digits.size(); ++i) {
        int num = digits[i]-'0';
        if(num < 0 || num > 9) break;
        const string& candidate = v[num];
        if(candidate.empty()) continue;
        vector<string> tmp;
        for(int j = 0 ; j < candidate.size() ; ++j) {
            for(int k = 0 ; k < result.size() ; ++k) {
                tmp.push_back(result[k] + candidate[j]);
            }
        }
        result.swap(tmp);
    }
    return result;
}


// T9   2 for a, 22 is for b, 222 for c
class Solution {
    vector<string> m = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    void dfs(const string& digits, int i, vector<string>& res, string& cur, vector<string>& m) {
        if (i == digits.size()) res.push_back(cur);
        else {
            for (int j = 0; i + j < digits.size() && j < m[digits[i] - '0'].size() && digits[i] == digits[i + j]; ++j) {
                cur += m[digits[i]- '0'][j];
                dfs(digits, i + j + 1, res, cur, m);
                cur.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> res;
        string cur;
        dfs(digits, 0, res, cur, m);
        return res;
    }
};