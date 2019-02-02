// 984. String Without AAA or BBB

// Given two integers A and B, return any string S such that:

// S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
// The substring 'aaa' does not occur in S;
// The substring 'bbb' does not occur in S.
 

// Example 1:

// Input: A = 1, B = 2
// Output: "abb"
// Explanation: "abb", "bab" and "bba" are all correct answers.
// Example 2:

// Input: A = 4, B = 1
// Output: "aabaa"
 

// Note:

// 0 <= A <= 100
// 0 <= B <= 100
// It is guaranteed such an S exists for the given A and B.

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string r;
        int p = 0;
        while (A || B) {
            if (A && p < 2 && (p == -2 || A > B)) {
                p = max(1, p + 1);
                r += 'a';
                --A;
            } else {
                p = min(-1, p - 1);
                r += 'b';
                --B;
            }
        }
        return r;
    }
};

string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
  if (B > A) return strWithout3a3b(B, A, b, a);
  while (A-- > 0) {
    res += a;
    if (A > B) res += a, A--;
    if (B-- > 0) res += b;
  }
  return res;
}