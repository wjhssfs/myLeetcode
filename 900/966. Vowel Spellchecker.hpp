// 966. Vowel Spellchecker

// Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

// For a given query word, the spell checker handles two categories of spelling mistakes:

// Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
// Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
// Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
// Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
// Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
// Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
// Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
// Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
// In addition, the spell checker operates under the following precedence rules:

// When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
// When the query matches a word up to capitlization, you should return the first such match in the wordlist.
// When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
// If the query has no matches in the wordlist, you should return the empty string.
// Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

 

// Example 1:

// Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
// Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 

// Note:

// 1 <= wordlist.length <= 5000
// 1 <= queries.length <= 5000
// 1 <= wordlist[i].length <= 7
// 1 <= queries[i].length <= 7
// All strings in wordlist and queries consist only of english letters.

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> m;
        unordered_set<string> org;
        for (auto && word : wordlist) {
            org.insert(word);
            string cap = word;
            transform(cap.begin(), cap.end(), cap.begin(), ::tolower);
            if (m.count(cap) == 0) m[cap] = word;
        }
        for (auto && word : wordlist) {
            string vowel;
            for (auto c : word) {
                c = tolower(c);
                if (string("aeiou").find(c) != string::npos) c = '0';
                vowel.push_back(c);
            }
            if (m.count(vowel) == 0) m[vowel] = word;
        }
        vector<string> res;
        for (auto&& q : queries) {
            if (org.count(q)) {
                res.push_back(q);
                continue;
            }
            
            string cap;
            for (auto c : q) cap.push_back(tolower(c));
            if (m.count(cap)) {
                res.push_back(m[cap]);
                continue;
            }
            
            string vowel;
            for (auto c : q) {
                c = tolower(c);
                if (string("aeiou").find(c) != string::npos) c = '0';
                vowel.push_back(c);
            }
            if (m.count(vowel)) res.push_back(m[vowel]);
            else res.push_back("");
        }
        return res;
    }
};