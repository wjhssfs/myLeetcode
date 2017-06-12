// 587. Erect the Fence

// There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

// Example 1:
// Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
// Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
// Explanation:

// Example 2:
// Input: [[1,2],[2,2],[4,2]]
// Output: [[1,2],[2,2],[4,2]]
// Explanation:

// Even you only have trees in a line, you need to use rope to enclose them. 
// Note:

// All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
// All input integers will range from 0 to 100.
// The garden has at least one tree.
// All coordinates are distinct.
// Input points have NO order. No order required for output.

// https://leetcode.com/articles/erect-the-fence/
class Solution {
public:
	vector<Point> outerTrees(vector<Point>& points) {
		vector<Point> result;

		int firstIndex = 0;
		for (int i = 1; i < points.size(); i++) {
			if (points[i].x < points[firstIndex].x ||
				(points[i].x == points[firstIndex].x && points[i].y < points[firstIndex].y)) {
				firstIndex = i;
			}
		}
		result.push_back(points[firstIndex]);
		int lastOnHullIndex = firstIndex;

		int curIndex = firstIndex;
		do {
			Point next = points[0];
			int nextIndex = 0;
			for (int i = 1; i < points.size(); i++) {
				if (i == curIndex) continue;
				int cross = crossProductLength(points[curIndex], points[i], next);
				if (nextIndex == curIndex || cross > 0 ||
					// Handle collinear points
					(cross == 0 && distance(points[i], points[curIndex]) > distance(next, points[curIndex]))) {
					next = points[i];
					nextIndex = i;
				}
			}
			// Handle collinear points
			for (int i = 0; i < points.size(); i++) {
				if (i == curIndex) continue;
				int cross = crossProductLength(points[curIndex], points[i], next);
				if (cross == 0 && i != firstIndex) {
					result.push_back(points[i]);
				}
			}
			if (result.size() == points.size()) break;
			curIndex = nextIndex;

		} while (curIndex != firstIndex);

		return result;
	}

	int crossProductLength(Point A, Point B, Point C) {
		// Get the vectors' coordinates.
		int BAx = A.x - B.x;
		int BAy = A.y - B.y;
		int BCx = C.x - B.x;
		int BCy = C.y - B.y;

		// Calculate the Z coordinate of the cross product.
		return (BAx * BCy - BAy * BCx);
	}

	int distance(Point p1, Point p2) {
		return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	}
};