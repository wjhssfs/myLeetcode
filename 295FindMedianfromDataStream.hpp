// 295 Find Median from Data Stream

// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

// Examples: 
// [2,3,4] , the median is 3

// [2,3], the median is (2 + 3) / 2 = 2.5

// Design a data structure that supports the following two operations:

// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.
// For example:

// add(1)
// add(2)
// findMedian() -> 1.5
// add(3) 
// findMedian() -> 2

class MedianFinder {
public:
    MedianFinder(){
        seq = 0;
    }
    
    // Adds a number into the data structure.
    void addNum(int num) {
        ms.insert(make_pair(num,++seq));
        if(ms.size() == 1){
            medianLeftIt =  medianRightIt = ms.begin();
        }else {
            if(medianLeftIt == medianRightIt) {
                if(num >= medianRightIt->first) ++medianRightIt;
                else --medianLeftIt;
            }else {
                if(num < medianLeftIt->first) --medianRightIt;
                else if(num >= medianRightIt->first) ++medianLeftIt;
                else {
                    --medianRightIt;
                    ++medianLeftIt;
                }
            }
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        return (medianLeftIt->first + medianRightIt->first) / 2.0;
    }
    
private:
    multiset<pair<int,int>> ms;
    multiset<pair<int,int>>::iterator medianLeftIt, medianRightIt;
    size_t seq;
};


class MedianFinder {
    priority_queue<long> small, large;
public:

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};

// https://leetcode.com/discuss/64850/short-simple-java-c-python-o-log-n-o-1
