// 815. Bus Routes
// We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

// We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.

// Example:
// Input: 
// routes = [[1, 2, 7], [3, 6, 7]]
// S = 1
// T = 6
// Output: 2
// Explanation: 
// The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
// Note:

// 1 <= routes.length <= 500.
// 1 <= routes[i].length <= 500.
// 0 <= routes[i][j] < 10 ^ 6.

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        unordered_map<int, vector<int>> m; // stop to route index
        for (int i = 0; i < routes.size(); ++i) for (auto stop : routes[i]) m[stop].push_back(i);
        
        unordered_set<int> cur = {S};
        unordered_set<int> visited;
        unordered_set<int> visitedBus;
        int num = 0;
        while (cur.size()) {
            ++num;
            unordered_set<int> next;
            visited.insert(cur.begin(), cur.end());
            for (auto curStop : cur) {
                for (auto bus : m[curStop]) {
                    if (visitedBus.count(bus)) continue; // important
                    visitedBus.insert(bus);
                    for (auto nextstop : routes[bus]) {
                        if (nextstop == T) return num;
                        if (visited.count(nextstop) == 0) {
                            next.insert(nextstop);
                        }
                    }
                }
            }
            cur.clear();
            swap(cur, next);
        }
        return -1;
    }
};