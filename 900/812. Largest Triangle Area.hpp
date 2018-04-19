// 812. Largest Triangle Area
// You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

// Example:
// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2
// Explanation: 
// The five points are show in the figure below. The red triangle is the largest.


// Notes:

// 3 <= points.length <= 50.
// No points will be duplicated.
//  -50 <= points[i][j] <= 50.
// Answers within 10^-6 of the true value will be accepted as correct.

// https://leetcode.com/problems/largest-triangle-area/discuss/122711/C++JavaPython-Solution-with-Explanation-and-Prove
class Solution {
    double area(vector<int>& A, vector<int>& B, vector<int>& C) {
        return abs((A[0] * (B[1] - C[1]) + B[0] * (C[1] - A[1]) + C[0] * (A[1] - B[1]))) / 2.0;
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        for (size_t i = 0; i != points.size() - 2; ++i) {
            for (size_t j = i + 1; j != points.size() - 1; ++j) {
                for (size_t k = j + 1; k != points.size(); ++k) {
                    auto newArea = area(points[i], points[j], points[k]);
                    maxArea = max(maxArea, newArea);
                }
            }
        }
        return maxArea;
    }
};