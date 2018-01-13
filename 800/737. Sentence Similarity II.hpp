// 737. Sentence Similarity II
// Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

// For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

// Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.

// Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

// Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

// Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

// Note:

// The length of words1 and words2 will not exceed 1000.
// The length of pairs will not exceed 2000.
// The length of each pairs[i] will be 2.
// The length of each words[i] and pairs[i][j] will be in the range [1, 20].

class Solution {
    string find(unordered_map<string, string>& u, string& cur) {
        if (u.count(cur) == 0) u[cur] = cur;
        while (u[cur] != cur) cur = u[cur];
        return cur;
    }
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, string> u;
        for (auto&& pair : pairs) {
            auto r1 = find(u, pair.first);
            auto r2 = find(u, pair.second);
            if (r1 != r2) {
                u[r1] = r2;
            }
        }
        for (size_t i = 0; i < words1.size(); ++i) {
            if (find(u, words1[i]) != find(u, words2[i])) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& a, vector<string>& b, vector<pair<string, string>> pairs) {
        if (a.size() != b.size()) return false;
        map<string, string> m;
        for (pair<string, string> p : pairs) {
            string parent1 = find(m, p.first), parent2 = find(m, p.second);
            if (parent1 != parent2) m[parent1] = parent2;
        }

        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i] && find(m, a[i]) != find(m, b[i])) return false;

        return true;
    }

private:
    string find(map<string, string>& m, string s) {
        return !m.count(s) ? m[s] = s : (m[s] == s ? s : find(m, m[s]));
    }
};