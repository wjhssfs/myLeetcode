// 275 H-Index II

// Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

// Hint:

// Expected runtime complexity is in O(log n) and the input is sorted.

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = (int)citations.size();
        if(!n) return 0;
        int l = 0, h = n - 1, m = (l+h)/2;
        while(l < h){
            if(citations[m] >= (n - m)) {
                h = m;
            }
            else l = m + 1;
            m = (l+h)/2;
        }
        if(citations[h] < n - h) return 0;
        return n - h;
    }
};