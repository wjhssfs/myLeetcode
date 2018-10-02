// 692. Top K Frequent Words
// Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.

// O(n)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (auto&& word : words) ++count[word];
        vector<set<string>> s(words.size() + 1);
        for (auto&& elem : count) s[elem.second].insert(elem.first);
        vector<string> result;
        for (int i = words.size(); i > 0 && result.size() != k; --i) {
            for (auto&& word : s[i]) {
                result.push_back(word);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};

// O(nlog(k))
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (auto&& word : words) ++count[word];
        priority_queue<pair<int, string>> pq;
        for (auto&& elem : count) {
            pq.push(make_pair(-elem.second, elem.first));
            if (pq.size() > k) pq.pop();
        }
        vector<string> result(k);
        while (pq.size()) {
            result[pq.size() - 1] = pq.top().second;
            pq.pop();
        }
        return result;
    }
};