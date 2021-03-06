// 42 Trapping Rain Water 
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        vector<int>left(n), right(n);
        right[n - 1] = left[0] = 0;
        for (int i = n - 2; i >= 0; i--) right[i] = max(right[i+1], A[i + 1]);
        for (int i = 1; i < n; i++) left[i] = max(left[i-1], A[i - 1]);
        int sumR = 0;
        for (int i = 0; i < n; i++)  sumR = max(sumR, sumR + min(left[i], right[i]) - A[i]);
        return sumR;
    }
};

public int trap(int[] A){
    int a=0;
    int b=A.length-1;
    int max=0;
    int leftmax=0;
    int rightmax=0;
    while(a<=b){
        leftmax=Math.max(leftmax,A[a]);
        rightmax=Math.max(rightmax,A[b]);
        if(leftmax<rightmax){
            max+=(leftmax-A[a]);       // leftmax is smaller than rightmax, 
                                       // so the (leftmax-A[a]) water can be stored
            a++;
        }
        else{
            max+=(rightmax-A[b]);
            b--;
        }
    }
    return max;
}

// https://leetcode.com/discuss/45812/7-lines-c-c
int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}

// Here is my idea: instead of calculating area by height*width, we can think it in a cumulative way. In other words, sum water amount of each bin(width=1).
// Search from left to right and maintain a max height of left and right separately, which is like a one-side wall of partial container. Fix the higher one and flow water from the lower part. For example, if current height of left is lower, we fill water in the left bin. Until left meets right, we filled the whole container.
// https://leetcode.com/problems/trapping-rain-water/discuss/17357/Sharing-my-simple-c++-code:-O(n)-time-O(1)-space

class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};