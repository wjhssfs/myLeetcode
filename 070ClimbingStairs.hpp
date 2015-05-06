// 70 Climbing Stairs 
// You are climbing a stair case. It takes n steps to reach to the top.
// 
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        if(mem.find(n) != mem.end()) return mem[n];
        int ret = climbStairs(n-1)+climbStairs(n-2);
        mem[n] = ret;
        return ret;
    }
    map<int, int>mem;
};

class Solution2 {
public:
    int climbStairs(int n) {
        int last = 1;
        int lastlast = 1;
        for (int i = 2; i <= n; i++)
        {
            int step = last + lastlast;
            lastlast = last;
            last = step;
        }
        return last;
    }
};