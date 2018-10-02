// 407. Trapping Rain Water II
// Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

// Note:
// Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

// Example:

// Given the following 3x6 height map:
// [
//   [1,4,3,1,3,2],
//   [3,2,1,3,2,4],
//   [2,3,3,2,3,1]
// ]

// Return 4.

// The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.


// After the rain, water are trapped between the blocks. The total volume of water trapped is 4.

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m < 3) return 0;
        int n = heightMap[0].size();
        if (n < 3) return 0;
        vector<vector<char>> visited(m, vector<char>(n));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < m; ++i) {
            pq.emplace(heightMap[i][0], make_pair(i, 0));
            visited[i][0] = true;
            pq.emplace(heightMap[i][n-1], make_pair(i, n-1));
            visited[i][n-1] = true;
        }
        for (int i = 1; i < n - 1; ++i) {
            pq.emplace(heightMap[0][i], make_pair(0,i));
            visited[0][i] = true;
            pq.emplace(heightMap[m-1][i], make_pair(m-1, i));
            visited[m-1][i] = true;
        }
        
        int res = 0;
        while (pq.size()) {
            auto cur = pq.top(); pq.pop();
            //cout << cur.first << " " << cur.second.first << " " << cur.second.second << endl;
            int dir[] = {-1, 0, 1, 0, -1};
            for (int i = 0; i < 4; ++i) {
                int row = cur.second.first + dir[i];
                int col = cur.second.second + dir[i+1];
                if (row < 0 || row == m || col < 0 || col == n) continue;
                if (visited[row][col]) continue;
                visited[row][col] = true;
                res += max(0, cur.first - heightMap[row][col]);
                pq.emplace(max(cur.first, heightMap[row][col]), make_pair(row, col));
            }
        }
        return res;
    }
};

// https://discuss.leetcode.com/topic/60387/alternative-approach-using-dijkstra-in-o-rc-max-log-r-log-c-time
public class Solution {
    int[] dx = {0, 0, 1, -1};
    int[] dy = {1, -1, 0, 0};

    List<int[]>[] g;
    int start;

    private int[] dijkstra() {
        int[] dist = new int[g.length];
        Arrays.fill(dist, Integer.MAX_VALUE / 2);
        dist[start] = 0;
        TreeSet<int[]> tree = new TreeSet<>((u, v) -> u[1] == v[1] ? u[0] - v[0] : u[1] - v[1]);
        tree.add(new int[]{start, 0});
        while (!tree.isEmpty()) {
            int u = tree.first()[0], d = tree.pollFirst()[1];
            for (int[] e : g[u]) {
                int v = e[0], w = e[1];
                if (Math.max(d, w) < dist[v]) {
                    tree.remove(new int[]{v, dist[v]});
                    dist[v] = Math.max(d, w);
                    tree.add(new int[]{v, dist[v]});
                }
            }
        }
        return dist;
    }

    public int trapRainWater(int[][] a) {
        if (a == null || a.length == 0 || a[0].length == 0) return 0;
        int r = a.length, c = a[0].length;

        start = r * c;
        g = new List[r * c + 1];
        for (int i = 0; i < g.length; i++) g[i] = new ArrayList<>();
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1) g[start].add(new int[]{i * c + j, 0});
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < r && y >= 0 && y < c) g[i * c + j].add(new int[]{x * c + y, a[i][j]});
                }
            }

        int ans = 0;
        int[] dist = dijkstra();
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                int cb = dist[i * c + j];
                if (cb > a[i][j]) ans += cb - a[i][j];
            }

        return ans;
    }
}

