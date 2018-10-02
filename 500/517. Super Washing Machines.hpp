// 517. Super Washing Machines

// You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

// For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time .

// Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.

// Example1

// Input: [1,0,5]

// Output: 3

// Explanation: 
// 1st move:    1     0 <-- 5    =>    1     1     4
// 2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
// 3rd move:    2     1 <-- 3    =>    2     2     2   
// Example2

// Input: [0,3,0]

// Output: 2

// Explanation: 
// 1st move:    0 <-- 3     0    =>    1     2     0    
// 2nd move:    1     2 --> 0    =>    1     1     1     
// Example3

// Input: [0,2,0]

// Output: -1

// Explanation: 
// It's impossible to make all the three washing machines have the same number of dresses. 
// Note:
// The range of n is [1, 10000].
// The range of dresses number in a super washing machine is [0, 1e5].

// https://discuss.leetcode.com/topic/79938/super-short-easy-java-o-n-solution
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int total = accumulate(machines.begin(), machines.end(), 0);
        if (total % machines.size()) return -1;
        int avg = total / machines.size(), cnt = 0, res = 0;
        for (int load : machines) {
            cnt += load - avg; //load-avg is "gain/lose", cnt is total value flow through
            res = max(max(res, abs(cnt)), load - avg);  // not abs(load - avg), can flow in from both neighbor
        }
        return res;
    }
};

// https://discuss.leetcode.com/topic/79923/c-16ms-o-n-solution-with-trivial-proof
// Since we can operate several machines at the same time, the minium number of moves
// is the maximum number of necessary operations on every machine.
// L > 0 && R > 0: both sides lacks dresses, and we can only export one dress from current machines at a time, so result is abs(L) + abs(R)
// L < 0 && R < 0: both sides contains too many dresses, and we can import dresses from both sides at the same time, so result is max(abs(L), abs(R))
// L < 0 && R > 0 or L >0 && R < 0: the side with a larger absolute value will import/export its extra dresses from/to current machine or other side, so result is max(abs(L), abs(R))
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size();
        vector<int> sum(len + 1, 0);
        for (int i = 0; i < len; ++i)
            sum[i + 1] = sum[i] + machines[i];

        if (sum[len] % len) return -1;

        int avg = sum[len] / len;
        int res = 0;
        for (int i = 0; i < len; ++i)
        {
            int l = i * avg - sum[i];
            int r = (len - i - 1) * avg - (sum[len] - sum[i] - machines[i]);

            if (l > 0 && r > 0)
                res = std::max(res, std::abs(l) + std::abs(r));
            else
                res = std::max(res, std::max(std::abs(l), std::abs(r)));
        }
        return res;
    }
};

public class Solution {
    public int findMinMoves(int[] machines) {
        int total = 0, target = 0, result = 0, n = machines.length;
        for (int d : machines) total += d;
        if (total == 0) return 0;
        if (total % n != 0) return -1;
        target = total / n;
        
        int[] move = new int[n];
        for (int i = 0; i < n - 1; i++) {
            if (machines[i] > target) {
                move[i] += machines[i] - target;
                machines[i + 1] += machines[i] - target;
                machines[i] = target;
                result = Math.max(result, move[i]);
            }
            else {
                move[i + 1] = target - machines[i];
                machines[i + 1] -= target - machines[i];
                machines[i] = target;
                result = Math.max(result, move[i + 1]);
            }
        }
        
        return result;
    }
}