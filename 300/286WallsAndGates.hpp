// 286 Walls and Gates

// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

// For example, given the 2D grid:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// After running your function, the 2D grid should be:
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i = 0; i < rooms.size(); i++) {
            for(int j = 0; j < rooms[0].size();j++){
                if(rooms[i][j]==0){
                    BFS(rooms,i,j);
                }
            }
        }
    }
    
    void BFS(vector<vector<int>>& rooms, int x, int y) {
        queue<pair<int, int>> q;
        q.push(make_pair(x,y));
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if(cur.first > 0 && rooms[cur.first-1][cur.second] > rooms[cur.first][cur.second] + 1){
                rooms[cur.first-1][cur.second] = rooms[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first-1, cur.second));
            }
            if(cur.first < rooms.size()-1 && rooms[cur.first+1][cur.second] > rooms[cur.first][cur.second] + 1){
                rooms[cur.first+1][cur.second] = rooms[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first+1, cur.second));
            }
            if(cur.second > 0 && rooms[cur.first][cur.second-1] > rooms[cur.first][cur.second] + 1){
                rooms[cur.first][cur.second-1] = rooms[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first, cur.second-1));
            }
            if(cur.second < rooms[0].size()-1 && rooms[cur.first][cur.second + 1] > rooms[cur.first][cur.second] + 1){
                rooms[cur.first][cur.second+1] = rooms[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first, cur.second+1));
            }
        }
    }
};

// Push all gates into queue first. Then for each gate update its neighbor cells and push them to the queue. Repeating above steps until there is nothing left in the queue.
public class Solution {
    public void wallsAndGates(int[][] rooms) {
        if (rooms.length == 0 || rooms[0].length == 0) return;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < rooms.length; i++) {
            for (int j = 0; j < rooms[0].length; j++) {
                if (rooms[i][j] == 0) queue.add(new int[]{i, j});
            }
        }
        while (!queue.isEmpty()) {
            int[] top = queue.remove();
            int row = top[0], col = top[1];
            if (row > 0 && rooms[row - 1][col] == Integer.MAX_VALUE) {
                rooms[row - 1][col] = rooms[row][col] + 1;
                queue.add(new int[]{row - 1, col});
            }
            if (row < rooms.length - 1 && rooms[row + 1][col] == Integer.MAX_VALUE) {
                rooms[row + 1][col] = rooms[row][col] + 1;
                queue.add(new int[]{row + 1, col});
            }
            if (col > 0 && rooms[row][col - 1] == Integer.MAX_VALUE) {
                rooms[row][col - 1] = rooms[row][col] + 1;
                queue.add(new int[]{row, col - 1});
            }
            if (col < rooms[0].length - 1 && rooms[row][col + 1] == Integer.MAX_VALUE) {
                rooms[row][col + 1] = rooms[row][col] + 1;
                queue.add(new int[]{row, col + 1});
            }
        }
    }
}