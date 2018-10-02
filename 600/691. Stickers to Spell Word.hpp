// 691. Stickers to Spell Word

// We are given N different types of stickers. Each sticker has a lowercase English word on it.

// You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.

// You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

// What is the minimum number of stickers that you need to spell out the target? If the task is impossible, return -1.

// Example 1:

// Input:

// ["with", "example", "science"], "thehat"
// Output:

// 3
// Explanation:

// We can use 2 "with" stickers, and 1 "example" sticker.
// After cutting and rearrange the letters of those stickers, we can form the target "thehat".
// Also, this is the minimum number of stickers necessary to form the target string.
// Example 2:

// Input:

// ["notice", "possible"], "basicbasic"
// Output:

// -1
// Explanation:

// We can't form the target "basicbasic" from cutting letters from the given stickers.
// Note:

// stickers has length in the range [1, 50].
// stickers consists of lowercase English words (without apostrophes).
// target has length in the range [1, 15], and consists of lowercase English letters.
// In all test cases, all words were chosen randomly from the 1000 most common US English words, and the target was chosen as a concatenation of two random words.
// The time limit may be more challenging than usual. It is expected that a 50 sticker test case can be solved within 35ms on average.


// encode available characters in to i.
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        int N = 1 << n;
        vector<int> dp(N, -1);
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            if (dp[i] == -1) continue;
            for (int j = 0; j < stickers.size(); ++j) {
                int cur = i;
                for (int k = 0; k < stickers[j].size(); ++k) { 
                    for (int r = 0; r < n; ++r) {
                        if ((cur >> r) & 1) continue; // skip if target[r] is already available in cur
                        if (stickers[j][k] == target[r]) {
                            cur |= 1 << r;
                            break;
                        }
                    }
                    if (dp[cur] == -1 || dp[cur] > dp[i] + 1) dp[cur] = dp[i] + 1;
                }
            }
        }
        return dp[N - 1];
    }
};

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = stickers.size();
        vector<vector<int>> mp(m, vector<int>(26, 0));
        unordered_map<string, int> dp;
        // count characters a-z for each sticker 
        for (int i = 0; i < m; i++) 
            for (char c:stickers[i]) mp[i][c-'a']++;
        dp[""] = 0;
        return helper(dp, mp, target);
    }
private:
    int helper(unordered_map<string, int>& dp, vector<vector<int>>& mp, string target) {
        if (dp.count(target)) return dp[target];
        int ans = INT_MAX, n = mp.size();
        vector<int> tar(26, 0);
        for (char c:target) tar[c-'a']++;
        // try every sticker
        for (int i = 0; i < n; i++) {
            // optimization
            if (mp[i][target[0]-'a'] == 0) continue; 
            string s;
            // apply a sticker on every character a-z
            for (int j = 0; j < 26; j++) 
                if (tar[j]-mp[i][j] > 0) s += string(tar[j]-mp[i][j], 'a'+j);
            int tmp = helper(dp, mp, s);
            if (tmp!= -1) ans = min(ans, 1+tmp);
        }
        dp[target] = ans == INT_MAX? -1:ans;
        return dp[target];
    }
};

#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1<<15;
int dp[SIZE];
void update(int &x,int v){
    if(x==-1||x>v)x=v;
}
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        MS1(dp);
        dp[0]=0;
        int n=SZ(target);
        int N=1<<n;
        REP(i,N){
            if(dp[i]==-1)continue;
            REP(j,SZ(stickers)){
                int now=i;
                REP(k,SZ(stickers[j])){
                    REP(r,n){
                        if((now>>r)&1)continue;
                        if(target[r]==stickers[j][k]){
                            now|=1<<r;
                            break;
                        }
                    }
                }
                update(dp[now],dp[i]+1);
            }
        }
        return dp[N-1];
    }
};