// 731. My Calendar II
// Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

// Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

// A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)

// For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

// Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
// Example 1:
// MyCalendar();
// MyCalendar.book(10, 20); // returns true
// MyCalendar.book(50, 60); // returns true
// MyCalendar.book(10, 40); // returns true
// MyCalendar.book(5, 15); // returns false
// MyCalendar.book(5, 10); // returns true
// MyCalendar.book(25, 55); // returns true
// Explanation: 
// The first two events can be booked.  The third event can be double booked.
// The fourth event (5, 15) can't be booked, because it would result in a triple booking.
// The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
// The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
// the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
// Note:

// The number of calls to MyCalendar.book per test case will be at most 1000.
// In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].

class MyCalendarTwo {
    map<int, int> cal; // key: start or end timestamp. value: active booking count;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ++cal[start];
        --cal[end];
        int count = 0;
        for (auto&& e : cal) {
            count += cal[e.first];
            if (count > 2) {
                ++cal[end];
                --cal[start];
                return false;
            }
            if (e.first >= end) break;
        }
        if (cal[start] == 0) cal.erase(start);
        if (cal[end] == 0) cal.erase(end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */

// we just want to make sure these overlaps does not overlap - having overlap is now ok, but overlapped period
// cannot be overlapped again. So we just need to keep track of all the overlaps with any previous books
class MyCalendar {
    vector<pair<int, int>> books;
public:
    bool book(int start, int end) {
        for (pair<int, int> p : books)
            if (max(p.first, start) < min(end, p.second)) return false;
        books.push_back({start, end});
        return true;
    }
};
class MyCalendarTwo {
    vector<pair<int, int>> books;
public:
    bool book(int start, int end) {
        MyCalendar overlaps;
        for (pair<int, int> p : books) {
            if (max(p.first, start) < min(end, p.second)) { // overlap exist
                pair<int, int> overlapped = getOverlap(p.first, p.second, start, end);
                if (!overlaps.book(overlapped.first, overlapped.second)) return false; // overlaps overlapped
            }
        }
        books.push_back({ start, end });
        return true;
    }

    pair<int, int> getOverlap(int s0, int e0, int s1, int e1) {
        return { max(s0, s1), min(e0, e1)};
    }
};