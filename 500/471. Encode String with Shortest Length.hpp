// 471. Encode String with Shortest Length

// Given a non-empty string, encode the string such that its encoded length is the shortest.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.

// Note:
// k will be a positive integer and encoded string will not be empty or have extra space.
// You may assume that the input string contains only lowercase English letters. The string's length is at most 160.
// If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them is fine.
// Example 1:

// Input: "aaa"
// Output: "aaa"
// Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.
// Example 2:

// Input: "aaaaa"
// Output: "5[a]"
// Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
// Example 3:

// Input: "aaaaaaaaaa"
// Output: "10[a]"
// Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".
// Example 4:

// Input: "aabcaabcd"
// Output: "2[aabc]d"
// Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".
// Example 5:

// Input: "abbbabbbcabbbabbbc"
// Output: "2[2[abbb]c]"
// Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2[abbb]c", so one answer can be "2[2[abbb]c]".

// https://discuss.leetcode.com/topic/71413/acc-o-n-3-dynamic-programming-solution/2
class Solution {

    void mDP(vector<vector<string> >& DP,string s,int i, int j){
        DP[i][j]=s.substr(i,j);
        //first loop
        for(int k=1;k<j;k++){
            if(j%k==0){
                int fine=true;
                for(int kk=1;kk<j/k;kk++){
                    if(!(s.substr(i,k)==s.substr(i+kk*k,k))){
                        fine=false;
                        break;
                    }
                }
                if(fine){
                    if(DP[i][k].size()==0)mDP(DP,s,i,k);
                    for(int kk=1;kk<j/k;kk++)DP[i+kk*k][k]=DP[i][k];
                    if(DP[i][j].size()>to_string(j/k).size()+2+DP[i][k].size()){
                        DP[i][j]=to_string(j/k)+"["+DP[i][k]+"]";
                    }
                }
            }
        }
        //second loop
        for(int k=1;k<j;k++){
            if(DP[i][k].size()==0)mDP(DP,s,i,k);
            if(DP[i+k][j-k].size()==0)mDP(DP,s,i+k,j-k);
            if(DP[i][j].size()>DP[i][k].size()+DP[i+k][j-k].size()){
                DP[i][j]=DP[i][k]+DP[i+k][j-k];
            }
        }
    }

public:
    string encode(string s) {
        int l=s.size();
        vector<vector<string> > DP(l,*new vector<string>(l+1,""));
        mDP(DP,s,0,l);
        return DP[0][l];
    }
};


// https://discuss.leetcode.com/topic/71442/short-python
// def encode(self, s, memo={}):
//     if s not in memo:
//         n = len(s)
//         i = (s + s).find(s, 1)
//         one = '%d[%s]' % (n / i, self.encode(s[:i])) if i < n else s
//         multi = [self.encode(s[:i]) + self.encode(s[i:]) for i in xrange(1, n)]
//         memo[s] = min([s, one] + multi, key=len)
//     return memo[s]
//https://discuss.leetcode.com/topic/68206/easy-python-solution-with-explaination/6