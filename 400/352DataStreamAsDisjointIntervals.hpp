// 352. Data Stream as Disjoint Intervals
// Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
// For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
// [1, 1]
// [1, 1], [3, 3]
// [1, 1], [3, 3], [7, 7]
// [1, 3], [7, 7]
// [1, 3], [6, 7]
// Follow up:
// What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        s.insert(val);
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> ret;
        int start = -1, pre = -1;
        for (int i : s) {
            if (pre == -1) {
                start = pre = i;
            }
            else if (i == pre + 1) {
                ++pre;
            }
            else {
                ret.emplace_back(start, pre);
                start = pre = i;
            }
        }
        if (pre != -1) {
            ret.emplace_back(start, pre);
        }
        return ret;
    }
private:
    set<int> s;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    void addNum(int val) {
        auto it = st.lower_bound(Interval(val, val));
        int start = val, end = val;
        if(it != st.begin() && (--it)->end+1 < val) it++;
        while(it != st.end() && val+1 >= it->start && val-1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it);
        }
        st.insert(it,Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for(auto val: st) result.push_back(val);
        return result;
    }
private:
    struct Cmp{
        bool operator()(Interval a, Interval b){ return a.start < b.start; }
    };
    set<Interval, Cmp> st;
};

 bool operator < (const Interval &i1, const Interval &i2) {
    return i1.start < i2.start;
}

void update_end(const Interval &i, int end) {
    const_cast<Interval &>(i).end = end;
}

class SummaryRanges {
    set<Interval> data;
public:
    SummaryRanges() {}
    void addNum(int val) {
        Interval i(val, val);
        auto &&next = upper_bound(data.begin(), data.end(), i);
        if (next != data.begin() && next != data.end()) {
            auto prev = next; --prev;
            if (prev->end >= val) {
                return;
            }
        }

        if (next == data.end() && !data.empty()) {
            if (data.rbegin()->end >= val) {
                return;
            }
        }

        auto &&curr = data.insert(next, i);
        auto prev = data.end();
        bool erase_curr = false, erase_next = false;
        if (curr != data.begin()) {
            prev = curr; --prev;
            if (prev->end == curr->start - 1) {
                update_end(*prev, curr->start);
                erase_curr = true;
            }
        }
        if (next != data.end()) {
            if (next->start == curr->start + 1) {
                if (erase_curr) {
                    update_end(*prev, next->end);
                } else {
                    update_end(*curr, next->end);
                }
                erase_next = true;
            }
        }

        if (erase_curr) {
            data.erase(curr);
        }

        if (erase_next) {
            data.erase(next);
        }
    }

    vector<Interval> getIntervals() {
        return vector<Interval>(data.begin(), data.end());
    }
};

// using Segment tree
struct MMTreeNode
 {
     Interval range;
     MMTreeNode *left;
     MMTreeNode *right;
     MMTreeNode(int s, int e):range(s, e), left(NULL), right(NULL){}
 };
class SummaryRanges {
private:
    MMTreeNode *rt;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        rt = NULL;
    }
    
    void addNum(int val) {
        addNumHelper(val, rt);
    }
    
    void addNumHelper(int val, MMTreeNode *&root)
    {
        if(root == NULL)
        {
            root = new MMTreeNode(val, val);
            return;
        }
        if(root->range.start <= val && root->range.end >= val) return;
        if(root->range.start == val + 1)
        {
            root->range.start = val;
            //find the rightest node on the left subtree
            if(root->left)
            {
                MMTreeNode *node = root->left;
                if(node->right == NULL)
                {
                    //node's right subtree doesn't exist
                    if(node->range.end == val - 1)
                    {
                        root->range.start = node->range.start;
                        root->left = node->left;
                        delete node;
                    }
                    return;
                }
                //if right subtree exists, then find the rightest node
                MMTreeNode *parent;
                while(node->right)
                {
                    parent = node;
                    node = node->right;
                }
                if(node->range.end == val - 1)
                {
                    parent->right = node->left;
                    root->range.start = node->range.start;
                    delete node;
                }
            }
            return;
        }else if(root->range.end == val - 1)
        {
            root->range.end = val;
            //find the leftest node on the right subtree
            if(root->right)
            {
                MMTreeNode *node = root->right;
                if(node->left == NULL)
                {
                    //node's left subtree doesn't exist
                    if(node->range.start == val + 1)
                    {
                        root->range.end = node->range.end;
                        root->right = node->right;
                        delete node;
                    }
                    return;
                }
                //if left subtree exists, then find the leftest node
                MMTreeNode *parent = root;
                while(node->left)
                {
                    parent = node;
                    node = node->left;
                }
                if(node->range.start == val + 1)
                {
                    parent->left = node->right;
                    root->range.end = node->range.end;
                    delete node;
                }
            }
            return;
        }else if(root->range.start > val)
        {
            addNumHelper(val, root->left);
        }else
        {
            addNumHelper(val, root->right);
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        getIntervalsHelper(rt, result);
        return result;
    }
    //middle order traversal
    void getIntervalsHelper(MMTreeNode *root, vector<Interval> &result)
    {
        if(root == NULL) return;
        getIntervalsHelper(root->left, result);
        result.push_back(root->range);
        getIntervalsHelper(root->right, result);
    }
};

class SummaryRanges {
private:
    vector<Interval> intervals = vector<Interval>();
    
    int binarySearch(vector<Interval> intervals, int val) {
        return binarySearchHelper(intervals, 0, intervals.size(), val);
    }
    
    int binarySearchHelper(vector<Interval> intervals, int start, int end, int val) {
        if (start == end) return -1;
        if (start+1 == end && intervals[start].start < val) return start;
        
        int mid = (start + end)/2;
        if (intervals[mid].start == val) {
            return mid;
        } else if (intervals[mid].start < val) {
            return binarySearchHelper(intervals, mid, end, val);
        } else { //intervals[mid] > val
            return binarySearchHelper(intervals, start, mid, val);
        }
    }
    
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    /** For a new number n, find the last(biggest) interval
     *  [s,t], such that s < n. If no such interval exists, 
     *  return -1.
     */
    void addNum(int val) {
        int index = binarySearch(intervals, val);
        
        // intervals[index] contains val
        if (index != -1 && intervals[index].end >= val) {
            return;
        }
        
        if (index != intervals.size()-1 && val + 1 == intervals[index+1].start) {
            intervals[index+1].start = val;
        } else if (index != -1 && val - 1 == intervals[index].end) {
            intervals[index].end = val;
        } else {
            intervals.insert(intervals.begin() + index + 1, Interval(val, val));
        }
        
        //merge intervals[index] with intervals[index+1]
        if (index != -1 && intervals[index].end + 1 == intervals[index+1].start) {
            intervals[index].end = intervals[index+1].end;
            intervals.erase(intervals.begin()+index+1);
        }
        
        return;
    }
    
    vector<Interval> getIntervals() {
        return this->intervals;
    }
};

class SummaryRanges {
public:
    void addNum(int val) {
        auto Cmp = [](Interval a, Interval b) { return a.start < b.start; };
        auto it = lower_bound(vec.begin(), vec.end(), Interval(val, val), Cmp);
        int start = val, end = val;
        if(it != vec.begin() && (it-1)->end+1 >= val) it--;
        while(it != vec.end() && val+1 >= it->start && val-1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = vec.erase(it);
        }
        vec.insert(it,Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return vec;
    }
private:
    vector<Interval> vec;
};