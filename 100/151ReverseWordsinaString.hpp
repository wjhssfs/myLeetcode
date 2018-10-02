// 151 Reverse Words in a String
// Given an input string, reverse the string word by word.
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".
// Clarification:
// What constitutes a word?
// A sequence of non-space characters constitutes a word.
// Could the input string contain leading or trailing spaces?
// Yes. However, your reversed string should not contain leading or trailing spaces.
// How about multiple spaces between two words?
// Reduce them to a single space in the reversed string.

class Solution {
public:
	void reverseWords(string &s) {
		//normalize s
		int sz = s.size();
		int i = 0;
		int j = 0;
		while (i < sz && s[j] == ' ') j++;
		while (j < sz){
			if (s[j] != ' '){
				s[i] = s[j];
				i++;
				j++;
			}
			else{
				while (j < sz && s[j] == ' ')j++;
				if (j < sz){
					s[i] = ' ';
					i++;
				}
			}
		}
		sz = i;
		s.resize(sz);
		reverseSpan(s, 0, sz);
		int wStart = 0;
		int wEnd = 0;
		while (wEnd < sz){
			while (wEnd < sz && s[wEnd] != ' ') wEnd++;
			reverseSpan(s, wStart, wEnd);
			wStart = wEnd + 1; //skip space, doesn't matter if it is already end
			wEnd = wStart;
		}
	}

	void reverseSpan(string &s, int start, int end){
		if (start >= end) return;
		for (int i = 0; i < (end - start) / 2; i++){
			swap(s[start+i], s[end-i-1]);
		}
	}
};

void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int storeIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (storeIndex != 0) s[storeIndex++] = ' ';
            int j = i;
            while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
            reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
            i = j;
        }
    }
    s.erase(s.begin() + storeIndex, s.end());
}