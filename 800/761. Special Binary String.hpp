// 761. Special Binary String
// Special binary strings are binary strings with the following two properties:

// The number of 0's is equal to the number of 1's.
// Every prefix of the binary string has at least as many 1's as 0's.
// Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings of S, and swapping them. (Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.)

// At the end of any number of moves, what is the lexicographically largest resulting string possible?

// Example 1:
// Input: S = "11011000"
// Output: "11100100"
// Explanation:
// The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
// This is the lexicographically largest string possible after some number of swaps.
// Note:

// S has length at most 50.
// S is guaranteed to be a special binary string as defined above.

// https://discuss.leetcode.com/topic/116280/easy-and-concise-solution-with-explanation-c-java-python
// Split S into several special strings (as many as possible).
// Special string starts with 1 and ends with 0. Recursion on the middle part.
// Sort all special strings in lexicographically largest order.
// Join and output all strings.

string makeLargestSpecial(string S) {
    int count = 0, i = 0;
    vector<string> res;
    for (int j = 0; j < S.size(); ++j) {
      if (S[j] == '1') count++;
      else count--;
      if (count == 0) {
        res.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
        i = j + 1;
      }
    }
    // if I could swap many times, it turned out to be a sort.
    sort(res.begin(), res.end(), greater<string>());
    string res2 = "";
    for (int i = 0; i < res.size(); ++i) res2 += res[i];
    return res2;
  }

// https://discuss.leetcode.com/topic/116419/think-of-it-as-valid-parentheses/2