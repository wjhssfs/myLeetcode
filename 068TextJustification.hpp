// 68 Text Justification 
// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
// 
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
// 
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
// 
// For the last line of text, it should be left justified and no extra space is inserted between words.
// 
// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
// 
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.
// 
// click to show corner cases.
// 
// Corner Cases:
// A line other than the last line might contain only one word. What should you do in this case?
// In this case, that line should be left-justified.

 
class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;
		int start = 0;
		int n = 0;
		int curLen = 0;
		while (start + n< words.size()){
			curLen = curLen + (n>0) + words[start + n].size();
			if (curLen == L){
				result.push_back(format(words, start, n + 1, L));
				curLen = 0;
				start = start + n + 1;
				n = 0;
			}
			else if (curLen > L){
				result.push_back(format(words, start, n, L));
				curLen = 0;
				start = start + n;
				n = 0;
			}
			else{
				n++;
				if (start + n == words.size()){
					string temp = words[start];
					for (int i = 1; i < n; i++){
						temp += " " + words[start + i];
					}
					temp += string(L - temp.size(), ' ');
					result.push_back(temp);
				}
			}
		}
		return result;
	}

	string format(vector<string> &words, int start, int n, int L){
		string ret;
		int totalLen = 0;
		for (int i = 0; i < n; i++){
			totalLen += words[start+i].size();
		}
		int totalspce = L - totalLen;
		if (n == 1){
			ret = words[start] + string(totalspce, ' ');
		}
		else{
			ret = words[start];
			for (int i = 1; i < n; i++){
				int iNSpace = totalspce / (n-1) + (i <= totalspce % (n-1));
				ret += string(iNSpace, ' ') + words[start + i];
			}
		}
		return ret;
	}
};

class Solution2 {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0, N = words.size();
        while (i < N)
        {
            int length = words[i].size();
            int j = i + 1;
            while (j < N && length + words[j].size() + (j-i) <= L)
                length += words[j++].size();
            // build line
            string s(words[i]);
            bool isLastLine = (j == N);
            bool oneWord = (j == i + 1);
            int average = isLastLine || oneWord ? 1 : (L - length) / (j - i - 1);
            int extra = isLastLine || oneWord ? 0 : (L - length) % (j - i - 1);
            for (int k = i + 1; k < j; ++k) {
                s.append(extra > 0 ? average + 1 : average, ' ');
                s.append(words[k]);
                extra--;
            }
            s.append(L - s.size(), ' ');
            // push line
            res.push_back(s);
            i = j;
        }
        return res;
    }
};