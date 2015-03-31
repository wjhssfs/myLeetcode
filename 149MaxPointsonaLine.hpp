// 149 Max Points on a Line 
// 
// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
// 
// Tags:{Hash, Table Math}

class Solution{
public:
	int maxPoints(vector<Point> &points) {
		int sz = points.size();
		if (sz < 3) return sz;
		int maxPs = 0;
		for (int i = 0; i < sz-1; i++){
			int nSamePoint = 1;
			unordered_map<double, int> slops;
			for (int j = i + 1; j < sz; j++){
				if (points[i].x == points[j].x && points[i].y == points[j].y){
					nSamePoint++;
				}
				else{
					double deltaY = points[j].y - points[i].y;
					double deltaX = points[j].x - points[i].x;
					// for double, 1.0/0.0 results in inf
					double slop = deltaX == 0? 1.0/deltaX:deltaY / deltaX;
					slops[slop]++;
				}
			}
			int maxpointsij = 0;
			for (auto &slop : slops){
				if (slop.second > maxpointsij){
					maxpointsij = slop.second;
				}
			}
			maxPs = max(maxPs, maxpointsij + nSamePoint);
		}
		return maxPs;
	}
};