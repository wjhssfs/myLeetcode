// 835. Image Overlap

// Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

// We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

// (Note also that a translation does not include any kind of rotation.)

// What is the largest possible overlap?

// Example 1:

// Input: A = [[1,1,0],
//             [0,1,0],
//             [0,1,0]]
//        B = [[0,0,0],
//             [0,1,1],
//             [0,0,1]]
// Output: 3
// Explanation: We slide A to right by 1 unit and down by 1 unit.
// Notes: 

// 1 <= A.length = A[0].length = B.length = B[0].length <= 30
// 0 <= A[i][j], B[i][j] <= 1

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int maxO = 0;
        if (A.empty() || A[0].empty() || B.empty() || B[0].empty()) return 0;
        for (int iOff = -(A.size() - 1); iOff < (int)B.size(); ++iOff) {
            for (int jOff = -(A[0].size() - 1); jOff < (int) B[0].size(); ++jOff) {
                int cur = 0;
                for (int i = 0; i < A.size(); ++i) {
                    for (int j = 0; j < A[0].size(); ++j) {
                        int curI = i + iOff;
                        int curJ = j + jOff;
                        if (curI < 0 || curJ < 0 || curI >= B.size() || curJ >= B[0].size()) continue;
                        if (A[i][j] == 1 && B[curI][curJ] == 1) cur++;
                    }
                }
                maxO = max(maxO, cur);
            }
        }
        return maxO;
    }
};

// O(AB) https://leetcode.com/problems/image-overlap/discuss/130623/C++JavaPython-Straight-Forward
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> LA, LB;
        int N = A.size();
        unordered_map<int, int> count;
        // 100 is big enough, For example, If slide 13 rows and 19 cols, it will be 1319.
        // can't be number like 30 For example: 409 = 13 * 30 + 19 = 14 * 30 - 11.
        // 409 can be taken as sliding "14 rows and -11 cols" or "13 rows and 19 cols" at the same time.
        for (int i = 0; i < N * N; ++i) if (A[i / N][i % N] == 1) LA.push_back(i / N * 100 + i % N);
        for (int i = 0; i < N * N; ++i) if (B[i / N][i % N] == 1) LB.push_back(i / N * 100 + i % N);
        // If we slide to make A[i] orverlap B[j], we can get 1 point.
        for (int i: LA) for (int j: LB) count[i - j]++;
        int res = 0;
        for (auto it: count) res = max(res, it.second);
        return res;
    }