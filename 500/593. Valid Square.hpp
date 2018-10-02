// 593. Valid Square
// Given the coordinates of four points in 2D space, return whether the four points could construct a square.

// The coordinate (x,y) of a point is represented by an integer array with two integers.

// Example:
// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
// Output: True
// Note:

// All the input integers are in the range [-10000, 10000].
// A valid square has four equal sides with positive length and four equal angles (90-degree angles).
// Input points have no order.

class Solution {
    int d2 (vector<int>& p1, vector<int>& p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int> m;
        m[d2(p1, p2)]++;
        m[d2(p1, p3)]++;
        m[d2(p1, p4)]++;
        m[d2(p2, p3)]++;
        m[d2(p2, p4)]++;
        m[d2(p3, p4)]++;
        return m.size() == 2 && m.begin()->second == 4 && (++m.begin()) ->second == 2 && m.begin()->first * 2 == (++m.begin()) ->first;
    }
};


int d(vector<int>& p1, vector<int>& p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}
// correct based on not possible to have lattice (interger) points forming a equilateral triangle.
// https://math.stackexchange.com/questions/105330/equilateral-triangle-whose-vertices-are-lattice-points
// otherwise would need to check 4 equal distances should be smaller than 2 equal distances.
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    unordered_set<int> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
    return !s.count(0) && s.size() == 2;
}