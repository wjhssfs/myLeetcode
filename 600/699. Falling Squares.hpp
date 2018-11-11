// 699. Falling Squares
// On an infinite number line (x-axis), we drop given squares in the order they are given.

// The i-th square dropped (positions[i] = (left, side_length)) is a square with the left-most point being positions[i][0] and sidelength positions[i][1].

// The square is dropped with the bottom edge parallel to the number line, and from a higher height than all currently landed squares. We wait for each square to stick before dropping the next.

// The squares are infinitely sticky on their bottom edge, and will remain fixed to any positive length surface they touch (either the number line or another square). Squares dropped adjacent to each other will not stick together prematurely.


// Return a list ans of heights. Each height ans[i] represents the current highest height of any square we have dropped, after dropping squares represented by positions[0], positions[1], ..., positions[i].

// Example 1:
// Input: [[1, 2], [2, 3], [6, 1]]
// Output: [2, 5, 5]
// Explanation:

// After the first drop of positions[0] = [1, 2]:
// _aa
// _aa
// -------
// The maximum height of any square is 2.


// After the second drop of positions[1] = [2, 3]:
// __aaa
// __aaa
// __aaa
// _aa__
// _aa__
// --------------
// The maximum height of any square is 5.  
// The larger square stays on top of the smaller square despite where its center
// of gravity is, because squares are infinitely sticky on their bottom edge.


// After the third drop of positions[1] = [6, 1]:
// __aaa
// __aaa
// __aaa
// _aa
// _aa___a
// --------------
// The maximum height of any square is still 5.

// Thus, we return an answer of [2, 5, 5].


// Example 2:
// Input: [[100, 100], [200, 100]]
// Output: [100, 100]
// Explanation: Adjacent squares don't get stuck prematurely - only their bottom edge can stick to surfaces.
// Note:

// 1 <= positions.length <= 1000.
// 1 <= positions[i][0] <= 10^8.
// 1 <= positions[i][1] <= 10^6.

class Solution {
public:
	vector<int> fallingSquares(vector<pair<int, int>>& positions) {
		vector<int> res;
		for (int i = 0; i < positions.size(); ++i) {
			int h = positions[i].second;
			for (int j = 0; j < i; ++j) {
				if (!(positions[i].first >= positions[j].first + positions[j].second ||
					positions[i].first + positions[i].second <= positions[j].first)) {
					h = max(h, res[j] + positions[i].second);
				}
			}
			res.push_back(h);
		}

        for (int i = 1; i < res.size(); ++i) res[i] = max(res[i], res[i - 1]);
		return res;
	}
};

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        int n = positions.size();
        set<int> poses;
        for (int i = 0; i < n; i++) {
            poses.insert(positions[i].first);
            poses.insert(positions[i].first + positions[i].second - 1);
        }
        vector<int> vec_pos = vector<int>(poses.begin(), poses.end());
        map<int, int> map_pos;
        for (int i = 0; i < vec_pos.size(); i++) {
            map_pos[vec_pos[i]] = i;
        }
        vector<int> heights(3000);
        vector<int> res;
        int now = 0;
        for (int i = 0; i < n; i++) {
            int l = map_pos.at(positions[i].first), r = map_pos.at(positions[i].first + positions[i].second - 1);
            int max_height = 0;
            for (int j = l; j <= r; j++) {
                max_height = max(max_height, heights[j]);
            }
            now = max(max_height + positions[i].second, now);
            res.push_back(now);
            for (int j = l; j <= r; j++) {
                heights[j] = max_height + positions[i].second;
            }
        }
        return res;
    }
};

// pos tracks the x-coordinate of start points.
// height tracks the y-coordinate of lines.
def fallingSquares(self, positions):
        height = [0]
        pos = [0]
        res = []
        max_h = 0
        for left, side in positions:
            i = bisect.bisect_right(pos, left)
            j = bisect.bisect_left(pos, left + side)
            high = max(height[i - 1:j] or [0]) + side
            pos[i:j] = [left, left + side]
            height[i:j] = [high, height[j - 1]]
            max_h = max(max_h, high)
            res.append(max_h)
        return res