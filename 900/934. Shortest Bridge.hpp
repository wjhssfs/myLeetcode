// 934. Shortest Bridge

// In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

// Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

// Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

 

// Example 1:

// Input: [[0,1],[1,0]]
// Output: 1
// Example 2:

// Input: [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2
// Example 3:

// Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1
 

// Note:

// 1 <= A.length = A[0].length <= 100
// A[i][j] == 0 or A[i][j] == 1

class Solution {
    vector<int> d = {0, -1, 0, 1, 0};
    void dfs(int x, int y, vector<vector<int>>& A, set<pair<int, int>>& edges) {
        
        A[x][y] = 2;
        for (int i = 0; i < 4; ++i) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (nx < 0 || ny < 0 || nx == A.size() || ny == A[0].size() || A[nx][ny] == 2) continue;
            if (A[nx][ny] == 0) {
                edges.insert(make_pair(x, y));
                continue;
            }
            dfs(nx, ny, A, edges);
        }
    }
    
public:
    int shortestBridge(vector<vector<int>>& A) {
        set<pair<int, int>> edges;
        queue<pair<int, int>> q;
        
        for (int i = 0, done = 0; i < A.size() && !done; ++i) {
            for (int j = 0; j < A[0].size() && !done; ++j) {
                if (A[i][j] == 1) {
                    dfs(i, j, A, edges);
                    done = 1;
                }
            }
        }
        for (auto e : edges) q.push(e);
        int step = -1;
        while (q.size()) {
            int sz = q.size();
            ++step;
            for (int i = 0; i < sz; ++i) {
                int x = q.front().first, y = q.front().second;
                //cout << x << " " << y << endl;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + d[i], ny = y + d[i + 1];
                    if (nx < 0 || ny < 0 || nx == A.size() || ny == A[0].size() || A[nx][ny] == 2) continue;
                    //cout << "next" <<  nx << " " << ny << endl;
                    if (A[nx][ny] == 1) return step;
                    A[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        return -1;
    }
};