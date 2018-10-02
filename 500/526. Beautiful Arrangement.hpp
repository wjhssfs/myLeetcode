// 526. Beautiful Arrangement

// Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:

// The number at the ith position is divisible by i.
// i is divisible by the number at the ith position.
// Now given N, how many beautiful arrangements can you construct?

// Example 1:
// Input: 2
// Output: 2
// Explanation: 

// The first beautiful arrangement is [1, 2]:

// Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

// Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

// The second beautiful arrangement is [2, 1]:

// Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

// Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
// Note:
// N is a positive integer and will not exceed 15.

class Solution {
public:
    int countArrangement(int _N) {
        N = _N, total = 0;
        used = vector<char>(N, 0);
        dfs(1);
        return total;
    }
private:
    void dfs(int i) {
        if (i == N + 1) {
            ++total;
            return;
        }
        for (int j = 0; j < used.size(); ++j) {
            if (!used[j] && ((j + 1) % i == 0 || i % (j + 1) == 0)) {
                used[j] = 1;
                dfs(i + 1);
                used[j] = 0;
            }
        }
    }
    int N, total = 0;
    vector<char> used;
};


// By lovellp
// Time: 6ms
class Solution {
public:
    int countArrangement(int N) {
        vector<int> vs;
        for (int i=0; i<N; ++i) vs.push_back(i+1);
        return counts(N, vs);
    }
    int counts(int n, vector<int>& vs) {
        if (n <= 0) return 1;
        int ans = 0;
        for (int i=0; i<n; ++i) {
            if (vs[i]%n==0 || n%vs[i]==0) {
                swap(vs[i], vs[n-1]);
                ans += counts(n-1, vs);
                swap(vs[i], vs[n-1]);
            }
        }
        return ans;
    }
};