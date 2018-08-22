// 433. Minimum Genetic Mutation

// A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

// Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

// For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

// Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

// Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

// Note:

// Starting point is assumed to be valid, so it might not be included in the bank.
// If multiple mutations are needed, all mutations during in the sequence must be valid.
// You may assume start and end string is not the same.
 

// Example 1:

// start: "AACCGGTT"
// end:   "AACCGGTA"
// bank: ["AACCGGTA"]

// return: 1
 

// Example 2:

// start: "AACCGGTT"
// end:   "AAACGGTA"
// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

// return: 2
 

// Example 3:

// start: "AAAAACCC"
// end:   "AACCCCCC"
// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

// return: 3

class Solution {
public:
  int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end)) return -1;
        unordered_set<string> smallSet, largeSet;
        smallSet.insert(start), largeSet.insert(end);
        int step = 0;
        while (!smallSet.empty() && !largeSet.empty()) {
            if (smallSet.size() > largeSet.size()) swap(smallSet, largeSet);
            unordered_set<string> tmp;
            step++;
            for (auto&& d : smallSet) {
                for (int i = 0; i < 8; ++i) {
                    string dna = d; 
                    for (auto&& g : string("ATGC")) {
                        dna[i] = g;
                        if (largeSet.count(dna)) return step;
                        auto it = dict.find(dna);
                        if (it != dict.end()) {
                            tmp.insert(dna);
                            dict.erase(it);
                        }
                    }
                }
            }
            smallSet = tmp;
        }
        return -1;
  }
};