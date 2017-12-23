// 720. Longest Word in Dictionary
// Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

// If there is no answer, return the empty string.
// Example 1:
// Input: 
// words = ["w","wo","wor","worl", "world"]
// Output: "world"
// Explanation: 
// The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
// Example 2:
// Input: 
// words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// Output: "apple"
// Explanation: 
// Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
// Note:

// All the strings in the input will only contain lowercase letters.
// The length of words will be in the range [1, 1000].
// The length of words[i] will be in the range [1, 30].

// Sort the words alphabetically, therefore shorter words always comes before longer words;
// Along the sorted list, populate the words that can be built;
// Any prefix of a word must comes before that word.

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res;
        for (string w : words) {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
                res = w.size() > res.size() ? w : res;
                built.insert(w);
            }
        }
        return res;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string&b) { 
            return a.size() > b.size() || (a.size() == b.size() && a < b);});
        unordered_set<string> m;
        for (auto&& word : words) m.insert(word);
        for (auto&& word : words) {
            int i = 1;
            for (; i <= word.size(); ++i) {
                if (m.count(word.substr(0, i)) == 0) break;
            }
            if (i > word.size()) return word;
        }
        return "";
    }
};