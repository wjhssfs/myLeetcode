// 447. Number of Boomerangs
// Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
// Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
// Example:
// Input:
// [[0,0],[1,0],[2,0]]
// Output:
// 2
// Explanation:
// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int sz = points.size();
		int total = 0;
		for (int i = 0; i < sz; ++i) {
			unordered_map<int, int> m;
			for (int j = 0; j < sz; ++j) {
				if (i == j) continue;
				int d = (points[i].first - points[j].first) * (points[i].first - points[j].first) +
					(points[i].second - points[j].second) * (points[i].second - points[j].second);
				++m[d];
			}
			for (auto && r : m) {
				if (r.second >= 2) {
					total += r.second * (r.second - 1);
				}
			}
		}
		
		return total;
	}
};

class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int sz = points.size(), total = 0;
		vector<vector<int>> dp(sz, vector<int>(sz));
		for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < i; ++j) {
				dp[i][j] = (points[i].first - points[j].first) * (points[i].first - points[j].first) +
					(points[i].second - points[j].second) * (points[i].second - points[j].second);
			}
		}
		unordered_map<int, int> m;
		for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < sz; ++j) {
				if (i == j) continue;
				i > j ? ++m[dp[i][j]] : ++m[dp[j][i]];
			}
			for (auto && r : m) {
				if (r.second < 2) continue;
				total += r.second * (r.second - 1);
			}
			m.clear();
		}
		return total;
	}
};