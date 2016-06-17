// 6 ZigZag Conversion
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like
// this: (you may want to display this pattern in a fixed font for better legibility)
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

// j point to the top row's index，2 columns at a time
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

public String convert(String s, int nRows) {
    char[] c = s.toCharArray();
    int len = c.length;
    StringBuffer[] sb = new StringBuffer[nRows];
    for (int i = 0; i < sb.length; i++) sb[i] = new StringBuffer();

    int i = 0;
    while (i < len) {
        for (int idx = 0; idx < nRows && i < len; idx++) // vertically down
            sb[idx].append(c[i++]);
        for (int idx = nRows-2; idx >= 1 && i < len; idx--) // obliquely up
            sb[idx].append(c[i++]);
    }
    for (int idx = 1; idx < sb.length; idx++)
        sb[0].append(sb[idx]);
    return sb[0].toString();
}

string convert(string s, int nRows) {

    if (nRows <= 1)
        return s;

    const int len = (int)s.length();
    string *str = new string[nRows];

    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]);

        if (row == 0)
            step = 1;
        else if (row == nRows - 1)
            step = -1;

        row += step;
    }

    s.clear();
    for (int j = 0; j < nRows; ++j)
    {
        s.append(str[j]);
    }

    delete[] str;
    return s;
}

// https://leetcode.com/discuss/55208/if-you-are-confused-with-zigzag-pattern-come-and-see
class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        if(numRows==1)
            return s;
        int step1,step2;
        int len=s.size();
        for(int i=0;i<numRows;++i){
            step1=(numRows-i-1)*2;
            step2=(i)*2;
            int pos=i;
            if(pos<len)
                result+=s.at(pos);
            while(1){
                pos+=step1;
                if(pos>=len)
                    break;
                if(step1)
                    result+=s.at(pos);
                pos+=step2;
                if(pos>=len)
                    break;
                if(step2)
                    result+=s.at(pos);
            }
        }
        return result;
    }
};