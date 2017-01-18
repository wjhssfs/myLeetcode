// 302 Smallest Rectangle Enclosing Black Pixels

// An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

// For example, given the following image:

// [
//   "0010",
//   "0110",
//   "0100"
// ]
// and x = 0, y = 2,
// Return 6.

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(!image.size()) return 0;
        int right = 0, left = image[0].size()- 1, bottom = 0, top = image.size() - 1;
        for(int i = 0; i < (int)image.size(); i++){
            for(int j = 0; j < (int)image[0].size(); j++) {
                if(image[i][j] == '1') {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = max(bottom, i);
                }
            }
        }
        return (right - left+1) * (bottom - top+1);
    }
};

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
     	if (!image.size()) return 0;
		right = 0; left = image[0].size() - 1; bottom = 0; top = image.size() - 1;
		DFS(image, x, y);
		return (right - left + 1) * (bottom - top + 1);
	}

	void DFS(vector<vector<char>>&image, int i, int j){
		if (image[i][j] == '1'){
			image[i][j] = 'X';
			left = min(left, j);
			right = max(right, j);
			top = min(top, i);
			bottom = max(bottom, i);
			if (i > 0) DFS(image, i - 1, j);
			if (i < image.size() - 1) DFS(image, i + 1, j);
			if (j > 0) DFS(image, i, j - 1);
			if (j < image[0].size() - 1) DFS(image, i, j + 1);
		}
	}
private:
	int left, right, top, bottom;
};

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        swap(_image, image);
        _m = (int)_image.size();
        if(_m) _n = (int)_image[0].size();
        int left = binaryBoundary(0, y, true, false);
        int right = binaryBoundary(y, _n, false, false);
        int top = binaryBoundary(0, x, true, true);
        int bottom = binaryBoundary(x, _m, false, true);
        return (right - left) * (bottom - top);
    }
    
    int binaryBoundary(int i, int j, bool forLowBound, bool vertical){
        while(i < j){
            int mid = (i+j)/2, c = 0, cMax = vertical? _n : _m;
            for(; c < cMax; c++){
                if(vertical && _image[mid][c] == '1') break;
                if(!vertical && _image[c][mid] == '1') break;
            }
            if((c<cMax) == forLowBound) j = mid;
            else i = mid + 1;
        }
        return i;
    }
    vector<vector<char>> _image;
    int _m, _n;
};