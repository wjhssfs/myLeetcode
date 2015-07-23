// 218 The Skyline Problem

// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

//  Buildings  Skyline Contour
// The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

// For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

// The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

// For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

// Notes:

// The number of buildings in any input list is guaranteed to be in the range [0, 10000].
// The input list is already sorted in ascending order by the left x position Li.
// The output list must be sorted by the x position.
// There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]


class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> res;
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> rightPq;
		map<int, int> m;  // This is actually not needed, see solution 3
		int curX = -1;
		size_t i = 0;
		while (i != buildings.size() || !rightPq.empty()){
			if (rightPq.empty() || (i != buildings.size() && buildings[i][0] <= rightPq.top().first))
			{
				int curBuildingLeft = buildings[i][0];
				int curBuildingRight = buildings[i][1];;
				int curBuildingHeight = buildings[i][2];
				int curY = m.empty()? 0 : m.rbegin()->first;
				if (curX != -1 && curBuildingLeft > curX && (!res.size() ||
					curY != res.rbegin()->second)){ // This clause make sure we merge Xs of same height
					res.push_back(make_pair(curX, curY));
				}
				m[curBuildingHeight]++; 
				curX = curBuildingLeft;
				rightPq.push(make_pair(curBuildingRight, curBuildingHeight));
				i++;
			}
			else{
				int curY = m.rbegin()->first;
				if (curX != -1 && rightPq.top().first > curX && (!res.size() || curY != res.rbegin()->second)){
					res.push_back(make_pair(curX, curY));
				}
				m[rightPq.top().second]--;
				if (!m[rightPq.top().second]) m.erase(rightPq.top().second); // make sure the height is removed.
				curX = rightPq.top().first;
				rightPq.pop();
			}
		}

		if (curX != -1) res.push_back(make_pair(curX, 0));
		return res;
	}
};

// https://leetcode.com/discuss/37630/my-c-code-using-one-priority-queue-812-ms
struct Solution {
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        int cur=0, cur_X, cur_H, len = buildings.size();
        priority_queue<pair<int, int>> liveBlg;
        while(cur<len || !liveBlg.empty()) {
            if (liveBlg.empty() || cur<len && buildings[cur][0] <= liveBlg.top().second) {
                cur_X = buildings[cur][0];
                while(cur<len && buildings[cur][0] == cur_X) {
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            } else {
                cur_X = liveBlg.top().second;
                while (liveBlg.size() && liveBlg.top().second <= cur_X)
                    liveBlg.pop();
            }
            cur_H = liveBlg.empty() ? 0 : liveBlg.top().first;
            if (res.empty() || (res.back().second != cur_H))
                res.push_back(make_pair(cur_X, cur_H));
        }
        return res;
    }
};