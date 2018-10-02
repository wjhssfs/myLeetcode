// 573. Squirrel Simulation
// There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.

// Example 1:
// Input: 
// Height : 5
// Width : 7
// Tree position : [2,2]
// Squirrel : [4,4]
// Nuts : [[3,0], [2,5]]
// Output: 12
// Explanation:

// Note:
// All given positions won't overlap.
// The squirrel can take at most one nut at one time.
// The given positions of nuts have no order.
// Height and width are positive integers. 3 <= height * width <= 10,000.
// The given positions contain at least one nut, only one tree and one squirrel.

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int totalD = 0, maxSave = INT_MIN;
        for (auto && nut : nuts) {
            int d = abs(nut[0] - tree[0]) + abs(nut[1] - tree[1]);
            totalD += d * 2;
            int squirrelToNut = abs(squirrel[0] - nut[0]) + abs(squirrel[1] - nut[1]);
            maxSave = max(maxSave, d - squirrelToNut);
        }
        return totalD - maxSave;
    }
};