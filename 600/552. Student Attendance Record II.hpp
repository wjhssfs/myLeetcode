// 552. Student Attendance Record II
// Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

// A student attendance record is a string that only contains the following three characters:

// 'A' : Absent.
// 'L' : Late.
// 'P' : Present.
// A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

// Example 1:
// Input: n = 2
// Output: 8 
// Explanation:
// There are 8 records with length 2 will be regarded as rewardable:
// "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" won't be regarded as rewardable owing to more than one absent times. 

// https://discuss.leetcode.com/topic/86526/improving-the-runtime-from-o-n-to-o-log-n
// Let f[i][j][k] denote the # of valid sequences of length i where:

// There can be at most j A's in the entire sequence.
// There can be at most k trailing L's.

class Solution {
public:
	int checkRecord(int n) {
		int mod = 1000000007;
		vector<vector<vector<int>>> f(2, vector<vector<int>>(2, vector<int>(3)));
		f[0] = { { 1, 1, 1 },{ 1, 1, 1 } };
		for (int i = 1; i <= n; ++i) {
			int c = i % 2, p = (i - 1) % 2;
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 3; ++k) {
					int val = f[p][j][2]; // P
					if (j > 0) val = (val + f[p][j - 1][2]) % mod; // A
					if (k > 0) val = (val + f[p][j][k - 1]) % mod; // L
					f[c][j][k] = val;
				}
			}
		}
		return f[n%2][1][2];
	}
};


// f[i][0][0]   | 0 0 1 0 0 0 |   f[i-1][0][0]
// f[i][0][1]   | 1 0 1 0 0 0 |   f[i-1][0][1]
// f[i][0][2] = | 0 1 1 0 0 0 | * f[i-1][0][2]
// f[i][1][0]   | 0 0 1 0 0 1 |   f[i-1][1][0]
// f[i][1][1]   | 0 0 1 1 0 1 |   f[i-1][1][1]
// f[i][1][2]   | 0 0 1 0 1 1 |   f[i-1][1][2]
// Let A be the matrix above, then f[n][][] = A^n * f[0][][], where f[0][][] = [1 1 1 1 1 1]. 
//The final answer is f[n][1][2], which involves multiplying the last row of A^n and the column vector [1 1 1 1 1 1]. 
//Interestingly, it is also equal to A^(n+1)[5][2] as the third column of A is just that vector
final int MOD = 1000000007;
final int M = 6;

int[][] mul(int[][] A, int[][] B) {
    int[][] C = new int[M][M];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < M; k++)
                C[i][j] = (int) ((C[i][j] + (long) A[i][k] * B[k][j]) % MOD);
    return C;
}


int[][] pow(int[][] A, int n) {
    int[][] res = new int[M][M];
    for (int i = 0; i < M; i++)
        res[i][i] = 1;
    while (n > 0) {
        if (n % 2 == 1)
            res = mul(res, A);
        A = mul(A, A);
        n /= 2;
    }
    return res;
}

public int checkRecord(int n) {
    int[][] A = {
            {0, 0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0},
            {0, 1, 1, 0, 0, 0},
            {0, 0, 1, 0, 0, 1},
            {0, 0, 1, 1, 0, 1},
            {0, 0, 1, 0, 1, 1},
    };
    return pow(A, n + 1)[5][2];
}