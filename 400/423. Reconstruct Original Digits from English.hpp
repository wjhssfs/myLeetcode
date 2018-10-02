// 423. Reconstruct Original Digits from English
// Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

// Note:
// Input contains only lowercase English letters.
// Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
// Input length is less than 50,000.
// Example 1:
// Input: "owoztneoer"

// Output: "012"
// Example 2:
// Input: "fviefuro"

// Output: "45"

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> count;
        for (auto c : s) ++count[c];
        vector<int> nD(10);
        vector<string> englishDigit = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        vector<char> hint = {'z', 'w', 'u', 'f', 'x', 's', 'g', 'i', 'o', 't'};
        vector<int> order = {0, 2, 4, 5, 6, 7, 8, 9, 1, 3};
        for (int i = 0; i < 10; ++i) {
            int cur = order[i], curCount = count[hint[i]];
            nD[cur] = curCount;
            for (auto c : englishDigit[cur]) {
                count[c] -= curCount;
            }
        }
        string result;
        for (int i = 0; i < 10; ++i) {
            if (nD[i]) {
                result += string(nD[i], '0'+i);
            }
        }
        return result;
    }
};

public String originalDigits(String s) {
    int[] count = new int[10];
    for (int i = 0; i < s.length(); i++){
        char c = s.charAt(i);
        if (c == 'z') count[0]++;
        if (c == 'w') count[2]++;
        if (c == 'x') count[6]++;
        if (c == 's') count[7]++; //7-6
        if (c == 'g') count[8]++;
        if (c == 'u') count[4]++; 
        if (c == 'f') count[5]++; //5-4
        if (c == 'h') count[3]++; //3-8
        if (c == 'i') count[9]++; //9-8-5-6
        if (c == 'o') count[1]++; //1-0-2-4
    }
    count[7] -= count[6];
    count[5] -= count[4];
    count[3] -= count[8];
    count[9] = count[9] - count[8] - count[5] - count[6];
    count[1] = count[1] - count[0] - count[2] - count[4];
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i <= 9; i++){
        for (int j = 0; j < count[i]; j++){
            sb.append(i);
        }
    }
    return sb.toString();
}