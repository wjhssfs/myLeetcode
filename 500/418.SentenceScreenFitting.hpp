// 418. Sentence Screen Fitting
// Given a rows x cols screen and a sentence represented by a list of words, find how many times the given sentence can be fitted on the screen.
// Note:
// A word cannot be split into two lines.
// The order of words in the sentence must remain unchanged.
// Two consecutive words in a line must be separated by a single space.
// Total words in the sentence won't exceed 100.
// Length of each word won't exceed 10.
// 1 ≤ rows, cols ≤ 20,000.
// Example 1:
// Input:
// rows = 2, cols = 8, sentence = ["hello", "world"]
// Output: 
// 1
// Explanation:
// hello---
// world---
// The character '-' signifies an empty space on the screen.
// Example 2:
// Input:
// rows = 3, cols = 6, sentence = ["a", "bcd", "e"]
// Output: 
// 2
// Explanation:
// a-bcd- 
// e-a---
// bcd-e-
// The character '-' signifies an empty space on the screen.
// Example 3:
// Input:
// rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]
// Output: 
// 1
// Explanation:
// I-had
// apple
// pie-I
// had--
// The character '-' signifies an empty space on the screen.

// https://discuss.leetcode.com/topic/62455/21ms-18-lines-java-solution
class Solution {
public:
	int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (auto && word : sentence) s += word + " ";
        int start = 0, l = s.length();
        for (int i = 0; i < rows; i++) {
            start += cols;
            if (s[start % l] == ' ') {
                start++;
            } else {
                while (start > 0 && s[(start-1) % l] != ' ') {
                    start--;
                }
            }
        }
        
        return start / s.length();
    }
};

class Solution {
public:
	int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (auto && word : sentence) s += word + " ";
        int len = s.size(), count = 0;
        vector<int> m(len); // adjustment to matched s if first letter in next row is s[i]
        for (int i = 1; i < len; ++i) {
            m[i] = s[i] == ' ' ? 1 : m[i-1] - 1;
        }
        for (int i = 0; i < rows; ++i) {
            count += cols;
            count += m[count % len];
        }
        return count / len;
	}
};

class Solution {
public:
	int wordsTyping(vector<string>& sentence, int rows, int cols) {
		if (sentence.empty()) return 0;
		unordered_map<int, pair<int, int>> m;
		int total = 0, wordIndex = 0, curRow = 0;
		while (curRow < rows) {
			int curCol = -1, wordIndexBegin = wordIndex, totalDelta = 0;
			if (m.count(wordIndexBegin)) {
				wordIndex = m[wordIndexBegin].first;
				total += m[wordIndexBegin].second;
			}
			else {
				while (curCol + 1 + (int)sentence[wordIndex].size() <= cols) {
					curCol += 1 + (int)sentence[wordIndex++].size();
					if (wordIndex == sentence.size()) {
						++totalDelta;
						wordIndex = 0;
					}
				}
				m[wordIndexBegin] = make_pair(wordIndex, totalDelta);
				total += totalDelta;
			}
			++curRow;
		}
		return total;
	}
};