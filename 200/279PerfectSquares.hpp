// 279 Perfect Squares
// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> s{0};
        for (int i = 0; i < n; ++i) {
            unordered_set<int> ns;
            for (auto c : s) {
                for (int k = 1; c + k * k <= n; ++k) {
                    if (c + k * k == n) return i + 1;
                    ns.insert(c + k * k);
                }
            }
            swap(s, ns);
        }
        return n;
    }
};


// https://leetcode.com/discuss/58056/summary-of-different-solutions-bfs-static-and-mathematics
// 2.Static Dynamic Programming: 12ms
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }

        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Since cntPerfectSquares is a static vector, if 
        // cntPerfectSquares.size() > n, we have already calculated the result 
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});

        // While cntPerfectSquares.size() <= n, we need to incrementally 
        // calculate the next result until we get the result for n.
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }

            cntPerfectSquares.push_back(cntSquares);
        }

        return cntPerfectSquares[n];
    }
};