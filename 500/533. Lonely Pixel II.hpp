// 533. Lonely Pixel II

// Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

// Row R and column C both contain exactly N black pixels.
// For all rows that have a black pixel at column C, they should be exactly the same as row R
// The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

// Example:
// Input:                                            
// [['W', 'B', 'W', 'B', 'B', 'W'],    
//  ['W', 'B', 'W', 'B', 'B', 'W'],    
//  ['W', 'B', 'W', 'B', 'B', 'W'],    
//  ['W', 'W', 'B', 'W', 'B', 'W']] 

// N = 3
// Output: 6
// Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
//         0    1    2    3    4    5         column index                                            
// 0    [['W', 'B', 'W', 'B', 'B', 'W'],    
// 1     ['W', 'B', 'W', 'B', 'B', 'W'],    
// 2     ['W', 'B', 'W', 'B', 'B', 'W'],    
// 3     ['W', 'W', 'B', 'W', 'B', 'W']]    
// row index

// Take 'B' at row R = 0 and column C = 1 as an example:
// Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
// Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.

// Note:
// The range of width and height of the input 2D array is [1,200].

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty()) return 0;
        int rc = picture.size(), cc = picture[0].size(), res = 0;
        for (int i = 0; i < cc; ++i) {
            vector<int> bRs;
            for (int j = 0; j < rc; ++j) {
                if (picture[j][i] == 'B') bRs.push_back(j);
            }
            if (bRs.size() == N) {
                bool isValid = true;
                int n = 0;
                for (int k = 0; k < cc && isValid; ++k) {
                    if (picture[bRs[0]][k] == 'B') ++n;
                    for (int l = 1; l < N && isValid; ++l) {
                        if (picture[bRs[l]][k] != picture[bRs[0]][k]) {
                            isValid = false;
                        }
                    }
                }
                if (isValid && n == N) res += N;
            }
        }
        return res;
    }
};

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty()) return 0;
        int rc = picture.size(), cc = picture[0].size(), res = 0;
        unordered_map<string, int> m;
        vector<int> countC(cc), countR(rc);
        vector<string> srows;
        for (int i = 0; i < rc; ++i){
            string s(picture[i].begin(), picture[i].end());
            ++m[s];
            for (int j = 0; j < cc; ++j) {
                if (picture[i][j] == 'B') {
                    ++countC[j];
                    ++countR[i];
                }
            }
            srows.push_back(s);
        }
        for(int i = 0; i < rc; ++i)
            if(countR[i] == N && m[srows[i]] == N)
                for(int j = 0; j < cc; ++j)
                     if(picture[i][j] == 'B' && countC[j] == N) ++res;     
        return res;
    }
};

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty() || !N) return 0;
        int rc = picture.size(), cc = picture[0].size(), res = 0;
        unordered_map<string, int> m;
        vector<vector<int>> columnBRows(cc);
        vector<int> countR(rc);
        vector<string> srows;
        for (int i = 0; i < rc; ++i){
            string s(picture[i].begin(), picture[i].end());
            ++m[s];
            for (int j = 0; j < cc; ++j) {
                if (picture[i][j] == 'B') {
                    columnBRows[j].push_back(i);
                    ++countR[i];
                }
            }
            srows.push_back(s);
        }
        for(int i = 0; i < cc; ++i) {
            if (columnBRows[i].size() == N && m[srows[columnBRows[i][0]]] == N && countR[columnBRows[i][0]] == N) res += N;
        }
        return res;
    }
};