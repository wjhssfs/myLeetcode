// 489. Robot Room Cleaner

// Given a robot cleaner in a room modeled as a grid.

// Each cell in the grid can be empty or blocked.

// The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.

// When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.

// Design an algorithm to clean the entire room using only the 4 given APIs shown below.

// interface Robot {
//   // returns true if next cell is open and robot moves into the cell.
//   // returns false if next cell is obstacle and robot stays on the current cell.
//   boolean move();

//   // Robot will stay on the same cell after calling turnLeft/turnRight.
//   // Each turn will be 90 degrees.
//   void turnLeft();
//   void turnRight();

//   // Clean the current cell.
//   void clean();
// }
// Example:

// Input:
// room = [
//   [1,1,1,1,1,0,1,1],
//   [1,1,1,1,1,0,1,1],
//   [1,0,1,1,1,1,1,1],
//   [0,0,0,1,0,0,0,0],
//   [1,1,1,1,1,1,1,1]
// ],
// row = 1,
// col = 3

// Explanation:
// All grids in the room are marked by either 0 or 1.
// 0 means the cell is blocked, while 1 means the cell is accessible.
// The robot initially starts at the position of row=1, col=3.
// From the top left corner, its position is one row below and three columns right.
// Notes:

// The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded". In other words, you must control the robot using only the mentioned 4 APIs, without knowing the room layout and the initial robot's position.
// The robot's initial position will always be in an accessible cell.
// The initial direction of the robot will be facing up.
// All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.
// Assume all four edges of the grid are all surrounded by wall.

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
    void dfs(Robot& robot) {
        if (m.count(cur)) return;
        //cout << "clean:" << cur.first << " " << cur.second << " " << d << endl;
        m.insert(cur);
        robot.clean();
        tryMove(robot);
        tryLeft(robot);
        robot.turnLeft();
        d = (d + 1) % 4;
        tryLeft(robot);
        robot.turnLeft();
        d = (d + 1) % 4;
        tryLeft(robot);
        robot.turnLeft();
        robot.turnLeft();
        d = (d + 2) % 4;
        //cout << "exit:" << cur.first << " " << cur.second  << " " << d << endl;
    }
    void tryMove(Robot& robot) {
        auto t = cur;
        if (d == 0) {
            cur.first--;
        } else if (d == 1) {
            cur.second--;
        } else if (d == 2) {
            cur.first++;
        } else cur.second++;
        
        if (m.count(cur) ||!robot.move()) {
            cur = t;
            return;
        }
        dfs(robot);
        // Cancle the move
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
        cur = t;
    }
    void tryLeft(Robot& robot) {
        robot.turnLeft();
        d = (d + 1) % 4;
        //cout << "tryLeft:" << cur.first << " " << cur.second << " " << d << endl;
        tryMove(robot);
        robot.turnRight();
        d = (4 + d - 1) % 4;
    }
    set<pair<int, int>> m;
    pair<int, int> cur;
    int d;
public:
    void cleanRoom(Robot& robot) {
        cur = make_pair(0, 0);
        d = 0;
        dfs(robot);
    }
};


 public void cleanRoom(Robot robot) {
        // A number can be added to each visited cell
        // use string to identify the class
        Set<String> set = new HashSet<>();
        int cur_dir = 0;   // 0: up, 90: right, 180: down, 270: left
        backtrack(robot, set, 0, 0, 0);
    }

    public void backtrack(Robot robot, Set<String> set, int i, 
                int j, int cur_dir) {
        String tmp = i + "->" + j;
        if(set.contains(tmp)) {
            return;
        }
        
        robot.clean();
        set.add(tmp);

        for(int n = 0; n < 4; n++) {
        // the robot can to four directions, we use right turn
            if(robot.move()) {
                // can go directly. Find the (x, y) for the next cell based on current direction
                int x = i, y = j;
                switch(cur_dir) {
                    case 0:
                        // go up, reduce i
                        x = i-1;
                        break;
                    case 90:
                        // go right
                        y = j+1;
                        break;
                    case 180:
                        // go down
                        x = i+1;
                        break;
                    case 270:
                        // go left
                        y = j-1;
                        break;
                    default:
                        break;
                }

                backtrack(robot, set, x, y, cur_dir);
                       // go back to the starting position
            robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnRight();
                robot.turnRight();

            } 
            // turn to next direction
            robot.turnRight();
            cur_dir += 90;
            cur_dir %= 360;
        }

    }