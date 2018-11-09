// 855. Exam Room

// In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.

// When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)

// Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.

 

// Example 1:

// Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
// Output: [null,0,9,4,2,null,5]
// Explanation:
// ExamRoom(10) -> null
// seat() -> 0, no one is in the room, then the student sits at seat number 0.
// seat() -> 9, the student sits at the last seat number 9.
// seat() -> 4, the student sits at the last seat number 4.
// seat() -> 2, the student sits at the last seat number 2.
// leave(4) -> null
// seat() -> 5, the student​​​​​​​ sits at the last seat number 5.
// ​​​​​​​

// Note:

// 1 <= N <= 10^9
// ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
// Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.


class ExamRoom {
    int N;
    set<int> s;
public:
    ExamRoom(int N_) : N(N_) {}
    
    int seat() {
        if (s.empty()) {
            s.insert(0);
            return 0;
        }
        else {
            int maxD = *s.begin();
            int curD = maxD;
            int maxP = 0;

            auto cur = s.begin();
            auto pre = s.begin();
            for (++cur; cur != s.end(); ++cur, ++pre) {
                curD = (*cur - *pre) / 2;
                if (curD > maxD) {
                    maxD = curD;
                    maxP = (*cur + *pre) / 2;
                }
            }
            curD = N - 1 - *s.rbegin();
            if (curD > maxD) {
                maxD = curD;
                maxP = N - 1;
            }
            s.insert(maxP);
            return maxP;
        }
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

// https://leetcode.com/problems/exam-room/discuss/148595/Java-PriorityQueue-with-customized-object.-seat:-O(logn)-leave-O(n)-with-explanation
// PriorityQueue
class ExamRoom {
    PriorityQueue<Interval> pq;
    int N;

    class Interval {
        int x, y, dist;
        public Interval(int x, int y) {
            this.x = x;
            this.y = y;
            if (x == -1) {
                this.dist = y;
            } else if (y == N) {
                this.dist = N - 1 - x;
            } else {
                this.dist = Math.abs(x - y) / 2;    
            }
        }
    }

    public ExamRoom(int N) {
        this.pq = new PriorityQueue<>((a, b) -> a.dist != b.dist? b.dist - a.dist : a.x - b.x);
        this.N = N;
        pq.add(new Interval(-1, N));
    }

    // O(logn): poll top candidate, split into two new intervals
    public int seat() {
        int seat = 0;
        Interval interval = pq.poll();
        if (interval.x == -1) seat = 0;
        else if (interval.y == N) seat = N - 1;
        else seat = (interval.x + interval.y) / 2; 
        
        pq.offer(new Interval(interval.x, seat));
        pq.offer(new Interval(seat, interval.y));
            
        return seat;
    }
    
    // O(n)Find head and tail based on p. Delete and merge two ends
    public void leave(int p) {
        Interval head = null, tail = null;
        List<Interval> intervals = new ArrayList<>(pq);
        for (Interval interval : intervals) {
            if (interval.x == p) tail = interval;
            if (interval.y == p) head = interval;
            if (head != null && tail != null) break;
        }
        // Delete
        pq.remove(head);
        pq.remove(tail);
        // Merge
        pq.offer(new Interval(head.x, tail.y));
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

// https://leetcode.com/problems/exam-room/discuss/139941/Python-O(log-n)-time-for-both-seat()-and-leave()-with-heapq-and-dicts-Detailed-explanation
from heapq import heappop, heappush
class ExamRoom(object):

    def __init__(self, N):
        """
        :type N: int
        """
        self.N = N
        self.heap = []
        self.avail_first = {}
        self.avail_last = {}
        self.put_segment(0, self.N - 1)

    def put_segment(self, first, last):

        if first == 0 or last == self.N - 1:
            priority = last - first
        else:
            priority = (last - first) // 2

        // Python implements heapq as min heap
        segment = [-priority, first, last, True]

        self.avail_first[first] = segment
        self.avail_last[last] = segment

        heappush(self.heap, segment)

    def seat(self):
        """
        :rtype: int
        """
        while True:
            _, first, last, is_valid = heappop(self.heap)

            if is_valid:
                del self.avail_first[first]
                del self.avail_last[last]
                break

        if first == 0:
            ret = 0
            if first != last:
                self.put_segment(first + 1, last)

        elif last == self.N - 1:
            ret = last
            if first != last:
                self.put_segment(first, last - 1)

        else:
            ret = first + (last - first) // 2

            if ret > first:
                self.put_segment(first, ret - 1)

            if ret < last:
                self.put_segment(ret + 1, last)

        return ret

    def leave(self, p):
        """
        :type p: int
        :rtype: void
        """
        first = p
        last = p

        left = p - 1
        right = p + 1

        if left >= 0 and left in self.avail_last:
            segment_left = self.avail_last.pop(left)
            segment_left[3] = False
            first = segment_left[1]

        if right < self.N and right in self.avail_first:
            segment_right = self.avail_first.pop(right)
            segment_right[3] = False
            last = segment_right[2]

        self.put_segment(first, last)