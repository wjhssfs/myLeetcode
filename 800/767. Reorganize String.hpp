// 767. Reorganize String
// Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

// If possible, output any possible result.  If not possible, return the empty string.

// Example 1:

// Input: S = "aab"
// Output: "aba"
// Example 2:

// Input: S = "aaab"
// Output: ""
// Note:

// S will consist of lowercase letters and have length in range [1, 500].

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> m;
        for (auto c : S) m[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto&& e : m) pq.emplace(e.second, e.first);
        if (pq.top().first * 2 - 1 > S.size()) return {};
        string result;
        while (!pq.empty()){
            auto c = pq.top();
            if (result.empty() || c.second != result.back()) {
                result.push_back(c.second);
                pq.pop();
                if (--c.first) pq.push(c);
            } else if (pq.size()) {
                pq.pop();
                auto c2 = pq.top();
                result.push_back(c2.second);
                pq.pop();
                if (--c2.first) pq.push(c2);
                pq.push(c);
            } else break;
        }
        return pq.empty() ? result : "";
    }
};