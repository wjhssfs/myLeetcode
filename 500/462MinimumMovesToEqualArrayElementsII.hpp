// 462. Minimum Moves to Equal Array Elements II
// Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
// You may assume the array's length is at most 10,000.
// Example:
// Input:
// [1,2,3]
// Output:
// 2
// Explanation:
// Only two moves are needed (remember each move increments or decrements one element):
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 2) return 0;
        nth_element(nums.begin(), nums.begin() +  sz / 2, nums.end());
        int median = *(nums.begin() + sz / 2);
        int total = 0;
        for (auto num : nums) total += median > num ? median - num : num - median;
        return total;
    }
};

public class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int i = 0, j = nums.length-1;
        int count = 0;
        while(i < j){
            count += nums[j]-nums[i];
            i++;
            j--;
        }
        return count;
    }
}

def minMoves2(self, nums):
    median = sorted(nums)[len(nums) / 2]
    return sum(abs(num - median) for num in nums)

def minMoves2(self, nums):
    nums.sort()
    return sum(nums[~i] - nums[i] for i in range(len(nums) / 2))
//  The ~ operator is the same as in C++, so 0, 1, 2, ... get turned into -1, -2, -3, .... But C++ doesn't support negative indexing.
// In Python, index -1 means the last element, index -2 means the next-to-last element, etc.    