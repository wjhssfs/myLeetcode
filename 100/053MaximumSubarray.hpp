// 53 Maximum Subarray 
// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.
// If you have figured out the O(n) solution, try coding another solution using the divide and
// conquer approach, which is more subtle.

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = A[0];
        int sum = A[0];
        for(int i = 1; i < n; i++){
            sum = sum+A[i];
            if(A[i] > sum) sum = A[i];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};

public static int maxSubArray(int[] A) {
    int maxSoFar=A[0], maxEndingHere=A[0];
    for (int i=1;i<A.length;++i){
        maxEndingHere= Math.max(maxEndingHere+A[i],A[i]);
        maxSoFar=Math.max(maxSoFar, maxEndingHere); 
    }
    return maxSoFar;
}