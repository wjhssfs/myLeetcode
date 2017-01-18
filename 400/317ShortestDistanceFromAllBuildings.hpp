// 317. Shortest Distance from All Buildings

// You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

// Each 0 marks an empty land which you can pass by freely.
// Each 1 marks a building which you cannot pass through.
// Each 2 marks an obstacle which you cannot pass through.
// For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

// 1 - 0 - 2 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
// The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

// Note:
// There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

class Solution {
public:
	int shortestDistance(vector<vector<int>>& grid) {
		int m = grid.size();
		if (!m) return -1;
		int n = grid[0].size(), minDist = INT_MAX, nVisitedNeg = 0, nBuildings = 0;
		auto total = grid;
		vector<int> d({ 0, -1, 0, 1, 0 });
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 2) total[i][j] = INT_MAX;
				else if (grid[i][j] == 1) {
					++nBuildings;
					queue<pair<int, int>> q, qNext;
					q.emplace(i, j);
					int dist = 1;
					while (q.size()) {
						while (q.size()) {
							auto cur = q.front(); q.pop();
							int ci = cur.first, cj = cur.second;
							for (int k = 0; k < 4; k++) {
								int ni = ci + d[k];
								int nj = cj + d[k + 1];
								if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == nVisitedNeg) {
									qNext.emplace(ni, nj);
									total[ni][nj] += dist;
									--grid[ni][nj];
								}
							}
						}
						swap(q, qNext);
						++dist;
					}
					--nVisitedNeg;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == -nBuildings) {
					minDist = min(minDist, total[i][j]);
				}
			}
		}
		if (minDist == INT_MAX)
			return -1;
		return minDist;
	}
};