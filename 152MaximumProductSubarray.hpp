// 152 Maximum Product Subarray 
// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
// 
// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.

class Solution {
public:
    int maxProduct(int A[], int n) {
        int maxP = A[0], curP, begin = 0, end;
        while (begin < n){
            curP = A[begin];
            maxP = max(curP, maxP);
            if (!curP){ 
                begin++;
                continue;
            }
            end = begin + 1;
            while (end != n && A[end] != 0){
                curP *= A[end++];
                maxP = max(curP, maxP);
            }
            while (curP < 0 && begin < end -1) {
                curP /= A[begin++];
                maxP = max(curP, maxP);
            }
            begin = end;
        }
        return maxP;
    }
};