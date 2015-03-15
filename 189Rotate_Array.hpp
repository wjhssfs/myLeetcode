// 189 Rotate Array 
// Rotate an array of n elements to the right by k steps.
// 
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
// 
// Note:
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// 
// [show hint]
// 
// Related problem: Reverse Words in a String II

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (n <= 0) return;
        k %= n;
        int curStart = -1;
        int nMoved = 0;
        while (nMoved < n)
        {   
            curStart++;
            int curP = curStart;
            int cur = nums[curP];
            do{
                int nextP = (curP + k + n) % n;
                swap(cur, nums[nextP]);
                nMoved++;
                curP = nextP;
            } while (curP != curStart);
        }
    }
};