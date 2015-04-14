// 6 ZigZag Conversion
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows == 1) return s;
		string result;
		int c = nRows + nRows - 2;
		for (int i = 0; i != nRows && i !=s.size(); i++){
			if (i == 0 || i == nRows-1){
				for (int j = i; j < s.size(); j += c) result += s[j];
			}
			else{
				for (int j = i; j < s.size(); j += c){
					result += s[j];
					if (j + c - i * 2 < s.size()) result += s[j + c - i * 2];
				}
			}
		}
		return result;
	}
};

// j point to the top row's index
class Solution2 {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string res;
        int inc = (nRows - 1) * 2, N = s.size();
        for (int i = 0; i < nRows; ++i)
        {
            int j = 0;
            while (true)
            {
                if (i > 0 && i < nRows-1 && j-i >= 0 && j-i < N)
                    res.push_back(s[j-i]);
                if (j+i < N)
                    res.push_back(s[j+i]);
                if (j+i >= N)
                    break;
                j += inc;
            }
        }
        return res;
    }
};
