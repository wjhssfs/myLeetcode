// 320. Generalized Abbreviation
// Write a function to generate the generalized abbreviations of a word.

// Example:
// Given word = "word", return the following list (order does not matter):
// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        gen(word, 0, "", result);
        return result;
    }
    
    void gen(const string &word, int left, string cur, vector<string> &result)
    {
        if(word.empty()) {
            if(left)
                cur += to_string(left);
            result.emplace_back(cur);
            return;
        }
        string restWord = word.substr(1);
        gen(restWord, left + 1, cur, result);
        if(left){
            cur += to_string(left);
        }
        gen(restWord, 0, cur + word[0], result);
    }
};

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        generateAbbreviationsHelper(word, "", 0, result, false);
        return result;
    }
    
    void generateAbbreviationsHelper(string& word, string abbr, int i, vector<string>& result, bool prevNum) {
        if (i == word.length()) {
            result.push_back(abbr);
            return;
        }
        
        generateAbbreviationsHelper(word, abbr+word[i], i+1, result, false);
        if (!prevNum) {
            // Add number abbreviations only when we added a character instead of an abbreviation earlier
            for (int len = 1; i+len <= word.length(); ++len) {
                generateAbbreviationsHelper(word, abbr+to_string(len), i+len, result, true);
            }
        }
    }
};