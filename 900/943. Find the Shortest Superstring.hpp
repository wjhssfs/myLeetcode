// 943. Find the Shortest Superstring
// Given an array A of strings, find any smallest string that contains each string in A as a substring.

// We may assume that no string in A is substring of another string in A.

 
// Example 1:

// Input: ["alex","loves","leetcode"]
// Output: "alexlovesleetcode"
// Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
// Example 2:

// Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
// Output: "gctaagttcatgcatc"
 

// Note:

// 1 <= A.length <= 12
// 1 <= A[i].length <= 20


class Solution {
    int calc(string& a, string& b) {
        for (int i = 1; i < a.size(); i++)
            if (b.find(a.substr(i)) == 0) return b.size() - a.size() + i;
        return b.size();
    }
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = calc(A[i], A[j]);
                graph[j][i] = calc(A[j], A[i]);
            }
        }
        vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX));
        vector<vector<int>> path(1<<n, vector<int>(n));
        
        int last = -1, min = INT_MAX;
        // start TSP DP
        for (int i = 1; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    int prev = i - (1 << j);
                    if (prev == 0) {
                        dp[i][j] = A[j].size();
                    } else {
                        for (int k = 0; k < n; k++) {
                            if (dp[prev][k] < INT_MAX && dp[prev][k] + graph[k][j] < dp[i][j]) {
                                dp[i][j] = dp[prev][k] + graph[k][j];
                                path[i][j] = k;
                            }
                        }
                    }
                }
                if (i == (1 << n) - 1 && dp[i][j] < min) {
                    min = dp[i][j];
                    last = j;
                }
            }
        }
        
        // build the path
        string sb;
        int cur = (1 << n) - 1;
        stack<int> s;
        while (cur > 0) {
            s.push(last);
            int temp = cur;
            cur -= (1 << last);
            last = path[temp][last];
        }
        
        // build the result
        int i = s.top(); s.pop();
        sb+= A[i];
        while (!s.empty()) {
            int j = s.top(); s.pop();
            sb += A[j].substr(A[j].size() - graph[i][j]);
            i = j;
        }
        return sb;
    }
};