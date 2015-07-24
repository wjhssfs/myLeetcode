// 221 Maximal Square

// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

// For example, given the following matrix:

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 4.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0, rows = (int)matrix.size(), cols = 0;
        if(rows) cols = (int)matrix[0].size();
        if(!rows || !cols) return 0;
        // # of 1s above and # of 1s to the left
        vector<vector<pair<int, int>>> m(rows, vector<pair<int,int>>(cols));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                m[i][j] = matrix[i][j]=='0'? make_pair(0,0) :
                make_pair(i==0?1:m[i-1][j].first + 1, j==0?1:m[i][j-1].second + 1);
                int curMaxLength = maxSquareLen(m, i, j);
                res = max(res, curMaxLength*curMaxLength);
            }
        }
        return res;
    }
    
    int maxSquareLen(vector<vector<pair<int, int>>> &m, int x, int y){
        int layerBound = min(m[x][y].first, m[x][y].second);
        if(!layerBound) return 0;
        int layer = 1;
        while(x - layer >= 0 && y - layer >= 0 && layer < layerBound){
            int newLayerbound = min(m[x-layer][y-layer].first, m[x-layer][y-layer].second);
            if(!newLayerbound) break;
            layerBound = min (newLayerbound + layer, layerBound);
            layer++;
        }
        return layer;
    }
};	