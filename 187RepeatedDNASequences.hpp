// 187 Repeated DNA Sequences
// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
// For example,
// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].

// Using rolling hash, map A,C,G,T to 0,1,2,3. 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string &s) {
        vector<string> result;
        if (s.size() < 10) return result;
        vector<char> shown(0x100000, 0);
        char m['U'];
        m['A'] = 0; m['C'] = 1; m['G'] = 2; m['T'] = 3;

        int hash = 0;
        for (int i = 0; i < 10; i++) hash = ((hash << 2) | m[s[i]]);
        shown[hash] = 1;

        for (size_t i = 10; i < s.size(); i++){
            hash <<= 2;
            hash &= 0xFFFFF;
            hash |= m[s[i]];
            if (shown[hash] == 0) shown[hash] = 1;
            else if (shown[hash] == 1) {
                shown[hash] = 2;
                result.emplace_back(s.substr(i - 9, 10));
            }
        }
        return result;
    }
};

// https://leetcode.com/discuss/24478/i-did-it-in-10-lines-of-c
// lst 3 bits of 'A', 'C', 'G' and 'T' are differet
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    int t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = t << 3 | s[i++] & 7;
    while (i < ss)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    return r;
}