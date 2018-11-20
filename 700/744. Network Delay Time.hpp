// 744. Network Delay Time
// There are N network nodes, labelled 1 to N.

// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

// Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

// Note:
// N will be in the range [1, 100].
// K will be in the range [1, N].
// The length of times will be in the range [1, 6000].
// All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> connect(N + 1, vector<int>(N + 1, INT_MAX));
        vector<int> minD(N + 1, INT_MAX);
        for (auto&& time : times) {
            connect[time[0]][time[1]] = time[2];
        }
        priority_queue<pair<int, int>> q;
        q.emplace(0, K);
        while (!q.empty()) {
            int cur = q.top().second;
            int dCur = abs(q.top().first);
            q.pop();
            for (int next = 1; next <= N; ++next) {
                if ((connect[cur][next] != INT_MAX) && (minD[next] > dCur+ connect[cur][next])) {
                    minD[next] = dCur + connect[cur][next];
                    q.emplace(-minD[next], next);
                }
            }
        }
        int minTime = 0;
        for (int i = 1; i <= N; ++i) {
            if (i == K) continue;
            minTime = max(minTime, minD[i]);
        }
        return minTime == INT_MAX ? -1 : minTime;
    }
};

// https://leetcode.com/problems/network-delay-time/discuss/109982/C++-Bellman-Ford
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};