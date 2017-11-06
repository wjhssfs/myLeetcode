// 505. The Maze II

// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

// Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

// Example 1

// Input 1: a maze represented by a 2D array

// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0

// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (4, 4)

// Output: 12
// Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
//              The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

// Example 2

// Input 1: a maze represented by a 2D array

// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0

// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (3, 2)

// Output: -1
// Explanation: There is no way for the ball to stop at the destination.

// Note:
// There is only one ball and one destination in the maze.
// Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
// The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

class Solution {
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		vector<vector<vector<int>>> boundaries(maze.size(), vector<vector<int>>(maze[0].size(), vector<int>(4)));
		for (int i = 0; i < maze.size(); ++i) {
			for (int j = 0; j < maze[0].size(); ++j) {
				boundaries[i][j][0] = maze[i][j] ? j + 1 : (!j ? 0 : boundaries[i][j - 1][0]); // left
				boundaries[i][j][1] = maze[i][j] ? i + 1 : (!i ? 0 : boundaries[i - 1][j][1]); // up
			}
		}
		for (int i = maze.size() - 1; i >= 0; --i) {
			for (int j = maze[0].size() - 1; j >= 0; --j) {
				boundaries[i][j][2] = maze[i][j] ? j - 1 : (j < maze[0].size() - 1 ? boundaries[i][j + 1][2] : maze[0].size() - 1); // right
				boundaries[i][j][3] = maze[i][j] ? i - 1 : (i < maze.size() - 1 ? boundaries[i + 1][j][3] : maze.size() - 1); // down
			}
		}

		start.push_back(0);
		queue<vector<int>> q;
		q.emplace(start);
		int minD = INT_MAX;
		while (!q.empty()) {
			start = q.front(); q.pop();
			if (visited.count(getKey(start)) > 0 && visited[getKey(start)] <= start[2]) continue;
			visited[getKey(start)] = start[2];
			if (vector<int>{ start[0], start[1] } == destination) {
				minD = min(minD, start[2]);
			}
			auto& bounds = boundaries[start[0]][start[1]];
			q.push({ start[0], bounds[0], start[2] + abs(bounds[0] - start[1]) });
			q.push({ bounds[1], start[1], start[2] + abs(bounds[1] - start[0]) });
			q.push({ start[0], bounds[2], start[2] + abs(bounds[2] - start[1]) });
			q.push({ bounds[3], start[1], start[2] + abs(bounds[3] - start[0]) });
		}
		return minD == INT_MAX ? -1 : minD;
	}
private:
	unordered_map<string, int> visited;

	inline string getKey(vector<int> &pos) {
		return to_string(pos[0]) + "|" + to_string(pos[1]);
	}
};

public class Solution {
    class Point {
        int x,y,l;
        public Point(int _x, int _y, int _l) {x=_x;y=_y;l=_l;}
    }
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        int m=maze.length, n=maze[0].length;
        int[][] length=new int[m][n]; // record length
        for (int i=0;i<m*n;i++) length[i/n][i%n]=Integer.MAX_VALUE;
        int[][] dir=new int[][] {{-1,0},{0,1},{1,0},{0,-1}};
        PriorityQueue<Point> list=new PriorityQueue<>((o1,o2)->o1.l-o2.l); // using priority queue
        list.offer(new Point(start[0], start[1], 0));
        while (!list.isEmpty()) {
            Point p=list.poll();
            if (length[p.x][p.y]<=p.l) continue; // if we have already found a route shorter
            length[p.x][p.y]=p.l;
            for (int i=0;i<4;i++) {
                int xx=p.x, yy=p.y, l=p.l;
                while (xx>=0 && xx<m && yy>=0 && yy<n && maze[xx][yy]==0) {
                    xx+=dir[i][0];
                    yy+=dir[i][1];
                    l++;
                }
                xx-=dir[i][0];
                yy-=dir[i][1];
                l--;
                list.offer(new Point(xx, yy, l));
            }
        }
        return length[destination[0]][destination[1]]==Integer.MAX_VALUE?-1:length[destination[0]][destination[1]];
    }
}

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    	int m = maze.size(), n= maze[0].size();
    
    	vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
    	queue<pair<int, int>> q;
    
    	vector<pair<int, int>> incr = { { 1,0 },{ 0,-1 },{ 0,1 },{ -1,0 } };
    
    	q.push({ start[0], start[1] });
    	dists[start[0]][start[1]] = 0;
    
    	while (!q.empty())
    	{
    		auto curr = q.front();
    		q.pop();
    		int x = curr.first;
    		int y = curr.second;
    		int dist = dists[x][y];
    
    		for (int k = 0; k < 4; ++k)
    		{
    			int i = x;
    			int j = y;
    			int step = 0;
    			int d_i = incr[k].first;
    			int d_j = incr[k].second;
    
    			while (i + d_i < m && i + d_i >= 0 && j + d_j >= 0 && j + d_j <n && maze[i + d_i][j + d_j] == 0)
    			{
    				++step;
    				i += incr[k].first;
    				j += incr[k].second;
    				
    			}
    			if (dists[i][j] > dist + step) // not the first time, but generate smaller dist, process one more time
    			{
    				dists[i][j] = dist + step;
    				q.push({ i,j });
    			}
    		}
    	}
    
    	return dists[destination[0]][destination[1]] == INT_MAX ? -1 : dists[destination[0]][destination[1]];        
    }
};
