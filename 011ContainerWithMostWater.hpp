// 11 Container With Most Water
// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container.

class Solution {
public:
    int maxArea(vector<int> &height) {
        int sz = height.size();
        if(sz < 2) return 0;
        int maxA = 0, low = 0, high = sz-1; 
        while(low<high){
            maxA = max(maxA, (high-low)*min(height[low], height[high]));
            if(height[low] < height[high]){
                low++;
            }else{
                high--;
            }
        }
        return maxA;
    }
};