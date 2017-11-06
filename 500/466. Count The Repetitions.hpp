// 466. Count The Repetitions

// Define S = [s,n] as the string S which consists of n connected strings s. For example, ["abc", 3] ="abcabcabc".

// On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.

// You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be obtained from S1.

// Example:

// Input:
// s1="acb", n1=4
// s2="ab", n2=2

// Return:
// 2

// https://discuss.leetcode.com/topic/70667/c-0ms-o-str1-length-str2-length/6
class Solution  {
public:
	int getMaxRepetitions(string s1, int n1, string s2, int n2)  {

		// Let (pass2, idx2) mean that we cover a string s2 for pass2 times,
		// and reach idx2-th character.
		// (pass2s, idx2s) stores the that, for pass1-th pass of s1,
		// we cover a string s2 for pass2s[pass1] times,
		// and reach idx2s[pass1]-th character.

		vector<int> pass2s(s2.size() + 1u, -1);
		vector<int> idx2s(s2.size() + 1u, -1);
		pass2s[0] = 0;
		idx2s[0] = 0; // at the beginning, we are at (0, 0)
		// we will let all elements in idx2s be different
		// according to pigeonhole principle,
		// we only need s2.size()+1 to find two elements 
		// that are identical to each other.

		int pass2 = 0;
		int idx2 = 0;

		for (int pass1 = 1; pass1 <= n1; ++pass1) {
			// Due to pigeonhole principle
			// we are sure to break within O(s2.size()) iterations

			for (int idx1 = 0; idx1 < s1.size(); ++idx1) { // scan s1
				if (s2[idx2] == s1[idx1]) {
					++idx2;
					if (idx2 == s2.size()) {
						idx2 = 0;
						++pass2;
					}
				}
			}
			pass2s[pass1] = pass2;
			idx2s[pass1] = idx2;

			// try to find the repetitive part
			for (int prevPass1 = 0; prevPass1 < pass1; ++prevPass1) {
				if (idx2s[prevPass1] == idx2) {
					// prevRepeat1 and pass1 share the same idx2,
					// repetitive part is found

					int repeatCount = (n1 - prevPass1) / (pass1 - prevPass1);
					int remainPass1count = (n1 - prevPass1) % (pass1 - prevPass1);

					int prefixPass2Num = pass2s[prevPass1]; // prefix part
					int repetitivePass2Num = repeatCount * (pass2s[pass1] - pass2s[prevPass1]); // repetitive part
					int suffixPass2Num = pass2s[prevPass1 + remainPass1count] - pass2s[prevPass1];
					
					int overallPass2Num = prefixPass2Num + repetitivePass2Num + suffixPass2Num;
					return overallPass2Num / n2;
				}
			}
		}

		// no repeative part found
		return pass2s[n1] / n2;
	}
};

public class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        char[] array1 = s1.toCharArray(), array2 = s2.toCharArray();
        int count1 = 0, count2 = 0, i = 0, j = 0;
        
        while (count1 < n1) {
            if (array1[i] == array2[j]) {
                j++;
                if (j == array2.length) {
                    j = 0;
                    count2++;
                }
            }
            i++;
            if (i == array1.length) {
                i = 0;
                count1++;
            }
        }
        
        return count2 / n2;
    }
}