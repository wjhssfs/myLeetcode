// 787. Cheapest Flights Within K Stops
// There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

// Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

// Example 1:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200
// Explanation: 
// The graph looks like this:


// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
// Example 2:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500
// Explanation: 
// The graph looks like this:


// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
// Note:

// The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
// The size of flights will be in range [0, n * (n - 1) / 2].
// The format of each flight will be (src, dst, price).
// The price of each flight will be in the range [1, 10000].
// k is in the range of [0, n - 1].
// There will not be any duplicated flights or self cycles.

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[] dis = new int[n];
        int[] pre = new int[n];
        Arrays.fill(dis, Integer.MAX_VALUE / 2);
        Arrays.fill(pre, Integer.MAX_VALUE / 2);
        dis[src] = pre[src] = 0;

        for (int i = 0; i <= K; ++i) {
            for (int[] edge: flights)
                dis[edge[1]] = Math.min(dis[edge[1]], pre[edge[0]] + edge[2]);

            pre = dis;
        }

        return dis[dst] < Integer.MAX_VALUE / 2 ? dis[dst] : -1;
    }
}

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[][] graph = new int[n][n];
        for (int[] flight: flights)
            graph[flight[0]][flight[1]] = flight[2];

        Map<int[], Integer> best = new HashMap();

        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, src});

        while (!pq.isEmpty()) {
            int[] info = pq.poll();
            int cost = info[0], k = info[1], place = info[2];
            if (k > K+1 || cost > best.getOrDefault(new int[]{k, place}, Integer.MAX_VALUE))
                continue;
            if (place == dst)
                return cost;

            for (int nei = 0; nei < n; ++nei) if (graph[place][nei] > 0) {
                int newcost = cost + graph[place][nei];
                if (newcost < best.getOrDefault(new int[]{k+1, nei}, Integer.MAX_VALUE)) {
                    pq.offer(new int[]{newcost, k+1, nei});
                    best.put(new int[]{k+1, nei}, newcost);
                }
            }
        }

        return -1;
    }
}


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> m; // src => (dst, price)
        for (auto&& f : flights) m[f[0]].emplace_back(f[1], f[2]);
        vector<int> cost(n, INT_MAX);
        queue<int> q, nextq; 
        cost[src] = 0;
        nextq.push(src);
        while(nextq.size() && K + 1) {
            --K;
            swap(q, nextq);
            while (q.size()) {
                auto cur = q.front(); q.pop();
                for (auto next : m[cur]) {
                    if (cost[next.first] > cost[cur] + next.second) {
                        cost[next.first] = cost[cur] + next.second;
                        nextq.push(next.first);
                    }
                }
            }
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst] ;
    }
};