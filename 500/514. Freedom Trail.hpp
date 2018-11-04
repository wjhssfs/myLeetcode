// 514. Freedom Trail
// In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.

// Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.

// Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button. 
// At the stage of rotating the ring to spell the key character key[i]:
// You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
// If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
// Example:


// Input: ring = "godding", key = "gd"
// Output: 4
// Explanation:
//  For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
//  For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
//  Also, we need 1 more step for spelling.
//  So the final output is 4.
// Note:
// Length of both ring and key will be in range 1 to 100.
// There are only lowercase letters in both strings and might be some duplcate characters in both strings.
// It's guaranteed that string key could always be spelled by rotating the string ring.

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<int, int> m, mn;
        m[0] = 0;
        for (int i = 0; i < key.size(); ++i) {
            for (auto && entry : m) {
                int clockI = entry.first, antiClockI = entry.first, cstep = 0, astep = 0;
                while(ring[clockI] != key[i]) {++clockI; if (clockI == ring.size()) clockI = 0; ++cstep;};
                while(ring[antiClockI] != key[i]) {--antiClockI; if (antiClockI == -1) antiClockI += ring.size(); ++astep;}
                if (mn.count(clockI)) mn[clockI] = min(mn[clockI], m[entry.first] + cstep + 1);
                else mn[clockI] = m[entry.first] + cstep + 1;
                if (mn.count(antiClockI)) mn[antiClockI] = min(mn[antiClockI], m[entry.first] + astep + 1);
                else mn[antiClockI] = m[entry.first] + astep + 1;
            }
            m.clear();
            swap(m, mn);
        }
        int res = INT_MAX;
        for (auto && entry : m) {
            res = min(res, entry.second);
        }
        return res;
    }
};

// https://leetcode.com/problems/freedom-trail/discuss/98902/Concise-Java-DP-Solution
class Solution {
public:
 int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        // dp[i][j] means cost (without pressing center button) for spelling the key starting at i-th character when j-th character of ring is at 12 o'clock
        vector<vector<int>> dp(m+1, vector<int>(n,0));
        for(int i = m-1; i >= 0; --i){  // dp[m][j] are all 0
            for(int j = 0; j < n; ++j){
                dp[i][j] = INT_MAX;
                for(int k = 0; k < n; ++k){
                    if(ring[k] == key[i]){
                        int diff = abs(j-k);
                        int steps= min(diff, n-diff);
                        dp[i][j] = min(dp[i][j],dp[i+1][k] + steps);
                    }
                }// for k
            }// for j
        }// for i
        return dp[0][0] + m;    // plus m spell steps
    }
};

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int size = ring.size();
        int ksize = key.size();
        unordered_map<char,vector<int>> mp;//stored index of each characters in ring,pay attention to duplcate characters.
        for(int i=0;i<size;++i){
            mp[ring[i]].push_back(i);
        }
        
        vector<vector<int>> dp(ksize+1,vector<int> (size,INT_MAX));// initializing dp vector 
        fill(dp[0].begin(),dp[0].end(),0);
        
        vector<int> tmp(1,0); // starting index {0}
        
        int res = INT_MAX;
        for(int i=1;i<=ksize;++i){
            for(auto it:mp[key[i-1]]){  //
                for(int j=0;j<tmp.size();++j){  //Search The shortest distance key[i-1] in ring
                    int minDist = min((tmp[j] + size -it)%size,(it + size - tmp[j])%size) + dp[i-1][tmp[j]];// Look at the above explanation
                    dp[i][it] =min(dp[i][it],minDist);
                    res = (i!=ksize?res:min(res,dp[i][it])); //Can we optimize it?
                }
            }
            tmp = mp[key[i-1]]; //next start is the characters we search in this time
        }
        return res + ksize;
    }
};