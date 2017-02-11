// 362. Design Hit Counter
// Design a hit counter which counts the number of hits received in the past 5 minutes.

// Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

// It is possible that several hits arrive roughly at the same time.

// Example:
// HitCounter counter = new HitCounter();

// // hit at timestamp 1.
// counter.hit(1);

// // hit at timestamp 2.
// counter.hit(2);

// // hit at timestamp 3.
// counter.hit(3);

// // get hits at timestamp 4, should return 3.
// counter.getHits(4);

// // hit at timestamp 300.
// counter.hit(300);

// // get hits at timestamp 300, should return 4.
// counter.getHits(300);

// // get hits at timestamp 301, should return 3.
// counter.getHits(301); 
// Follow up:
// What if the number of hits per second could be very large? Does your design scale?


class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        nSlots = 300;
        history.resize(nSlots);
        latestTimestamp = 0;
        nHit = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        for (int i = latestTimestamp + 1; i <= min(timestamp, latestTimestamp + nSlots + 1); ++i) {
            nHit -= history[(i-1)%nSlots];
            history[(i-1)%nSlots] = 0;
        }
        ++history[(timestamp - 1)%nSlots];
        latestTimestamp = timestamp;
        nHit++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        for (int i = latestTimestamp + 1; i <= min(timestamp, latestTimestamp + nSlots + 1); ++i) {
            nHit -= history[(i-1)%nSlots];
            history[(i-1)%nSlots] = 0;
        }
        latestTimestamp = timestamp;
        return nHit;
    }
private:
    vector<int> history;
    int latestTimestamp;
    int nHit;
    int nSlots;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

class HitCounter {
private:
    queue<pair<int, int> >  hits;
    int cnt;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        cnt = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        // maintain the queue to get rid of the outdated hit pair 
        while(!hits.empty() && timestamp - hits.front().first >= 300 ){
            cnt -= hits.front().second;
            hits.pop();
        }
        // count the current hit:
        ++cnt;
        if(!hits.empty() && timestamp == hits.back().first)  ++(hits.back().second);
        else    hits.push(make_pair(timestamp,1));
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!hits.empty() && timestamp - hits.front().first >= 300){
            cnt -= hits.front().second;
            hits.pop();
        }
        return cnt;
    }
};

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        hits.resize(300);
        times.resize(300);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if (times[index] != timestamp) {
            times[index] = timestamp;
            hits[index] = 1;
        } else {
            hits[index]++;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int total = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - times[i] < 300) {
                total += hits[i];
            }
        }
        return total;
    }
private:
    vector<int> hits;
    vector<int> times;
};
