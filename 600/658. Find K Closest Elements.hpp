// 658. Find K Closest Elements
// Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

// Example 1:
// Input: [1,2,3,4,5], k=4, x=3
// Output: [1,2,3,4]
// Example 2:
// Input: [1,2,3,4,5], k=4, x=-1
// Output: [1,2,3,4]
// Note:
// The value k is positive and will always be smaller than the length of the sorted array.
// Length of the given array is positive and will not exceed 104
// Absolute value of elements in the array and x will not exceed 104

// It's the first index i so that arr[i] is better than arr[i+k]
public List<Integer> findClosestElements(List<Integer> arr, int k, int x) {
    int lo = 0, hi = arr.size() - k;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (x - arr.get(mid) > arr.get(mid+k) - x)
            lo = mid + 1;
        else
            hi = mid;
    }
    return arr.subList(lo, lo + k);
}

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it == arr.end()) return vector<int>(arr.begin() + arr.size() - k, arr.end());
        else if (it == arr.begin()) return vector<int>(arr.begin(), arr.begin() + k);
        else {
            auto itp = it - 1;
            deque<int> t;
            while (k > 0)
            {
                --k;
                if (it == arr.end() || abs(*itp - x) <= abs(*it - x)) {
                    t.push_front(*itp);
                    if (itp == arr.begin()) break;
                    --itp;
                } else {
                    t.push_back(*it);
                    ++it;
                }
            }
            while (k > 0) {
                t.push_back(*it);
                ++it;
                --k;
            }
            return vector<int>(t.begin(), t.end());
        }
    }
};

// https://discuss.leetcode.com/topic/99183/java-4-liner-and-o-n-time-solution
public List<Integer> findClosestElements(List<Integer> arr, int k, int x) {
     Collections.sort(arr, (a,b) -> a == b ? a - b : Math.abs(a-x) - Math.abs(b-x));
     arr = arr.subList(0, k);
     Collections.sort(arr);
     return arr;
}

O(n) Time Solution:

public List<Integer> findClosestElements(List<Integer> arr, int k, int x) {
    List<Integer> less = new ArrayList<>(), greater = new ArrayList<>(),
                  lessResult = new LinkedList<>(), greaterResult = new LinkedList<>();
 
    for (Integer i : arr) {
        if (i <= x) less.add(i);
        else greater.add(i);
    }
    
    Collections.reverse(less);
    int  i = 0, j = 0, n = less.size(), m = greater.size();
    for (int size=0;size<k;size++) {
        if (i < n && j < m) {
            if (Math.abs(less.get(i) - x) <= Math.abs(greater.get(j) - x)) lessResult.add(less.get(i++));
            else greaterResult.add(greater.get(j++));
        }
        else if (i < n) lessResult.add(less.get(i++));
        else greaterResult.add(greater.get(j++));
    }

    Collections.reverse(lessResult);
    lessResult.addAll(greaterResult);
    return lessResult;
}