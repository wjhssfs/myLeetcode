// 248 Strobogrammatic Number III
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
// For example,
// Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.
// Note:
// Because the range might be a large number, the low and high numbers are represented as string.

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        total = 0; _low = low; _high = high;
        for (int i = _low.size(); i <= _high.size(); i++) {
            if (i > _low.size() && i < _high.size()) { // Pruning, handles length of bounds diff a lot
                int subTotal = (int)pow(5, i/2) * ((i % 2) ? 3 : 1);
                subTotal -= (int)pow(5, (i-2)/2) * ((i % 2) ? 3 : 1);
                total += subTotal;
            }
            else
            {
                vector<char> buf(i, 0);
                genStroboWithFiltering(i, 0, buf, i == low.size(), i == high.size());
            }
        }

        return total;
    }

private:
    void genStroboWithFiltering(int curLength, int start, vector<char> buf, bool checkLow, bool checkHigh) {
        if (checkLow && start && curLength == _low.size()) { // Pruning, handles low with many digits
            if (buf[start - 1] < _low[start - 1]) return;
            if (buf[start - 1] > _low[start - 1]) checkLow = false;
        }
        if (checkHigh && start && curLength == _high.size()) { // Pruning, handles low with many digits
            if (buf[start - 1] > _high[start - 1]) return;
            if (buf[start - 1] < _high[start - 1]) checkHigh = false;
        }

        if (start == (curLength - 1) / 2 + 1) { // Pass over half, should check if the whole string is in range.
            if (_low.size() == curLength && string(buf.begin(), buf.end()) < _low) return;
            if (_high.size() == curLength && string(buf.begin(), buf.end()) > _high) return;
            ++total;
            return;
        }

        if (!checkLow && !checkHigh) { // Pruning, handles low with many digits
            int leftLength = curLength - start * 2;
            total += (int)pow(5, leftLength/2) * ((leftLength%2)?3:1);
            return;
        }

        bool isCenter = ((curLength % 2) && (start == (curLength - 1) / 2));

        if (isCenter || start != 0) {
            buf[start] = '0'; buf[curLength - 1 - start] = '0';
            genStroboWithFiltering(curLength, start + 1, buf, checkLow, checkHigh);
        }

        buf[start] = '1'; buf[curLength - 1 - start] = '1';
        genStroboWithFiltering(curLength, start + 1, buf, checkLow, checkHigh);

        if (!isCenter) {
            buf[start] = '6'; buf[curLength - 1 - start] = '9';
            genStroboWithFiltering(curLength, start + 1, buf, checkLow, checkHigh);
        }

        buf[start] = '8'; buf[curLength - 1 - start] = '8';
        genStroboWithFiltering(curLength, start + 1, buf, checkLow, checkHigh);

        if (!isCenter) {
            buf[start] = '9'; buf[curLength - 1 - start] = '6';
            genStroboWithFiltering(curLength, start + 1, buf, checkLow, checkHigh);
        }
    }

    int total;
    string _low, _high;
};



// Construct char array from lenLow to lenHigh and increase count when s is between low and high. Add the stro pairs from outside to inside until left > right.
char[][] pairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
int count = 0;

public int strobogrammaticInRange(String low, String high) {
    for(int len = low.length(); len <= high.length(); len++) {
        dfs(low, high, new char[len], 0, len - 1);
    }
    return count;
}

public void dfs(String low, String high, char[] c, int left, int right) {
    if(left > right) {
        String s = new String(c);
        if((s.length() == low.length() && s.compareTo(low) < 0) || 
           (s.length() == high.length() && s.compareTo(high) > 0)) return;
        count++; 
        return;
    }

    for(char[] p : pairs) {
        c[left] = p[0]; 
        c[right] = p[1];
        if(c.length != 1 && c[0] == '0') continue;
        if(left < right || left == right && p[0] == p[1]) dfs(low, high, c, left + 1, right - 1);
    }
}


class Solution {
public:
    int strobogrammaticInRange(const string& low, const string& high) {
        vector<string> mp = {"00", "11", "69", "88", "96"};
        int count = 0;
        for(int len = low.length(); len <= high.length(); len++) {
            if (len > low.length() && len < high.length()) { // Pruning, handles length of bounds diff a lot
                int subTotal = (int)pow(5, len/2) * ((len % 2) ? 3 : 1);
                subTotal -= (int)pow(5, (len-2)/2) * ((len % 2) ? 3 : 1);
                count += subTotal;
            }
            else
            {
                string temp(len, '0');
                dfs(low, high, temp, 0, len - 1, count, mp);
            }
        }
        return count;
    }
    void dfs(const string& low, const string& high, string& str, int left, int right, int &count, vector<string> &mp) {
        if(left > right) {
            if((str.length() == low.length() && str.compare(low) < 0) || 
               (str.length() == high.length() && str.compare(high) > 0)) return;
            count++; 
            return;
        }
        for(auto p : mp) {
            str[left] = p[0]; 
            str[right] = p[1];
            if(str.size() != 1 && str[0] == '0') continue;
            if(left < right || (left == right && p[0] == p[1])) dfs(low, high, str, left + 1, right - 1, count, mp);
        }
    }
};