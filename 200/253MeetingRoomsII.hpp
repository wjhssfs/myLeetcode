// 253 Meeting Rooms II
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return 2.
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> points;
        for(auto && interval : intervals){
            points.push_back({interval.start, 1});
            points.push_back({interval.end, -1});
        }
        sort(points.begin(), points.end());
        int curRoom = 0, maxRoom = 0;
        for(int i = 0; i < points.size(); i++){
            curRoom += points[i].second;
            maxRoom = max(maxRoom, curRoom);
        }
        return maxRoom;
    }
};

// https://leetcode.com/discuss/50948/c-o-n-log-n-584-ms-3-solutions

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval&b) { return a.start < b.start;});
        priority_queue<int, deque<int>, greater<int>> q;
        size_t res = 0;
        for (auto && interval : intervals) {
            while (q.size() && interval.start >= q.top()) q.pop();
            q.push(interval.end);
            res = max(res, q.size());
        }
        return static_cast<int>(res);
    }
};