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

template <typename T>
inline void hash_combine(std::size_t & seed, const T & v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std {
    template<typename T>
    struct hash<vector<T>> {
        inline size_t operator () z`(const vector<T> &v) const{
            size_t seed = 0;
            for (auto && n : v) ::hash_combine(seed, n);
            return seed;
        };
    };
}

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> bigRec = { INT_MAX, INT_MAX, INT_MIN, INT_MIN };
        unordered_set<vector<int>> m;
        int totalArea = 0;
        for (auto && rec : rectangles) {
            bigRec[0] = min(bigRec[0], rec[0]);
            bigRec[1] = min(bigRec[1], rec[1]);
            bigRec[2] = max(bigRec[2], rec[2]);
            bigRec[3] = max(bigRec[3], rec[3]);
            vector<int> p1 = { rec[0], rec[1] }, p2 = { rec[2], rec[3] }, p3 = { rec[0], rec[3] }, p4 = { rec[2], rec[1] };
            if (m.count(p1)) m.erase(p1);
            else m.emplace(p1);
            if (m.count(p2)) m.erase(p2);
            else m.emplace(p2);
            if (m.count(p3)) m.erase(p3);
            else m.emplace(p3);
            if (m.count(p4)) m.erase(p4);
            else m.emplace(p4);
            totalArea += (rec[2] - rec[0]) * (rec[3] - rec[1]);
        }
        if (m.size() != 4 ||
            !m.count({ bigRec[0], bigRec[1] }) ||
            !m.count({ bigRec[2], bigRec[3] }) ||
            !m.count({ bigRec[0], bigRec[3] }) ||
            !m.count({ bigRec[2], bigRec[1] })) return false;
        return totalArea == (bigRec[2] - bigRec[0]) * (bigRec[3] - bigRec[1]);
    }
};



inline string getKey(int v1, int v2) {
    return to_string(v1) + " " + to_string(v2);
}
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> bigRec = { INT_MAX, INT_MAX, INT_MIN, INT_MIN };
        unordered_set<string> m;
        int totalArea = 0;
        for (auto && rec : rectangles) {
            bigRec[0] = min(bigRec[0], rec[0]);
            bigRec[1] = min(bigRec[1], rec[1]);
            bigRec[2] = max(bigRec[2], rec[2]);
            bigRec[3] = max(bigRec[3], rec[3]);
            string p1 = getKey(rec[0], rec[1]), p2 = getKey(rec[2], rec[3]), p3 = getKey(rec[0], rec[3]), p4 = getKey(rec[2], rec[1]);
            if (m.count(p1)) m.erase(p1);
            else m.emplace(p1);
            if (m.count(p2)) m.erase(p2);
            else m.emplace(p2);
            if (m.count(p3)) m.erase(p3);
            else m.emplace(p3);
            if (m.count(p4)) m.erase(p4);
            else m.emplace(p4);
            totalArea += (rec[2] - rec[0]) * (rec[3] - rec[1]);
        }
        if (m.size() != 4 ||
            !m.count(getKey(bigRec[0], bigRec[1])) ||
            !m.count(getKey(bigRec[2], bigRec[3])) ||
            !m.count(getKey(bigRec[0], bigRec[3])) ||
            !m.count(getKey(bigRec[2], bigRec[1]))) return false;
        return totalArea == (bigRec[2] - bigRec[0]) * (bigRec[3] - bigRec[1]);
    }
};
