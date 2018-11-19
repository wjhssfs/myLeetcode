// 862. Shortest Subarray with Sum at Least K

// Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

// If there is no non-empty subarray with sum at least K, return -1.

 

// Example 1:

// Input: A = [1], K = 1
// Output: 1
// Example 2:

// Input: A = [1,2], K = 4
// Output: -1
// Example 3:

// Input: A = [2,-1,2], K = 3
// Output: 3
 

// Note:

// 1 <= A.length <= 50000
// -10 ^ 5 <= A[i] <= 10 ^ 5
// 1 <= K <= 10 ^ 9

// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C++JavaPython-O(N)-Using-Deque

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int res = A.size() + 1, sum = 0;
        deque<pair<int, int>> dq; // index, sum
        dq.emplace_back(-1, 0);
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            while (dq.size() && sum - dq.front().second >= K) {
                res = min(res, i - dq.front().first);
                dq.pop_front();
            }
            while (dq.size() && sum <= dq.back().second) dq.pop_back();
            dq.emplace_back(i, sum);
        }
        return res > A.size() ? -1 : res;
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N = A.size(), res = N + 1;
        vector<int> B(N + 1, 0);
        for (int i = 0; i < N; i++) B[i + 1] = B[i] + A[i];
        deque<int> d;
        for (int i = 0; i < N + 1; i++) {
            while (d.size() > 0 && B[i] - B[d.front()] >= K)
                res = min(res, i - d.front()), d.pop_front();
            while (d.size() > 0 && B[i] <= B[d.back()]) d.pop_back();
            d.push_back(i);
        }
        return res <= N ? res : -1; 
    }
};