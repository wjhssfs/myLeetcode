// 149 Max Points on a Line 
// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
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

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() < 3) return points.size();
        int result=0;
        for(int i=0; i<points.size(); i++) {
            map<pair<int, int>, int> lines;
            int localmax=0, overlap=0, vertical=0;
            for(int j=i+1; j<points.size(); j++) {
                if(points[j].x==points[i].x && points[j].y==points[i].y) {
                    overlap++;
                    continue;
                }
                else if(points[j].x==points[i].x) vertical++;
                else {
                    int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
                    int gcd=GCD(a, b);
                    a/=gcd;
                    b/=gcd;
                    lines[make_pair(a, b)]++;
                    localmax=max(lines[make_pair(a, b)], localmax);
                }
                localmax=max(vertical, localmax);
            }
            result=max(result, localmax+overlap+1);
        }

        return result;
    }

private:
    int GCD(int a, int b) {
        if(b==0) return a;
        else return GCD(b, a%b);
    }
};