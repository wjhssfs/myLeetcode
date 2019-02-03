// 963. Minimum Area Rectangle II
// Given a set of points in the xy-plane, determine the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the x and y axes.

// If there isn't any rectangle, return 0.

 

// Example 1:



// Input: [[1,2],[2,1],[1,0],[0,1]]
// Output: 2.00000
// Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
// Example 2:



// Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
// Output: 1.00000
// Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
// Example 3:



// Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
// Output: 0
// Explanation: There is no possible rectangle to form from these points.
// Example 4:



// Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
// Output: 2.00000
// Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.
 

// Note:

// 1 <= points.length <= 50
// 0 <= points[i][0] <= 40000
// 0 <= points[i][1] <= 40000
// All points are distinct.
// Answers within 10^-5 of the actual value will be accepted as correct.

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<string, vector<pair<int, int>>> m;
        double res = 1e10;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int d = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                int cx = points[i][0] + points[j][0];
                int cy = points[i][1] + points[j][1];
                string key = to_string(d) + "|" + to_string(cx) + "|" + to_string(cy);
                if (m.count(key)) {
                    for (auto&& p : m[key]) {
                        double l1 = sqrt((points[p.first][0] - points[i][0]) * (points[p.first][0] - points[i][0]) + (points[p.first][1] - points[i][1]) * (points[p.first][1] - points[i][1]));
                        double l2 = sqrt((points[p.first][0] - points[j][0]) * (points[p.first][0] - points[j][0]) + (points[p.first][1] - points[j][1]) * (points[p.first][1] - points[j][1]));
                        res = min(res, l1 * l2);
                    }
                }
                m[key].push_back(make_pair(i, j
            }
        }
        if (abs(res - 1e10) < 1e-5) return 0.0;
        else return res;
    }
};