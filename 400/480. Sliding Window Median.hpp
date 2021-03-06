// 480. Sliding Window Median
// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

// Examples: 
// [2,3,4] , the median is 3

// [2,3], the median is (2 + 3) / 2 = 2.5

// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

// Window position                Median
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       1
//  1 [3  -1  -3] 5  3  6  7       -1
//  1  3 [-1  -3  5] 3  6  7       -1
//  1  3  -1 [-3  5  3] 6  7       3
//  1  3  -1  -3 [5  3  6] 7       5
//  1  3  -1  -3  5 [3  6  7]      6
// Therefore, return the median sliding window as [1,-1,-1,3,5,6].

// Note: 
// You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

// https://discuss.leetcode.com/topic/74963/o-n-log-k-c-using-multiset-and-updating-middle-iterator
// Keep the window elements in a multiset and keep an iterator pointing to the middle value (to "index" k/2, to be precise)
class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
	    multiset<int> window(nums.begin(), nums.begin() + k);
	    auto mid = next(window.begin(), k / 2);
	    vector<double> medians;
	    for (int i=k; ; i++) {

	        // Push the current median.
	        medians.push_back((double(*mid) + *next(mid, k%2 - 1)) / 2);

	        // If all done, return.
	        if (i == nums.size())
	            return medians;
	            
             // // if inserted or removed item equals to the current median, we need to retrace.
             //    // we do not know which exact element will be removed/inserted, and we cannot compare multiset iterators.
             //    // otherwise, we can keep or increment/decrement the current median iterator.
             //    if ((nums[i - k] < *it && nums[i] < *it) || (nums[i - k] > *it && nums[i] > *it)) repos_it = 0;
             //    else if (nums[i - k] < *it && nums[i] > *it) repos_it = 1; // advance forward.
             //    else if (nums[i - k] > *it && nums[i] < *it) repos_it = -1; // advance backward.

	        // Insert nums[i].
	        window.insert(nums[i]);
	        if (nums[i] < *mid)
	            mid--;

	        // Erase nums[i-k].
	        if (nums[i-k] <= *mid)
	            mid++;
	        window.erase(window.lower_bound(nums[i-k]));
	    }
	}
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int, int> hash;                          // count numbers to be deleted
        priority_queue<int, vector<int>> bheap;                // heap on the bottom
        priority_queue<int, vector<int>, greater<int>> theap;  // heap on the top
        
        int i = 0;
        
        // Initialize the heaps
        while (i < k)  { bheap.push(nums[i++]); }
        for (int count = k/2; count > 0; --count) {
            theap.push(bheap.top()); bheap.pop();
        }
        
        while (true) {
            // Get median
            if (k % 2) medians.push_back(bheap.top());
            else medians.push_back( ((double)bheap.top() + theap.top()) / 2 );
            
            if (i == nums.size()) break;
            int m = nums[i-k], n = nums[i++], balance = 0;
            
            // What happens to the number m that is moving out of the window
            if (m <= bheap.top())  { --balance;  if (m == bheap.top()) bheap.pop(); else ++hash[m]; }
            else                   { ++balance;  if (m == theap.top()) theap.pop(); else ++hash[m]; }
            
            // Insert the new number n that enters the window
            if (!bheap.empty() && n <= bheap.top())  { ++balance; bheap.push(n); }
            else                                     { --balance; theap.push(n); }
            
            // Rebalance the bottom and top heaps
            if      (balance < 0)  { bheap.push(theap.top()); theap.pop(); }
            else if (balance > 0)  { theap.push(bheap.top()); bheap.pop(); }
            
            // Remove numbers that should be discarded at the top of the two heaps
            while (!bheap.empty() && hash[bheap.top()])  { --hash[bheap.top()]; bheap.pop(); }
            while (!theap.empty() && hash[theap.top()])  { --hash[theap.top()]; theap.pop(); }
        }
        
        return medians;
    }
};