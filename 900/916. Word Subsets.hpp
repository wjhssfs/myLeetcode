// 916. Word Subsets
// We are given two arrays A and B of words.  Each word is a string of lowercase letters.

// Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".

// Now say a word a from A is universal if for every b in B, b is a subset of a. 

// Return a list of all universal words in A.  You can return the words in any order.

 

// Example 1:

// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
// Output: ["facebook","google","leetcode"]
// Example 2:

// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
// Output: ["apple","google","leetcode"]
// Example 3:

// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
// Output: ["facebook","google"]
// Example 4:

// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
// Output: ["google","leetcode"]
// Example 5:

// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
// Output: ["facebook","leetcode"]
 

// Note:

// 1 <= A.length, B.length <= 10000
// 1 <= A[i].length, B[i].length <= 10
// A[i] and B[i] consist only of lowercase letters.
// All words in A[i] are unique: there isn't i != j with A[i] == A[j].

class Solution {
    unordered_map<int, int> letterCount(string& word) {
        unordered_map<int, int> r;
        for (auto c : word) r[c]++;
        return r;
    }
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> res;
        unordered_map<int, int> req;
        for (auto&& word : B) {
            for (auto e : letterCount(word)) {
                req[e.first] = max(req[e.first], e.second);
            }
        }
        for (auto&& word : A) {
            auto counts = letterCount(word);
            bool insert = true;
            for (auto e : req) {
                if (counts[e.first] < e.second) {
                    insert = false;
                    break;
                }
            }
            if (insert)res.push_back(word);
        }
        return res;
    }
};

  def wordSubsets(self, A, B):
        uni = collections.Counter()
        for b in B:
            for c, n in collections.Counter(b).items():
                uni[c] = max(uni[c], n)
        res = []
        for a in A:
            count = collections.Counter(a)
            if all(count[c] >= uni[c] for c in uni):
                res.append(a)
        return res