// 539. Minimum Time Difference

// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

// Example 1:
// Input: ["23:59","00:00"]
// Output: 1
// Note:
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int diff = 1440 - getMDiff(timePoints.front(), timePoints.back());
        for (int i = 0; i < timePoints.size() - 1; ++i) {
            diff = min(diff, getMDiff(timePoints[i], timePoints[i+1]));
        }
        return diff;
    }
private:
    int getMDiff(const string &t1, const string &t2) {
        return ((t2[0] - t1[0]) * 10 + t2[1] - t1[1]) * 60 + (t2[3] - t1[3]) * 10 + t2[4] - t1[4];
    }
};

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<char> m(1440);
        for (auto && t1 : timePoints) {
            int v = ((t1[0] - '0') * 10 + (t1[1] - '0')) * 60 + (t1[3]- '0') * 10 + t1[4] - '0';
            if (m[v]) return 0;
            ++m[v];
        }
        int first = 1440, last = 0, minD = 1440, pre = -1440;
        for (int i = 0; i < 1440; ++i) {
            if (m[i]) {
                first = min(first, i);
                last = max(last, i);
                minD = min(minD, i - pre);
                pre = i;
            }
        }
        minD = min(minD, 1440 - (last - first));
        return minD;
    }
};