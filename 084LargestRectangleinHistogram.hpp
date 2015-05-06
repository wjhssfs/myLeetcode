// 84 Largest Rectangle in Histogram 
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
// 
// 
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
// 
// 
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
// 
// For example,
// Given height = [2,1,5,6,2,3],
// return 10.

class Solution {
    struct Bar
    {
        int index;
        int height;
        Bar(int i, int h) :index(i), height(h){}
    };
public:
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        int sz = height.size();
        stack<Bar> s;
        Bar b(0, 0);
        for (int i = 0; i < sz; i++)
        {
            while (!s.empty() && height[i] < s.top().height)
            {
                b = s.top(); s.pop();
                int start = s.empty() ? 0 : s.top().index + 1;
                maxArea = max(maxArea, (i - start) * b.height);
            }
            s.emplace(i, height[i]);
        }
        while (!s.empty())
        {
            b = s.top(); s.pop();
            int start = s.empty() ? 0 : s.top().index + 1;
            maxArea = max(maxArea, (sz - start) * b.height);
        }
        return maxArea;
    }
};

/*
 Solution: 1. Only calucate area when reaching local maximum value.
           2. Keep a non-descending stack. O(n).
*/

class Solution2 {
public:
    int largestRectangleArea(vector<int> &height) {
        return largestRectangleArea_2(height);
    }
    
    int largestRectangleArea_1(vector<int> &height) {
        int res = 0, N = height.size();
        for (int i = 0; i < N; ++i) {
            if (i < N-1 && height[i] <= height[i+1])
                continue;
            int minHeight = height[i];
            for (int j = i; j >= 0; --j) {
                minHeight = min(minHeight, height[j]);
                res = max((i-j+1) * minHeight, res);
            }
        }
        return res;
    }
    
    int largestRectangleArea_2(vector<int> &height) {
        height.push_back(0);
        int res = 0, i = 0, N = height.size();
        stack<int> stk;
        while (i < N) 
        {
            if (stk.empty() || height[stk.top()] <= height[i])
                stk.push(i++);
            else {
                int index = stk.top(); stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                res = max(res, width * height[index]);
            }
        }
        return res;
    }
};
