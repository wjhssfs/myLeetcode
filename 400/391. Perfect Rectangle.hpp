// 391. Perfect Rectangle
// Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

// Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).


// Example 1:

// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [3,2,4,4],
//   [1,3,2,4],
//   [2,3,3,4]
// ]

// Return true. All 5 rectangles together form an exact cover of a rectangular region.

// Example 2:

// rectangles = [
//   [1,1,2,3],
//   [1,3,2,4],
//   [3,1,4,2],
//   [3,2,4,4]
// ]

// Return false. Because there is a gap between the two rectangular regions.

// Example 3:

// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [1,3,2,4],
//   [3,2,4,4]
// ]

// Return false. Because there is a gap in the top center.

// Example 4:

// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [1,3,2,4],
//   [2,2,4,4]
// ]

// Return false. Because two of the rectangles overlap with each other.

// https://discuss.leetcode.com/topic/56052/really-easy-understanding-solution-o-n-java
// the large rectangle area should be equal to the sum of small rectangles
// count of all the points should be even(this rule out small regtangle overlaps), and that of all the four corner points should be one

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> bigRec = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
        unordered_set<vector<int>> m;
        int totalArea = 0;
        for (auto && rec : rectangles) {
            bigRec[0] = min (bigRec[0], rec[0]);
            bigRec[1] = min (bigRec[1], rec[1]);
            bigRec[2] = max (bigRec[2], rec[2]);
            bigRec[3] = max (bigRec[3], rec[3]);
            vector<int> p1 = {rec[0], rec[1]}, p2 = {rec[2], rec[3]}, p3 = {rec[0], rec[3]}, p4 = {rec[2], rec[1]};
            m.count(p1) ? m.erase(p1) : m.insert(p1);
            m.count(p2) ? m.erase(p2) : m.insert(p2);
            m.count(p3) ? m.erase(p3) : m.insert(p3);
            m.count(p4) ? m.erase(p4) : m.insert(p4);
            totalArea = (rec[2] - rec[0]) * (rec[3] - rec[1]);
        }
        if (m.size() != 4 || 
            !m.count({bigRec[0], bigRec[1]}) || 
            !m.count({bigRec[2], bigRect[3]}) ||
            !m.count({bigRec[0], bigRect[3]}) ||
            !m.count({bigRec[2], bigRect[1]})) return false;
        return totalArea == (bigRec[2] - bigRec[0]) * (bigRec[3] - bigRec[1]);
    }
};