// 500. Keyboard Row
// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


// American keyboard


// Example 1:
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
// Note:
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows{"qwertyuiop","adsfghjkl","zxcvbnm"}, res;
        for (auto && word : words) {
            vector<int> inRow(3);
            for (auto c : word) {
                c = tolower(c);
                for (int i = 0; i < rows.size(); ++i) {
                    if (rows[i].find(c) != string::npos) inRow[i] = 1;
                }
            }
            int total = accumulate(inRow.begin(), inRow.end(), 0);
            if ( total == 1) {
                res.push_back(word);   
            }
        }
        return res;
    }
};

def findWords(self, words):
    return filter(re.compile('(?i)([qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*)$').match, words)