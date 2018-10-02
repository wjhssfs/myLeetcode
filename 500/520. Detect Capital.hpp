// 520. Detect Capital
// Given a word, you need to judge whether the usage of capitals in it is right or not.

// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.
// Example 1:
// Input: "USA"
// Output: True
// Example 2:
// Input: "FlaG"
// Output: False
// Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (char c : word) if (isupper(c)) ++cnt;
        return !cnt || cnt == word.size() || cnt == 1 && isupper(word[0]);
    }
};

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        bool isCap = word.back() >= 'A' && word.back() <= 'Z';
        if (isCap) {
            for (int i = word.size() - 2; i >= 0; --i) {
                if (!(word[i] >= 'A' && word[i] <= 'Z')) return false;
            }
            return true;
        } else {
            for (int i = word.size() - 2; i >= 1; --i) {
                if (word[i] >= 'A' && word[i] <= 'Z') return false;
            }
            return true;
        }
    }
};