// 850. Rectangle Area II

// We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1, y1, x2, y2] , where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the ith rectangle.

// Find the total area covered by all rectangles in the plane.  Since the answer may be too large, return it modulo 10^9 + 7.



// Example 1:

// Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
// Output: 6
// Explanation: As illustrated in the picture.
// Example 2:

// Input: [[0,0,1000000000,1000000000]]
// Output: 49
// Explanation: The answer is 10^18 modulo (10^9 + 7), which is (10^9)^2 = (-7)^2 = 49.
// Note:

// 1 <= rectangles.length <= 200
// rectanges[i].length = 4
// 0 <= rectangles[i][j] <= 10^9
// The total area covered by all rectangles will never exceed 2^63 - 1 and thus will fit in a 64-bit signed integer.


// https://leetcode.com/problems/rectangle-area-ii/discuss/138206/C++-10-lines-normalized-canvas
class Solution {
public:
  int rectangleArea(vector<vector<int>>& rectangles, int res = 0) {
    set<int> sx, sy;
    for (auto v : rectangles) sx.insert(v[0]), sy.insert(v[1]), sx.insert(v[2]), sy.insert(v[3]);
    vector<int> x(begin(sx), end(sx)), y(begin(sy), end(sy));
    vector<vector<int>> m(x.size(), vector<int>(y.size(), 0));

    for (auto v : rectangles) {
      for (auto i = lower_bound(begin(x), end(x), v[0]); *i != v[2]; ++i)
        for (auto j = lower_bound(begin(y), end(y), v[1]); *j != v[3]; ++j)
          // min retangle starts at i,j to next(i)next(j)
          if (m[i - begin(x)][j - begin(y)]++ == 0)
            res = (res + ((long long)*next(i) - *i) * (*next(j) - *j)) % 1000000007;
    }
    return res;
  }
};

// https://leetcode.com/problems/rectangle-area-ii/discuss/137914/C++Python-Discretization-and-O(NlogN)
   int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1000000000 + 7;
        vector<int> x = {0};
        for (auto r : rectangles) {
            x.push_back(r[0]);
            x.push_back(r[2]);
        }
        sort(x.begin(), x.end());
        vector<int>::iterator end_unique = unique(x.begin(), x.end());
        x.erase(end_unique, x.end());
        unordered_map<int, int> x_i;
        for (int i = 0; i < x.size(); ++i) {
            x_i[x[i]] = i;
        }
        vector<int> count(x.size(), 0);
        vector<vector<int>> L;
        for (auto r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            L.push_back({y1, x1, x2, 1});
            L.push_back({y2, x1, x2, -1});
        }
        sort(L.begin(), L.end());
        long long cur_y = 0, cur_x_sum = 0, area = 0;
        for (auto l : L) {
            long long  y = l[0], x1 = l[1], x2 = l[2], sig = l[3];
            area = (area + (y - cur_y) * cur_x_sum) % mod;
            cur_y = y;
            for (int i = x_i[x1]; i < x_i[x2]; i++)
                count[i] += sig;
            cur_x_sum = 0;
            for (int i = 0; i < x.size(); ++i) {
                if (count[i] > 0)
                    cur_x_sum += x[i + 1] - x[i];
            }
        }
        return area;
    }