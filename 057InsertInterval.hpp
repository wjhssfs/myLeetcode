// 57 Insert Interval 
// 
// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// 
// You may assume that the intervals were initially sorted according to their start times.
// 
// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
// 
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
// 
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){return a.start < b.start; });
        int i = 0, j = 1;
        while (j < intervals.size()){
            if (intervals[i].end < intervals[j].start){
                intervals[++i] = intervals[j++];
            }
            else{ intervals[i].end = max(intervals[i].end,intervals[j].end); j++; }
        }
        if (intervals.size()) ret.assign(intervals.begin(), intervals.begin() + i + 1);
        return ret;
    }
};

class Solution2 {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        vector<Interval>::iterator it = intervals.begin();
        bool inserted = false;
        for (; it != intervals.end(); ++it)
        {
            if (inserted || it->end < newInterval.start) // non-overlaping
            {
                res.push_back(*it);
            }
            else if (newInterval.end < it->start)
            {
                res.push_back(newInterval);
                res.push_back(*it);
                inserted = true;
            }
            else // new interval is sub range of *it
            {
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
            }
        }
        if (!inserted)
            res.push_back(newInterval);
        return res;
    }
};