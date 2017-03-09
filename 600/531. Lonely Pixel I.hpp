// 531. Lonely Pixel I

// Given a picture consisting of black and white pixels, find the number of black lonely pixels.

// The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

// A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

// Example:
// Input: 
// [['W', 'W', 'B'],
//  ['W', 'B', 'W'],
//  ['B', 'W', 'W']]

// Output: 3
// Explanation: All the three 'B's are black lonely pixels.
// Note:
// The range of width and height of the input 2D array is [1,500].

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.empty() || picture[0].empty()) return 0;
        vector<int> v(picture[0].size());
        unordered_set<int> m;
        for (int i = 0; i < picture.size(); ++i) {
            int nH = 0, iH = -1;
            for (int j = 0; j < picture[0].size(); ++j) {
                if (picture[i][j] == 'B') {
                    ++v[j];
                    if (v[j] > 1) m.erase(j);
                    ++nH;
                    iH = j;
                }
            }
            if (nH == 1 && v[iH] == 1) m.insert(iH);
        }
        return m.size();
    }
};