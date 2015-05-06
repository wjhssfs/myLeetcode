// 69 Sqrt(x) 
// Implement int sqrt(int x).
// 
// Compute and return the square root of x.

class Solution {
public:
    int sqrt(int x) {
        if (x <= 0) return 0;
        int low = 0, high = x;
        while (low <= high){
            int middle = (low + high) / 2;
            if (middle && INT_MAX / middle < middle) {//overflow
                high = middle - 1;
                continue;
            }
            int square = middle *middle;
            if (square < x){
                if (INT_MAX / (middle + 1) <(middle + 1) || (middle + 1)*(middle + 1) > x) return middle;
                low = middle + 1;
            }
            else if (square > x){
                high = middle - 1;
            }
            else{
                return middle;
            }
        }
        return low;
    }
};

class Solution2 {
public:
    int sqrt(int x) {
        assert(x >= 0);
        if(x < 2)
            return x;
        int r = x;
        for(;;){
            int t = ((unsigned int)x / r + r) / 2;
            if(t >= r)
                break;
            r = t;
        }
        return r;
    }
};

/*
Solution: 1. Binary search in range [0, x / 2 + 1].
           2. Newton iteration method. x(i+1) = (x(i) + n/x(i)) / 2.
 See AnnieKim's blog (http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html) for more explanation (in Chinese).
 */

class Solution2 {
public:
    int sqrt_1(int x) {
        long long i = 0;
        long long j = x / 2 + 1;
        while (i <= j)
        {
            long long mid = (i + j) / 2;
            long long sq = mid * mid;
            if (sq == x) return mid;
            else if (sq < x) i = mid + 1;
            else j = mid - 1;
        }
        return j;
    }

    int sqrt_2(int x) {
        if (x == 0) return 0;
        double last = 0;
        double res = 1;
        while (res != last)
        {
            last = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};
