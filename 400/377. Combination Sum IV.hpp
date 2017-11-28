// 377. Combination Sum IV

// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

// Example:

// nums = [1, 2, 3]
// target = 4

// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)

// Note that different sequences are counted as different combinations.

// Therefore the output is 7.
// Follow up:
// What if negative numbers are allowed in the given array?
// How does it change the problem?
// What limitation we need to add to the question to allow negative numbers?

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> m(target + 1);
        m[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i >= nums[j]) m[i] += m[i - nums[j]];
            }
        }
        return m[target];
    }
};

// if there are negative numbers in the array, we must add a requirement that each number is only used
// one time, or either positive number or negative number should be used only one time, otherwise there
// would be infinite possible combinations.
// need to limit the len if allow negative.
Map<Integer, Map<Integer,Integer>> map2 = new HashMap<>();
    private int helper2(int[] nums, int len, int target, int MaxLen) {
        int count = 0;
        if (  len > MaxLen  ) return 0;
        if ( map2.containsKey(target) && map2.get(target).containsKey(len)) { 
            return map2.get(target).get(len);
        }
        if ( target == 0 )   count++;
        for (int num: nums) {
            count+= helper2(nums, len+1, target-num, MaxLen);
        }
        if ( ! map2.containsKey(target) ) map2.put(target, new HashMap<Integer,Integer>());
        Map<Integer,Integer> mem = map2.get(target);
        mem.put(len, count);
        return count;
    }
       
    public int combinationSum42(int[] nums, int target, int MaxLen) {
        if (nums == null || nums.length ==0 || MaxLen <= 0 ) return 0;
        map2 = new HashMap<>();
        return helper2(nums, 0,target, MaxLen);
    }