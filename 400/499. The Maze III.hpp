// 499. The Maze III
// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls on to the hole.

// Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). Output the moving directions by using 'u', 'd', 'l' and 'r'. Since there could be several different shortest ways, you should output the lexicographically smallest way. If the ball cannot reach the hole, output "impossible".

// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.

// Example 1

// Input 1: a maze represented by a 2D array

// 0 0 0 0 0
// 1 1 0 0 1
// 0 0 0 0 0
// 0 1 0 0 1
// 0 1 0 0 0

// Input 2: ball coordinate (rowBall, colBall) = (4, 3)
// Input 3: hole coordinate (rowHole, colHole) = (0, 1)

// Output: "lul"
// Explanation: There are two shortest ways for the ball to drop into the hole.
// The first way is left -> up -> left, represented by "lul".
// The second way is up -> left, represented by 'ul'.
// Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".

// Example 2

// Input 1: a maze represented by a 2D array

// 0 0 0 0 0
// 1 1 0 0 1
// 0 0 0 0 0
// 0 1 0 0 1
// 0 1 0 0 0

// Input 2: ball coordinate (rowBall, colBall) = (4, 3)
// Input 3: hole coordinate (rowHole, colHole) = (3, 0)
// Output: "impossible"
// Explanation: The ball cannot reach the hole.

// Note:
// There is only one ball and one hole in the maze.
// Both the ball and hole exist on an empty space, and they will not be at the same position initially.
// The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// The maze contains at least 2 empty spaces, and the width and the height of the maze won't exceed 30.

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n= maze[0].size();
    	vector<vector<int>> dists(m, vector<int>(n, INT_MAX));

    	dists[ball[0]][ball[1]] = 0;
    	string finalPath = "impossible";
    	dfs(ball, hole, maze, dists, "", finalPath);
    	return finalPath;
    }
    
    void dfs(vector<int> const & curr, vector<int>& hole, vector<vector<int>>& maze, vector<vector<int>> &dists, string path, string &finalPath) {
		int x = curr[0], y = curr[1], dist = dists[x][y];
		if (dist >= dists[hole[0]][hole[1]]) return;

        vector<pair<int, int>> incr = { { 1,0 },{ 0,-1 },{ 0,1 },{ -1,0 } };
        string pathStep("dlru");
		for (int k = 0; k < 4; ++k)
		{
			int i = x, j = y, step = 0, d_i = incr[k].first, d_j = incr[k].second;
			while (i + d_i < dists.size() && i + d_i >= 0 && j + d_j >= 0 && j + d_j <dists[0].size() && maze[i + d_i][j + d_j] == 0)
			{
				++step;
				i += incr[k].first;
				j += incr[k].second;
				if (i == hole[0] && j == hole[1]) break;
			}
			if (dists[i][j] > dist + step) {
				dists[i][j] = dist + step;
				if (i == hole[0] && j == hole[1]) {
                    if (x < hole[0]) path += 'd';
    		        else if (x > hole[0]) path += 'u';
    		        else if (y < hole[1]) path += 'r';
    		        else path += 'l';
    		        finalPath = path;
    		        break;
		        }
				else dfs(vector<int>{i, j}, hole, maze, dists, path + pathStep[k], finalPath);
			}
		}
    }
};

class Solution {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    string directions[4]={"d","u","l","r"};
    struct cmp{
        bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
            return p1.second>p2.second;
        }
    };
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m=maze.size(),n=maze[0].size();
        vector<vector<int>> Dis(m,vector<int>(n,INT_MAX));
        vector<vector<string>> Way(m,vector<string>(n,""));
        Dis[ball[0]][ball[1]]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> PQu;    //first: pos, second dist
        PQu.push({ball[0]*n+ball[1],0});
        while(!PQu.empty()){
            auto start=PQu.top();
            PQu.pop();
            int x0=start.first/n,y0=start.first%n;
            if(start.second>Dis[x0][y0])continue;
            if(x0==hole[0]&&y0==hole[1])return Way[x0][y0];
            for(int t=0;t<4;t++){
                int xnew=x0,ynew=y0,move=0;
                string trys=Way[x0][y0]+directions[t];
                while(xnew+dx[t]>=0&&xnew+dx[t]<m&&ynew+dy[t]>=0&&ynew+dy[t]<n&&maze[xnew+dx[t]][ynew+dy[t]]==0){
                    xnew+=dx[t];
                    ynew+=dy[t];
                    move++;
                    if(xnew==hole[0]&&ynew==hole[1])break;
                }
                if(move==0)continue;
                if(Dis[x0][y0]+move<Dis[xnew][ynew]){
                    Dis[xnew][ynew]=Dis[x0][y0]+move;
                    Way[xnew][ynew]=trys;
                    PQu.push({xnew*n+ynew,Dis[xnew][ynew]});
                }else if(Dis[x0][y0]+move==Dis[xnew][ynew]){
                    if(trys<Way[xnew][ynew])Way[xnew][ynew]=trys;
                }
            }
        }
        return "impossible";
    }
};

class Solution {
public:
   string roll(vector<vector<int>>& maze, int rowBall, int colBall, const vector<int>& hole, 
    int d_row, int d_col, int steps, const string& path, pair<string, int>& res)
	{
	    if (steps < res.second) {
	        if (d_row != 0 || d_col != 0) { // both are zero for the initial ball position.
	            while ((rowBall + d_row) >= 0 && (colBall + d_col) >= 0 && (rowBall + d_row) <  maze.size() 
	                && (colBall + d_col) < maze[0].size() && maze[rowBall + d_row][colBall + d_col] != 1) 
	            {
	                rowBall += d_row;
	                colBall += d_col;
	                ++steps;
	                if (rowBall == hole[0] && colBall == hole[1] && steps < res.second) res = {path, steps};
	            }
	        }
	        if (maze[rowBall][colBall] == 0 || steps + 2 < maze[rowBall][colBall]) {
	            maze[rowBall][colBall] = steps + 2; // '1' is for the walls.
	            if (d_row == 0) roll(maze, rowBall, colBall, hole, 1, 0, steps, path + "d", res);
	            if (d_col == 0) roll(maze, rowBall, colBall, hole, 0, -1, steps, path + "l", res);
	            if (d_col == 0) roll(maze, rowBall, colBall, hole, 0, 1, steps, path + "r", res);
	            if (d_row == 0) roll(maze, rowBall, colBall, hole, -1, 0, steps, path + "u", res);
	        }
	    }
	    return res.first;
	}
	string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) 
	{
	    return roll(maze, ball[0], ball[1], hole, 0, 0, 0, "", pair<string, int>() = {"impossible", INT_MAX});
	}
};