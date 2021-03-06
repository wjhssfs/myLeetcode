// 275 H-Index II
// Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
// Hint:
// Expected runtime complexity is in O(log n) and the input is sorted.

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left=0, len = citations.size(), right= len-1,  mid;
        while(left<=right)
        {
            mid=left+ (right-left)/2;
            if(citations[mid] >= (len-mid)) right = mid - 1;
            else left = mid + 1;
        }
        return len - left;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), left = 0, right = n;  // right (last)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) right = mid;
            else left = mid + 1;
        }
        return n - left;
    }
};