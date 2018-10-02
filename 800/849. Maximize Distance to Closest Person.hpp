// 849. Maximize Distance to Closest Person
// In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

// There is at least one empty seat, and at least one person sitting.

// Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

// Return that maximum distance to closest person.

// Example 1:

// Input: [1,0,0,0,1,0,1]
// Output: 2
// Explanation: 
// If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
// If Alex sits in any other open seat, the closest person has distance 1.
// Thus, the maximum distance to the closest person is 2.
// Example 2:

// Input: [1,0,0,0]
// Output: 3
// Explanation: 
// If Alex sits in the last seat, the closest person is 3 seats away.
// This is the maximum distance possible, so the answer is 3.
// Note:

// 1 <= seats.length <= 20000
// seats contains only 0s or 1s, at least one 0, and at least one 1.

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int lastSeated = -1;
        int maxD = 0;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 0) continue;
            if (lastSeated == -1) {
                maxD = i;
            } else {
                maxD = max(maxD, (i - lastSeated) / 2);
            }
            lastSeated = i;
        }
        if (lastSeated != seats.size() - 1) maxD = max(maxD, (int)seats.size() - 1 - lastSeated);
        return maxD;
    }
};

int maxDistToClosest(vector<int> seats) {
        int res = 0, n = seats.size();
        for (int i = 0, zero = 0; i < n; ++i) if (seats[i] == 1) zero = 0; else res = max(res, (++zero + 1) / 2);
        for (int i = 0, zero = 0; seats[i] == 0; ++i) res = max(res, ++zero);
        for (int i = n - 1, zero = 0; seats[i] == 0; --i) res = max(res, ++zero);
        return res;
    }