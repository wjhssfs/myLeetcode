// 621. Task Scheduler
// Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

// However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

// You need to return the least number of intervals the CPU will take to finish all the given tasks.

// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
// Note:
// The number of tasks is in the range [1, 10000].
// The integer n is in the range [0, 100].

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