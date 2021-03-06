// 69 Sqrt(x) 
// Implement int sqrt(int x).
// Compute and return the square root of x.

/*
Solution: 1. Binary search in range [0, x / 2 + 1].
           2. Newton iteration method. x(i+1) = (x(i) + n/x(i)) / 2.
 See AnnieKim's blog (http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html) for more explanation (in Chinese).
 */
class Solution {
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

public int sqrt(int x) {
    long ans = 0;
    long bit = 1l << 16;
    while(bit > 0) {
        ans |= bit;
        if (ans * ans > x) {
            ans ^= bit;
        }
        bit >>= 1;
    }
    return (int)ans;
}

public int sqrt(int x) {
    if (x == 0)
        return 0;
    int left = 1, right = x;
    while (true) {
        int mid = left + (right - left)/2;
        if (mid > x/mid) {
            right = mid - 1;
        } else {
            if (mid + 1 > x/(mid + 1))
                return mid;
            left = mid + 1;
        }
    }
}