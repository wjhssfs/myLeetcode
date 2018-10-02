// 335. Self Crossing

// You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

// Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

// Example 1:
// Given x = [2, 1, 1, 2],
// ┌───┐
// │   │
// └───┼──>
//     │

// Return true (self crossing)
// Example 2:
// Given x = [1, 2, 3, 4],
// ┌──────┐
// │      │
// │
// │
// └────────────>

// Return false (not self crossing)
// Example 3:
// Given x = [1, 1, 1, 1],
// ┌───┐
// │   │
// └───┼>

// Return true (self crossing)

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if(x.size() <= 3) return false;
        if(x.size() == 4)
            return x[3] >= x[1] && x[2] <= x[0]; // 4th line crosses first line
        if(x.size() == 5)
            return x[4] + x[0] == x[2] && x[3] == x[1]; // 5th line cross first line.
        for (int i = 5; i < (int)x.size(); i++) {
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) // last line crosses 4th last line
                return true;
            // last line crosses 6th last line
            if (x[i - 1] <= x[i - 3] &&  
                x[i] + x[i - 4] >= x[i - 2] &&
                x[i - 2] >= x[i - 4] &&
                x[i - 1] + x[i - 5] >= x[i - 3]) 
                return true;
        }
        return false;
    }
};


// Categorize the self-crossing scenarios, there are 3 of them: 
// 1. Fourth line crosses first line and works for fifth line crosses second line and so on...
// 2. Fifth line meets first line and works for the lines after
// 3. Sixth line crosses first line and works for the lines after
public class Solution {
    public boolean isSelfCrossing(int[] x) {
        int l = x.length;
        if(l <= 3) return false;

        for(int i = 3; i < l; i++){
            if(x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;  //Fourth line crosses first line and onward
            if(i >=4)
            {
                if(x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) return true; // Fifth line meets first line and onward
            }
            if(i >=5)
            {
                if(x[i-2] - x[i-4] >= 0 && x[i] >= x[i-2] - x[i-4] && x[i-1] >= x[i-3] - x[i-5] && x[i-1] <= x[i-3]) return true;  // Sixth line crosses first line and onward
            }
        }
        return false;
    }
}