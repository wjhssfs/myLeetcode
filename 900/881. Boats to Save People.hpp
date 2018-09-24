// 881. Boats to Save People
// The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

// Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

// Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

 

// Example 1:

// Input: people = [1,2], limit = 3
// Output: 1
// Explanation: 1 boat (1, 2)
// Example 2:

// Input: people = [3,2,2,1], limit = 3
// Output: 3
// Explanation: 3 boats (1, 2), (2) and (3)
// Example 3:

// Input: people = [3,5,3,4], limit = 5
// Output: 4
// Explanation: 4 boats (3), (3), (4), (5)
// Note:

// 1 <= people.length <= 50000
// 1 <= people[i] <= limit <= 30000

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        map<int, int> p;
        for (auto i : people) p[i]++; 
        int r = 0;
        while (p.size()) {
            auto it = p.end();
            --it;
            int v1 = it->first;
            if (!--(it->second)) p.erase(it);
            auto s = p.upper_bound(limit - v1);
            if (s != p.begin()) {
                --s;
                if (!--(s->second))p.erase(s);
            }
            ++r;
        }
        return r;
    }
};

// https://leetcode.com/problems/boats-to-save-people/discuss/156855/6-lines-Java-O(nlogn)-code-sorting-+-greedy-with-greedy-algorithm-proof.
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int ans = 0; 
        for (int hi = people.length - 1, lo = 0; hi >= lo; --hi, ++ans) { // high end always moves
            if (people[lo] + people[hi] <= limit) { ++lo; } // low end moves only if it can fit in a boat with high end.
        }
        return ans;
    }