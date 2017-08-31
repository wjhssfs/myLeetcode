// 644. Maximum Average Subarray II

// Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.

// Example 1:
// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation:
// when length is 5, maximum average value is 10.8,
// when length is 6, maximum average value is 9.16667.
// Thus return 12.75.
// Note:
// 1 <= k <= n <= 10,000.
// Elements of the given array will be in range [-10,000, 10,000].
// The answer with the calculation error less than 10-5 will be accepted.

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = INT_MAX, right = INT_MIN, mid;
        for(int num:nums){
            right = max(right, double(num));
            left = min(left, double(num));
        }
        while(left + 0.00001 < right){
            mid = left + (right - left)/2;
            if(islarger(nums, mid, k))right = mid;
            else left = mid;
        }
        return left;
    }
    
    //Return true when mid is larger than or equal to the maximum average value;
    bool islarger(vector<int>& nums, double mid, int k){
        // sum: the sum from nums[0] to nums[i];
        // prev_sum:  the sum from nums[0] to nums[i-k];
        // min_sum: the minimal value of prev_sum
        double sum = 0, prev_sum = 0, min_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] - mid;
            if(i >= k){
                prev_sum += nums[i-k] - mid;                        
                min_sum = min(prev_sum, min_sum); 
            }
            if(i >= k-1 && sum > min_sum)return false;
        }
        return true;                                               
    }
};


// https://discuss.leetcode.com/topic/96131/python-advanced-o-n-solution-convex-hull-window
// we have a set of points {P_x} = {(x, P[x]) | x = 0...n} (abusing notation P[x] for the array, P_x for the point),
// and we want to find the largest slope between two points that have x coordinates with difference K or more.
// Here, d(a, b-1) is m(P_a, P_b), the slope between P_a and P_b.
// After the first loop and append, hull is exactly the lower convex hull of these points: the slopes d(hull[i], hull[i+1] -1) are increasing,
// and choosing in order any three of those points A, B, C, they are counterclockwise (B lies below AC.)
// Imagine we tried all points P_i (i < j-K) and see which one maximizes the slope of the line m(P_i, P_{j-K}). 
// If we have two points P_0, P_1, then m(P_1, P_{j-K}) > m(P_0, P_{j-K}) iff P_1 is below line P_0 P_{j-K}, 
// namely (P_0, P_1, P_{j-K}) is counterclockwise. This is a transitive property: we can perform this imaginary "tournament" in
// any order and find the winning point, and any points P_i with (P_h, P_i, P_{j-K}) clockwise (h < i < j-K) can be eliminated.
// Suppose (A, B, C) is clockwise, with A.x < B.x < C.x < T.x. The crux of the argument is that max(m(A, T), m(C, T)) > m(B, T).
// Refer to the picture below for a proof of this. That means that any B's that were eliminated when creating the convex hull
// could not have the largest slope m(B, T), where T = P_{j-K}.
def findMaxAverage(self, A, K):
    N = len(A)
    P = [0]
    for x in A:
        P.append(P[-1] + x)

    def d(x, y):
        return (P[y+1] - P[x]) / float(y+1-x)

    hull = collections.deque()
    ans = float('-inf')

    for j in xrange(K-1, N):
        while len(hull) >= 2 and d(hull[-2], hull[-1]-1) >= d(hull[-2], j-K):
            hull.pop()
        hull.append(j-K + 1)
        while len(hull) >= 2 and d(hull[0], hull[1]-1) <= d(hull[0], j):
            hull.popleft()
        ans = max(ans, d(hull[0], j))

    return ans


