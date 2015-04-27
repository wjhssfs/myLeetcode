// 45 Jump Game II
// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// For example:
// Given array A = [2,3,1,1,4]

// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

class Solution {
public:
    int jump(int A[], int n) {
        int nj = 0,/*n jump*/ lm = 0, /*last maximum*/ cm = 0; /*current maximum*/
        for (int i = 0; i < n; i++){
            if (i > cm) return -1;
            if (i > lm){
                lm = cm; nj++;
            }
            cm = max(cm, i + A[i]);
        }
        return nj;
    }
};

class Solution2 {
public:
    int jump(int A[], int n) {
        vector<int>m(n), l(n)/*max index after covering i*/;
        for (int i = 0; i < n; i++)
        {
            if (A[i] + i <= l[i]) continue;
            if (i > 0 && !m[i]) continue;
            for (int j = 1; j <= A[i] && i+j < n; j++)
            {
                if (m[i + j] == 0)
                {
                    m[i + j] = m[i] + 1;
                }
                else m[i + j] = min(m[i + j], m[i] + 1);
                if(l[i + j] == 0) l[i+j] = A[i] + i;
            }
        }
        return m[n - 1];
    }
};