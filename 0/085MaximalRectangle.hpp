// 85 Maximal Rectangle 
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing
// all ones and return its area.

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        if (!n) return 0;
        vector<int>h(n+1);
        h[n] = 0;
        int maxArea = 0;
        for (int i = 0; i < m; i++){
            stack<int> s;
            for (int j = 0; j < n+1; j++){
                if (j < n)
                {
                    if (matrix[i][j] == '1') h[j]++;
                    else h[j] = 0;
                }

                if (s.empty() || h[j] >= h[s.top()])
                    s.push(j);
                else
                {
                    while (!s.empty() && h[j] < h[s.top()])
                    {
                        int top = s.top();
                        s.pop();
                        int area = h[top] * (s.empty() ? j : (j -1 - s.top()));
                        maxArea = max(area, maxArea);
                    }
                    s.push(j);
                }
            }
        }
        return maxArea;
    }
};


/*
Solution:  dp. (72 milli secs for the large).
              a) dp[i][j] records the number of consecutive '1' on the left and up of the element matrix[i][j].
              b) For each element(i,j), calculate the area of rectangle including the element itself.
 */

class Solution2 {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int N = matrix.size(), M = matrix[0].size();
        pair<int, int> dp[N][M];
        int res = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (matrix[i][j] == '0')
                    continue;
                
                int x = (j == 0) ? 1 : dp[i][j-1].first + 1;
                int y = (i == 0) ? 1 : dp[i-1][j].second + 1;
                dp[i][j] = make_pair(x, y);
                
                int minHeight = y;
                for (int k = j; k > j - x; --k)
                {
                    minHeight = min(minHeight, dp[i][k].second);
                    res = max(res, minHeight * (j - k + 1));
                }
            }
        }
        return res;
    }
};

// height counts the number of successive '1's above (plus the current one). 
// The value of left & right means the boundaries of the rectangle which contains
// the current point with a height of value height.
// 0th row: 0 0 0 1 0 0 0
// 1st row: 0 0 1 1 1 0 0
// 2nd row: 0 1 1 1 1 1 0
//
// left:    0 0 0 3 0 0 0
// right    7 7 7 4 7 7 7
//
// left:    0 0 2 3 2 0 0
// right:   7 7 5 4 5 7 7
//
// left:    0 1 2 3 2 1 0
// right:   7 6 5 4 5 6 7
class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.empty()) return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    int left[n], right[n], height[n];
    fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
    int maxA = 0;
    for(int i=0; i<m; i++) {
        int cur_left=0, cur_right=n; 
        for(int j=0; j<n; j++) { // compute height (can do this from either side)
            if(matrix[i][j]=='1') height[j]++; 
            else height[j]=0;
        }
        for(int j=0; j<n; j++) { // compute left (from left to right)
            if(matrix[i][j]=='1') left[j]=max(left[j],cur_left); 
            else {left[j]=0; cur_left=j+1;}
        }
        // compute right (from right to left)
        for(int j=n-1; j>=0; j--) {
            if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
            else {right[j]=n; cur_right=j;}    
        }
        // compute the area of rectangle (can do this from either side)
        for(int j=0; j<n; j++)
            maxA = max(maxA,(right[j]-left[j])*height[j]);
    }
    return maxA;
  }
};