// 621. Task Scheduler

// Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

// However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

// You need to return the least number of intervals the CPU will take to finish all the given tasks.

// Example 1:
// Input: tasks = ['A','A','A','B','B','B'], n = 2
// Output: 8
// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
// Note:
// The number of tasks is in the range [1, 10000].
// The integer n is in the range [0, 100].

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int f[26] = {};
        int topCount = INT_MIN;
        for  (auto t : tasks) {
            ++f[t - 'A'];
            topCount = max(topCount, f[t-'A']);
        }
        int nTopCount = 0;
        for (int i = 0; i < 26; ++i) {
            if (f[i] == topCount) ++nTopCount;
        }
        int topCountLength = (topCount - 1) * (n + 1) + nTopCount;
        return max(topCountLength, (int)tasks.size());
    }
};

// (c[25] - 1) * (n + 1) + 25 - i  is frame size
// when inserting chars, the frame might be "burst", then tasks.length takes precedence
// when 25 - i > n, the frame is already full at construction, the following is still valid.
public class Solution {
    public int leastInterval(char[] tasks, int n) {

        int[] c = new int[26];
        for(char t : tasks){
            c[t - 'A']++;
        }
        Arrays.sort(c);
        int i = 25;
        while(i >= 0 && c[i] == c[25]) i--;

        return Math.max(tasks.length, (c[25] - 1) * (n + 1) + 25 - i);
    }
}