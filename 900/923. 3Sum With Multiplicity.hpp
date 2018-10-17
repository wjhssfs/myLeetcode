// 923. 3Sum With Multiplicity
// Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.

// As the answer can be very large, return it modulo 10^9 + 7.

 

// Example 1:

// Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
// Output: 20
// Explanation: 
// Enumerating by the values (A[i], A[j], A[k]):
// (1, 2, 5) occurs 8 times;
// (1, 3, 4) occurs 8 times;
// (2, 2, 4) occurs 2 times;
// (2, 3, 3) occurs 2 times.
// Example 2:

// Input: A = [1,1,2,2,2,2], target = 5
// Output: 12
// Explanation: 
// A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
// We choose one 1 from [1,1] in 2 ways,
// and two 2s from [2,2,2,2] in 6 ways.
 

// Note:

// 3 <= A.length <= 3000
// 0 <= A[i] <= 100
// 0 <= target <= 300

  int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, long> c;
        for (int a : A) c[a]++;
        long res = 0;
        for (auto it : c)
            for (auto it2 : c) {
                int i = it.first, j = it2.first, k = target - i - j;
                if (!c.count(k)) continue;
                if (i == j && j == k)
                    res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                else if (i == j && j != k)
                    res += c[i] * (c[i] - 1) / 2 * c[k];
                else if (i < j && j < k)
                    res += c[i] * c[j] * c[k];
            }
        return res % int(1e9 + 7);
    }
    
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        long res = 0, mod = 1e9 + 7;
        long dp[301][4] = {};
        for (auto a : A) {
            for (int t = target; t >= 0; --t) {
                for (int i = 2; i > 0; --i) {
                    if (dp[t][i] && t + a <= target) 
                      dp[t + a][i + 1] = (dp[t + a][i + 1] + dp[t][i]) % mod;
                }
            }
            dp[a][1]++;
        }
        return dp[target][3];
    }
};


class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        long res = 0, mod = 1e9 + 7;
        for (int i = 0; i < A.size() - 2; ++i) {
           unordered_map<int, int> m;
           int sum = target - A[i];
           for (int j = i + 1; j < A.size(); ++j) {
               int c = A[j];
               if (m.count(sum - c)) {
                   res = (res + m[sum - c]) % mod;
               }
               m[c]++;
           }
       }
        return res;
    }
};