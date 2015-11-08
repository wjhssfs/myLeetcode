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