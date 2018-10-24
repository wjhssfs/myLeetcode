// 279 Perfect Squares
// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

class Solution {
public:
    int numSquares(int n) {
        if(n<=1) return n;
        vector<int> ps;
        int maxPSR = 1, maxPS = 1;
        while(maxPS <= n) {
            ps.push_back(maxPS);
            ++maxPSR;
            maxPS = maxPSR * maxPSR;
        }
        
        if(n==ps.back()) return 1;
        
        vector<bool> m(n+1);
        queue<int> q;
        q.push(0);
        int count = 0;
        while(1){
            ++count;
            int curCountLeft = q.size();
            while(curCountLeft--){
                int cur = q.front(); q.pop();
                for(int i = 0; i < ps.size(); i++){
                    int next = ps[i] + cur;
                    if(next > n) break;
                    if(next == n) return count;
                    if(m[next]) continue;
                    m[next] = true;
                    q.push(next);
                }
            }
        }
        return -1;
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