// 220 Contains Duplicate III 
// Given an array of integers, find out whether there are two distinct indices i and j in the array
// such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        if(nums.empty() || k <= 0 || t < 0) return false;
        for(int i = 0; i < nums.size(); i++){
            if(i>k) s.erase(nums[i-k-1]);
            auto itLow = s.lower_bound((long long)nums[i]-t);
            if(itLow != s.end() && *itLow <= (long long)nums[i]+t)
              return true;
            s.insert(nums[i]);
        }
        return false;
    }
};

// bucket O(n)
// https://leetcode.com/discuss/38206/ac-o-n-solution-in-java-using-buckets-with-explanation
 public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        Map<Long, Long> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            long remappedNum = (long) nums[i] - Integer.MIN_VALUE;
            long bucket = remappedNum / ((long) t + 1);
            if (map.containsKey(bucket)
                    || (map.containsKey(bucket - 1) && remappedNum - map.get(bucket - 1) <= t)
                        || (map.containsKey(bucket + 1) && map.get(bucket + 1) - remappedNum <= t))
                            return true;
            if (map.entrySet().size() >= k) {
                long lastBucket = ((long) nums[i - k] - Integer.MIN_VALUE) / ((long) t + 1);
                map.remove(lastBucket);
            }
            map.put(bucket, remappedNum);
        }
        return false;
    }
}