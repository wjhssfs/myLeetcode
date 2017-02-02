// 401. Binary Watch

// A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

// Each LED represents a zero or one, with the least significant bit on the right.


// For example, the above binary watch reads "3:25".

// Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

// Example:

// Input: n = 1
// Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
// Note:
// The order of output does not matter.
// The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
// The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

vector<string> readBinaryWatch(int num) {
    vector<string> rs;
    for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
        if (bitset<10>(h << 6 | m).count() == num)
            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return rs;
}

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> results;
        for (int i = 0; i <= num; ++i) {
            vector<int> hours = getValid(i, 12);
            vector<int> minutes = getValid(num - i, 60);
            for (auto && hour : hours) {
                for (auto && minute : minutes) {
                    string curTime = to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
                    results.emplace_back(curTime);
                }
            }
        }
        return results;
    }
private:
    vector<int> getValid(int num, int total){
        vector<int> result;
        for (int i = 0; i < total; ++i) {
            int cur = i, n = 0;
            while (cur) {
                if (cur & 1) ++n;
                cur >>= 1;
            }
            if (n == num) {
                result.push_back(i);
            }
        }
        return result;
    }
};

public class Solution {
        String[][] hour = {{"0"}, 
                                   {"1", "2", "4", "8"},
                   {"3", "5", "6", "9", "10"},
                   {"7", "11"}};
        String[][] minute = {{"00"}, //1
                         {"01", "02", "04", "08", "16", "32"}, //6
                         {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"}, //15
                         {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"}, //20
                         {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"}, //14
                         {"31", "47", "55", "59"}}; //4
    public List<String> readBinaryWatch(int num) {
        List<String> ret = new ArrayList();
        for (int i = 0; i <= 3 && i <= num; i++) {
            if (num - i <= 5) {
                for (String str1 : hour[i]) {
                    for (String str2 : minute[num - i]) {
                        ret.add(str1 + ":" + str2);
                    }
                }
            }
        }
        return ret;     
    }
}