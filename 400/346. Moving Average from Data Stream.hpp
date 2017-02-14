// 346. Moving Average from Data Stream
// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

// For example,
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : sum(0), size(size) {
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (q.size() > size) { sum -= q.front(); q.pop(); }
        return (double)sum / q.size();
    }
private:
    int sum, size;
    queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */