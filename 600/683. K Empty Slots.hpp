// 683. K Empty Slots

// There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

// Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

// For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

// Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

// If there isn't such day, output -1.

// Example 1:
// Input: 
// flowers: [1,3,2]
// k: 1
// Output: 2
// Explanation: In the second day, the first and the third flower have become blooming.
// Example 2:
// Input: 
// flowers: [1,2,3]
// k: 1
// Output: -1
// Note:
// The given array will be in the range [1, 20000].

// O(n)
int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for(int i=0; i<flowers.size();i++)days[flowers[i] - 1] = i + 1;
        int left = 0, right = k + 1, res = INT_MAX;
        for(int i = 0; right < days.size(); i++){
            if(days[i] < days[left] || days[i] <= days[right]){   
                if(i == right)res = min(res, max(days[left], days[right]));    //we get a valid subarray
                left = i, right = k + 1 + i;
            }
        }
        return (res == INT_MAX)?-1:res;
    }

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> bloom;
        for (int i = 0; i < flowers.size(); i++) {
            int p = flowers[i];
            auto it = bloom.insert(p).first;
            if (it != bloom.begin()) {
                if (p-*(--it) == k+1) return i+1;
                it++;
            }
            if (it != bloom.end() && *(++it)-p == k+1) return i+1; 
        }
        return -1;
    }
};

def kEmptySlots(self, flowers, k):
    blooming = []
    for day, flower in enumerate(flowers, 1):
        i = bisect.bisect(blooming, flower)
        for neighbor in blooming[i-(i>0):i+1]:
            if abs(flower - neighbor) - 1 == k:
                return day
        blooming.insert(i, flower)
    return -1