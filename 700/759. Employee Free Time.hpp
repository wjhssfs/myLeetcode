// 759. Employee Free Time
// We are given a list schedule of employees, which represents the working time for each employee.

// Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

// Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

// Example 1:
// Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
// Output: [[3,4]]
// Explanation:
// There are a total of three employees, and all common
// free time intervals would be [-inf, 1], [3, 4], [10, inf].
// We discard any intervals that contain inf as they aren't finite.
// Example 2:
// Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
// Output: [[5,6],[7,9]]
// (Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)

// Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

// Note:

// schedule and schedule[i] are lists with lengths in range [1, 50].
// 0 <= schedule[i].start < schedule[i].end <= 10^8.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


 public List<Interval> employeeFreeTime(List<List<Interval>> avails) {
        List<Interval> result = new ArrayList<>();
        List<Interval> timeLine = new ArrayList<>();
        avails.forEach(e -> timeLine.addAll(e));
        Collections.sort(timeLine, ((a, b) -> a.start - b.start));

        Interval temp = timeLine.get(0);
        for(Interval each : timeLine) {
            if(temp.end < each.start) {
                result.add(new Interval(temp.end, each.start));
                temp = each;
            }else{
                temp = temp.end < each.end ? each : temp;
            }
        }
        return result;
    }
    
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> result;
        map<int, int> timeSeq;
        for (auto&& employee : schedule) {
            for (auto&& interval : employee) {
                timeSeq[interval.start]++;
                timeSeq[interval.end]--;
            }
        }
        int cur = 0;
        int start = 0;
        for (auto&& timeStamp : timeSeq) {
            if (timeStamp.second == 0) continue;
            cur += timeStamp.second;
            if (cur == 0) {
                start = timeStamp.first;
            } else if (start != 0) {
                result.emplace_back(start, timeStamp.first);
                start = 0;
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> result;
        typedef pair<vector<Interval>::iterator, vector<Interval>::iterator> PVII;
        auto cmp = [&schedule](PVII a, PVII b) {return a.first->start > b.first->start;};
        priority_queue<PVII, deque<PVII>, decltype(cmp)> pq(cmp);
        for (auto&& employee : schedule) {
            if (employee.begin() != employee.end()) pq.emplace(employee.begin(), employee.end());
        }
        priority_queue<int, deque<int>, greater<int>> ends;
        while (!pq.empty()) {
            if (ends.empty() || pq.top().first->start <= ends.top()) {
                auto t = pq.top(); pq.pop();
                ends.push(t.first->end);
                if (++t.first != t.second) pq.push(t);
            } else {
                if (ends.size() == 1) {
                    result.emplace_back(ends.top(), pq.top().first->start);
                }
                ends.pop();
            }
        }
        return result;
    }
};