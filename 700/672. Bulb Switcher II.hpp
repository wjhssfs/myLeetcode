// 672. Bulb Switcher II
// There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.

// Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

// Flip all the lights.
// Flip lights with even numbers.
// Flip lights with odd numbers.
// Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
// Example 1:
// Input: n = 1, m = 1.
// Output: 2
// Explanation: Status can be: [on], [off]
// Example 2:
// Input: n = 2, m = 1.
// Output: 3
// Explanation: Status can be: [on, off], [off, on], [off, off]
// Example 3:
// Input: n = 3, m = 1.
// Output: 4
// Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].
// Note: n and m both fit in range [0, 1000].

class Solution {
public:
    int flipLights(int n, int m) {
        if (n >= 3 && m >= 3) return 8
        string strRep(n, 'n');
        unordered_set<string> allReps{strRep};
        for (int i = 0; i < m; ++i) {
            unordered_set<string> nextAllReps;
            for (auto&& rep : allReps) {
                string o1 = rep, o2 = rep, o3 = rep, o4 = rep;
                for (int j = 0; j < rep.size(); ++j) rep[j] == 'n' ? o1[j] = 'f' : o1[j] = 'n';
                for (int j = 1; j < rep.size(); j += 2) rep[j] == 'n' ? o2[j] = 'f' : o2[j] = 'n';
                for (int j = 0; j < rep.size(); j += 2) rep[j] == 'n' ? o3[j] = 'f' : o3[j] = 'n';
                for (int j = 0; j < rep.size(); j += 3) rep[j] == 'n' ? o4[j] = 'f' : o4[j] = 'n';
                nextAllReps.insert(o1);
                nextAllReps.insert(o2);
                nextAllReps.insert(o3);
                nextAllReps.insert(o4);
            }
            allReps = nextAllReps;
        }
        return allReps.size();
    }
};


// If we use button 1 and 2, it equals to use button 3.
// Similarly...
// 1 + 2 --> 3, 1 + 3 --> 2, 2 + 3 --> 1
// So, there are only 8 cases.
// All_on, 1, 2, 3, 4, 1+4, 2+4, 3+4
// And we can get all the cases, when n>=2 and m>=3.
// bulbs [1, 2, 3] determine the status of all others. Bulb 4 is determined by the bulbs 1, 2 and 3 (just xor them).
class Solution {
    public int flipLights(int n, int m) {
        if(m==0) return 1;
        if(n==1) return 2;
        if(n==2&&m==1) return 3;
        if(n==2) return 4;
        if(m==1) return 4;
        if(m==2) return 7;
        if(m>=3) return 8;
        return 8;
    }
}