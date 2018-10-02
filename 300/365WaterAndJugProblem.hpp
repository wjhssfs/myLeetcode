// 365. Water and Jug Problem
// You are given two jugs with capacities x and y litres. There is an infinite amount of water supply
// available. You need to determine whether it is possible to measure exactly z litres using these two jugs.
// If z liters of water is measurable, you must have z liters of water contained within one or
// both buckets by the end.
// Operations allowed:
// Fill any of the jugs completely with water.
// Empty any of the jugs.
// Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
// Example 1: (From the famous "Die Hard" example)
// Input: x = 3, y = 5, z = 4
// Output: True
// Example 2:
// Input: x = 2, y = 6, z = 5
// Output: False


// https://discuss.leetcode.com/topic/49238/math-solution-java-solution/2
public boolean canMeasureWater(int x, int y, int z) {
    //limit brought by the statement that water is finallly in one or both buckets
    if(x + y < z) return false;
    //case x or y is zero
    if( x == z || y == z || x + y == z ) return true;
    
    //get GCD, then we can use the property of Bézout's identity
    return z%GCD(x, y) == 0;
}

public int GCD(int a, int b){
    while(b != 0 ){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

// https://discuss.leetcode.com/topic/49751/clear-explanation-of-why-using-gcd
// Bezout's identity: We can always find a and b to satisfy ax + bx = d where d = gcd(x, y)
// the greatest common divisor d is the smallest positive integer that can be written as ax + by
// every integer of the form ax + by is a multiple of the greatest common divisor d.

// https://discuss.leetcode.com/topic/50477/no-tricky-maths-no-gcd-o-1-space-c-solution-with-explanation
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x > y) swap(x, y);
        if (x == z || y == z || x + y == z) return true;   //specific cases
        int currX = x;   //current water amount in smaller jug
        int currY = x;   //current water amount in larger jug
        if (x != 0 && y != 0) {
            while (1) {
                if (currY == z || currX + currY == z) return true;
                if (y - currY == currX) break;
                else if (y - currY > currX) {
                    currY = currY + currX;
                    currX = x;
                }
                else {
                    currX = currX - (y - currY);
                    currY = 0;
                }
            }
        }
        return false;
    }
};

namespace std {
template <> struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);
    }
};

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        queue<pair<int, int>> sq;
        unordered_set<pair<int, int>> m;
        sq.push(make_pair(0, 0));
        while (!sq.empty()) {
            auto cur = sq.front(); sq.pop();
            int cx = cur.first, cy = cur.second;
            if (cx + cy == z) return true;
            if (m.count(cur)) continue;
            m.insert(cur);
            if (cx > 0) sq.push(make_pair(0, cy));
            if (cy > 0) sq.push(make_pair(cx, 0));
            if (cx != x) sq.push(make_pair(x, cy));
            if (cy != y) sq.push(make_pair(cx, y));
            if (cx + cy < x) sq.push(make_pair(cx + cy, 0));
            if (cx + cy < y) sq.push(make_pair(0, cx + cy));
            if (cy + (x - cx) < y) sq.push(make_pair(x, cy + (x - cx)));
            if (cx + (y - cy) < x) sq.push(make_pair(cx + (y - cy), x));
        }
        return false;
    }
};