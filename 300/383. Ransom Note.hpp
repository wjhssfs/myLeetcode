// 383. Ransom Note
// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// Each letter in the magazine string can only be used once in your ransom note.

// Note:
// You may assume that both strings contain only lowercase letters.

// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hasLetter[128] = {};
        for (auto c : magazine) {
            ++hasLetter[c];
        }
        for (auto c : ransomNote) {
            if (!hasLetter[c]) return false;
            --hasLetter[c];
        }
        return true;
    }
};

// the dictionary subtraction operator keeps only positive values, so not here essentially means
// “return False if there are any positive values”. 
def canConstruct(self, ransomNote, magazine):
    return not collections.Counter(ransomNote) - collections.Counter(magazine)