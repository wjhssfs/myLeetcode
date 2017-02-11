// 356. Line Reflection
// Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

// Example 1:
// Given points = [[1,1],[-1,1]], return true.

// Example 2:
// Given points = [[1,1],[-1,-1]], return false.

// Follow up:
// Could you do better than O(n2)?

// Hint:

// Find the smallest and largest x-value for all points.
// If there is a line then it should be at y = (minX + maxX) / 2.
// For each point, make sure that it has a reflected point in the opposite side.

namespace std {
    template<>
    struct hash<pair<int, int>> {
        inline size_t operator () (pair<int, int> const & p) const {
            hash<int> intHash;
            return intHash(p.first) ^ intHash(p.second);
        }
    };
}
class Solution {
public:
	bool isReflected(vector<pair<int, int>>& points) {
	    if (points.empty()) return true;
		int left = INT_MAX, right = INT_MIN;
		unordered_set<pair<int, int>> m;
		for (auto && point : points) {
			left = min(left, point.first);
			right = max(right, point.first);
			m.insert(point);
		}
		if (left == right) return true;
		
		int middle2 = right + left;
		for (auto && point : points) {
			auto rPoint = make_pair(middle2 - point.first, point.second);
			if (!m.count(rPoint)) return false;
		}
		return true;
	}
};
