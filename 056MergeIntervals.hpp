// 56 Merge Intervals 
// Given a collection of intervals, merge all overlapping intervals.
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

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

class Solution {
private:
    static bool compare(Interval& i1, Interval& i2) {
        return i1.start<i2.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size()<2) return intervals;

        vector<Interval> M_I;
        sort(intervals.begin(),intervals.end(),compare);

        auto it=intervals.cbegin();
        Interval in=*it;
        ++it;
        for (it;it!=intervals.cend();++it) {
            if (it->start>in.end) {M_I.push_back(in); in=*it;}
            else in.end=max(in.end,it->end);
        }
        M_I.push_back(in);
        return M_I;
    }
};