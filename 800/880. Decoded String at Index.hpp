// 880. Decoded String at Index

// An encoded string S is given.  To find and write the decoded string to a tape, the encoded string is read one character at a time and the following steps are taken:

// If the character read is a letter, that letter is written onto the tape.
// If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.
// Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.

 

// Example 1:

// Input: S = "leet2code3", K = 10
// Output: "o"
// Explanation: 
// The decoded string is "leetleetcodeleetleetcodeleetleetcode".
// The 10th letter in the string is "o".
// Example 2:

// Input: S = "ha22", K = 5
// Output: "h"
// Explanation: 
// The decoded string is "hahahaha".  The 5th letter is "h".
// Example 3:

// Input: S = "a2345678999999999999999", K = 1
// Output: "a"
// Explanation: 
// The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".
 

// Note:

// 2 <= S.length <= 100
// S will only contain lowercase letters and digits 2 through 9.
// S starts with a letter.
// 1 <= K <= 10^9
// The decoded string is guaranteed to have less than 2^63 letters.

    string decodeAtIndex(string S, int K) {
        long N = 0, i;
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0) //  return c if K == 0 or K == N.
                // decrease N regardless as i is decreased next;
                return string(1, S[i]);
    }
    
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        size_t cur = 0, i = S.size() - 1;
        for (auto c : S) isdigit(c) ? cur *= (c - '0') : ++cur;
        for(; K != cur || isdigit(S[i]); --i) {
            if (isdigit(S[i])) {
                cur /= S[i] - '0';
                K = (K - 1) % cur + 1;
            } else --cur;
        }
        return string(1, S[i]);
    }
};

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        vector<uint64_t> ind;
        for (auto c : S) {
            if (isdigit(c)) ind.push_back(ind.back() * (c - '0'));
            else ind.push_back(ind.empty() ? 1 : ind.back() + 1);
            //cout << ind.back() << endl;
        }
        for (int j = S.size() - 1; j >= 0; --j) {
            //cout << K << " " << S[j] << " " << ind[j]<< endl;
            if (K < ind[j]) continue;
            if (K > ind[j]) K = (K - 1) % ind[j] + 1;
            if (K == ind[j]) {
                if (isdigit(S[j])) K = ind[j - 1];
                else return string(1, S[j]);
            }
        }
        return "";
    }
};

