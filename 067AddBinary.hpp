// 67 Add Binary
// Given two binary strings, return their sum (also a binary string).
// For example,
// a = "11"
// b = "1"
// Return "100".

class Solution {
public:
	string addBinary(string a, string b) {
		int aSz = a.size(), bSz = b.size(),carry = 0;
		string result;
		while (aSz > 0 || bSz > 0 || carry){
			int bSum = carry;
			if (aSz) bSum += a[--aSz] - '0';
			if (bSz) bSum += b[--bSz] - '0';
			carry = bSum / 2;
			result += bSum % 2 + '0';
		}
		while (result.size() && result[result.size() - 1] == '0') result.pop_back();
		if (!result.size()) result = "0";
		else{
			result.assign(result.rbegin(), result.rend());
		}
		return result;
	}
};

class Solution2 {
public:
    string addBinary(string a, string b) {
        int N = a.size(), M = b.size(), K = max(N, M);
        string res(K, ' ');
        int carry = 0;
        int i = N-1, j = M-1, k = K-1;
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 2;
            res[k--] = sum % 2 + '0';
        }
        if (carry == 1)
            res.insert(res.begin(), '1');
        return res;
    }
};

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }

        return s;
    }
};