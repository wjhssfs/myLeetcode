// 656. Coin Path
// Given an array A (index starts at 1) consisting of N integers: A1, A2, ..., AN and an integer B. The integer B denotes that from any place (suppose the index is i) in the array A, you can jump to any one of the place in the array A indexed i+1, i+2, …, i+B if this place can be jumped to. Also, if you step on the index i, you have to pay Ai coins. If Ai is -1, it means you can’t jump to the place indexed i in the array.

// Now, you start from the place indexed 1 in the array A, and your aim is to reach the place indexed N using the minimum coins. You need to return the path of indexes (starting from 1 to N) in the array you should take to get to the place indexed N using minimum coins.

// If there are multiple paths with the same cost, return the lexicographically smallest such path.

// If it's not possible to reach the place indexed N then you need to return an empty array.

// Example 1:
// Input: [1,2,4,-1,2], 2
// Output: [1,3,5]
// Example 2:
// Input: [1,2,4,-1,2], 1
// Output: []
// Note:
// Path Pa1, Pa2, ..., Pan is lexicographically smaller than Pb1, Pb2, ..., Pbm, if and only if at the first i where Pai and Pbi differ, Pai < Pbi; when no such i exists, then n < m.
// A1 >= 0. A2, ..., AN (if exist) will in the range of [-1, 100].
// Length of A is in the range of [1, 1000].
// B is in the range of [1, 100].

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        if (A[0] == -1 || A.back() == -1) return {};
        vector<int> dp(A.size(), INT_MAX);
        vector<vector<int>> results(A.size());
        results[0] = {1};
        dp[0] = A[0];
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == -1 || dp[i] == INT_MAX) continue;
            for (int j = 1; j <= B && i + j < A.size(); ++j) {
                if (A[i + j] == -1) continue;
                if (dp[i + j] >= dp[i] + A[i + j]) {
                    auto r = results[i];
                    r.push_back(i + j + 1);
                    if (dp[i + j] > dp[i] + A[i + j]) results[i + j]  = r;
                    else results[i + j] = min(results[i + j], r);
                    dp[i + j] = dp[i] + A[i + j];
                }
            }
        }
        if (dp.back() == INT_MAX) return {};
        return results.back();
    }
};


// https://discuss.leetcode.com/topic/98491/java-22-lines-solution-with-proof
// If there are two path to reach n, and they have the same optimal cost, then the longer path is lexicographically smaller.

// Proof by contradiction:
// Assume path P and Q have the same cost, and P is strictly shorter and P is lexicographically smaller.
// Since P is lexicographically smaller, P and Q must start to differ at some point.
// In other words, there must be i in P and j in Q such that i < j and len([1...i]) == len([1...j])
// P = [1...i...n]
// Q = [1...j...n]
// Since i is further away from n there need to be no less steps taken to jump from i to n unless j to n is not optimal
// So len([i...n]) >= len([j...n])
// So len(P) >= len(Q) which contradicts the assumption that P is strictly shorter.

public List<Integer> cheapestJump(int[] A, int B) {
        int n = A.length;
        int[] c = new int[n]; // cost
        int[] p = new int[n]; // previous index
        int[] l = new int[n]; // length
        Arrays.fill(c, Integer.MAX_VALUE);
        Arrays.fill(p, -1);
        c[0] = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == -1) continue;
            for (int j = Math.max(0, i - B); j < i; j++) {
                if (A[j] == -1) continue;
                int alt = c[j] + A[i];
                if (alt < c[i] || alt == c[i] && l[i] < l[j] + 1) {
                    c[i] = alt;
                    p[i] = j;
                    l[i] = l[j] + 1;
                }
            }
        }
        List<Integer> path = new ArrayList<>();
        for (int cur = n - 1; cur >= 0; cur = p[cur]) path.add(0, cur + 1);
        return path.get(0) != 1 ? Collections.emptyList() : path;
    }