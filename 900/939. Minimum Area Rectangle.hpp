// 939. Minimum Area Rectangle
// Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

// If there isn't any rectangle, return 0.

 

// Example 1:

// Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
// Output: 4
// Example 2:

// Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
// Output: 2
 

// Note:

// 1 <= points.length <= 500
// 0 <= points[i][0] <= 40000
// 0 <= points[i][1] <= 40000
// All points are distinct.

template <typename T>
inline void hash_combine(std::size_t & seed, const T & v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std {
    template<typename T>
    struct hash<vector<T>> {
        inline size_t operator () (const vector<T> &v) const{
            size_t seed = 0;
            for (auto && n : v) ::hash_combine(seed, n);
            return seed;
        };
    };
}

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<vector<int>> s(points.begin(), points.end());
        int res = INT_MAX;
        for (auto i = points.begin(); i != points.end(); ++i) {
            for (auto j = next(i); j != points.end(); ++j) {
                if ((*i)[0] == (*j)[0]) continue;
                if ((*i)[1] == (*j)[1]) continue;
                if (s.count({(*i)[0], (*j)[1]}) == 0) continue;
                if (s.count({(*j)[0], (*i)[1]}) == 0) continue;
                int curArea = abs(((*j)[0] - (*i)[0]) * ((*j)[1] - (*i)[1]));
                res = min(res, curArea);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};