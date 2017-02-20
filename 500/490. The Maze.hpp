// 490. The Maze
// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

// Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

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

// Output: true
// Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

// Example 2

// Input 1: a maze represented by a 2D array

// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0

// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (3, 2)

// Output: false
// Explanation: There is no way for the ball to stop at the destination.

// Note:
// There is only one ball and one destination in the maze.
// Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
// The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

class Solution {
public:
	bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		vector<vector<vector<int>>> boundaries(maze.size(), vector<vector<int>>(maze[0].size(), vector<int>(4)));
		for (int i = 0; i < maze.size(); ++i) {
			for (int j = 0; j < maze[0].size(); ++j) {
				boundaries[i][j][0] = maze[i][j] ? j + 1 : (!j ? 0 : boundaries[i][j - 1][0]); // left
				boundaries[i][j][1] = maze[i][j] ? i + 1: (!i ? 0 : boundaries[i - 1][j][1]); // up
			}
		}
		for (int i = maze.size() - 1; i >= 0; --i) {
			for (int j = maze[0].size() - 1; j >= 0; --j) {
				boundaries[i][j][2] = maze[i][j] ? j - 1 : (j < maze[0].size() - 1 ? boundaries[i][j + 1][2] : maze[0].size() - 1); // right
				boundaries[i][j][3] = maze[i][j] ? i - 1 : (i < maze.size() - 1 ? boundaries[i + 1][j][3] : maze.size() - 1); // down
			}
		}
		return dfs(boundaries, start, destination);
	}
private:
	bool dfs(vector<vector<vector<int>>> &boundaries, vector<int>& start, vector<int>& destination) {
		if (visited.count(getKey(start)) > 0) return false;
		visited.emplace(getKey(start));
		if (start == destination) return true;
		auto& bounds = boundaries[start[0]][start[1]];
		vector<int> left{ start[0], bounds[0] };
		if (dfs(boundaries, left, destination)) return true;
		vector<int> up{ bounds[1], start[1] };
		if (dfs(boundaries, up, destination)) return true;
		vector<int> right{ start[0], bounds[2] };
		if (dfs(boundaries, right, destination)) return true;
		vector<int> down{ bounds[3], start[1] };
		if (dfs(boundaries, down, destination)) return true;
		return false;
	}

	unordered_set<string> visited;

	inline string getKey(vector<int> &pos) {
		return to_string(pos[0]) + "|" + to_string(pos[1]);
	}
};

class Solution {
public:
	bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
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

		queue<vector<int>> q;
		q.emplace(start);
		while (!q.empty()) {
			start = q.front(); q.pop();
			if (visited.count(getKey(start))) continue;
			visited.emplace(getKey(start));
			if (start == destination) return true;
			auto& bounds = boundaries[start[0]][start[1]];
			q.push({start[0], bounds[0] });
			q.push({ bounds[1], start[1] });
			q.push({ start[0], bounds[2] });
			q.push({ bounds[3], start[1] });
		}
		return false;
	}
private:
	unordered_set<string> visited;

	inline string getKey(vector<int> &pos) {
		return to_string(pos[0]) + "|" + to_string(pos[1]);
	}
};

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        set<vector<int>> visited;
        return helper(maze, start, destination, visited);
    }
    bool helper(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, set<vector<int>>& visited) {
        if(start == destination) return true;
        if(visited.find(start) != visited.end()) return false;
        visited.insert(start);
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < 4; i++) {
            vector<int> res = go2End(maze, start, dirs[i]);
            if(res == destination || helper(maze, res, destination, visited)) return true;
        }
        return false;
    }
    vector<int> go2End(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir) {
        int i = start[0] + dir[0];
        int j = start[1] + dir[1];
        int m = maze.size();
        int n = maze[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || maze[i][j] == 1) {
            return start;
        }
        vector<int> newStart = {i, j};
        return go2End(maze, newStart, dir);
    }
};

public class Solution {
    class Point {
        int x,y;
        public Point(int _x, int _y) {x=_x;y=_y;}
    }
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        int m=maze.length, n=maze[0].length;
        if (start[0]==destination[0] && start[1]==destination[1]) return true;
        int[][] dir=new int[][] {{-1,0},{0,1},{1,0},{0,-1}};
        boolean[][] visited=new boolean[m][n];
        LinkedList<Point> list=new LinkedList<>();
        visited[start[0]][start[1]]=true;
        list.offer(new Point(start[0], start[1]));
        while (!list.isEmpty()) {
            Point p=list.poll();
            int x=p.x, y=p.y;
            for (int i=0;i<4;i++) {
                int xx=x, yy=y;
                while (xx>=0 && xx<m && yy>=0 && yy<n && maze[xx][yy]==0) {
                    xx+=dir[i][0];
                    yy+=dir[i][1];
                }
                xx-=dir[i][0];
                yy-=dir[i][1];
                if (visited[xx][yy]) continue;
                visited[xx][yy]=true;
                if (xx==destination[0] && yy==destination[1]) return true;
                list.offer(new Point(xx, yy));
            }
        }
        return false;
        
    }
}