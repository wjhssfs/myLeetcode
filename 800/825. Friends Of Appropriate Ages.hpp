// 825. Friends Of Appropriate Ages

// Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person. 

// Person A will NOT friend request person B (B != A) if any of the following conditions are true:

// age[B] <= 0.5 * age[A] + 7
// age[B] > age[A]
// age[B] > 100 && age[A] < 100
// Otherwise, A will friend request B.

// Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.

// How many total friend requests are made?

// Example 1:

// Input: [16,16]
// Output: 2
// Explanation: 2 people friend request each other.
// Example 2:

// Input: [16,17,18]
// Output: 2
// Explanation: Friend requests are made 17 -> 16, 18 -> 17.
// Example 3:

// Input: [20,30,100,110,120]
// Output: 
// Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
 

// Notes:

// 1 <= ages.length <= 20000.
// 1 <= ages[i] <= 120.

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int result = 0;
        sort(ages.begin(), ages.end());
        for (int i = 0; i < ages.size(); ++i) {
            // # of same age other people
            int rightCount = upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin() - i - 1;
            int leftMin = ages[i] * 0.5 + 7;
            if (leftMin < ages[i]) {
                result += rightCount;
                // # of too yong people.
                result += i - (upper_bound(ages.begin(), ages.end(), leftMin) - ages.begin());
            }
        }
        return result;
    }
};

// https://leetcode.com/problems/friends-of-appropriate-ages/discuss/127341/10ms-concise-Java-solution-O(n)-time-and-O(1)-space
 public int numFriendRequests(int[] ages) {
        int res = 0;
        int[] numInAge = new int[121], sumInAge = new int[121];
        
        for(int i : ages) 
            numInAge[i] ++;
        
        for(int i = 1; i <= 120; ++i) 
            sumInAge[i] = numInAge[i] + sumInAge[i - 1];
        
        for(int i = 15; i <= 120; ++i) {
            if(numInAge[i] == 0) continue;
            int count = sumInAge[i] - sumInAge[i / 2 + 7];
            res += count * numInAge[i] - numInAge[i]; //people will not friend request themselves, so  - numInAge[i]
        }
        return res;
    }