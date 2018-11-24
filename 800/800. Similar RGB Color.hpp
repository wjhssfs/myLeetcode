// 800. Similar RGB Color
// In the following, every capital letter represents some hexadecimal digit from 0 to f.

// The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".

// Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

// Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"

// Example 1:
// Input: color = "#09f166"
// Output: "#11ee66"
// Explanation:  
// The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
// This is the highest among any shorthand color.
// Note:

// color is a string of length 7.
// color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
// Any answer which has the same (highest) similarity as the best answer will be accepted.
// All inputs and outputs should use lowercase letters, and the output is 7 characters.

string helper(string str) {
    string dec_to_hex = "0123456789abcdef", res = "";

    int dec_num = stoi(str, nullptr, 16);
    int q = dec_num / 17; //  [ 0x00(0) , 0x11(17), 0x22(34),  0x33(51), ........., 0xff(255) ]
    if ((dec_num % 17) > 8) q = q + 1;
    res = res + dec_to_hex[q] + dec_to_hex[q];
    return res;
}

string similarRGB(string color) {
    return "#" + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) + helper(color.substr(5, 2));
}

class Solution {
    int getV(char c) {
        return c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10;
    }
    string getC(string o) {
        int v = getV(o[0]) * 16 + getV(o[1]);
        cout << v << endl;
        int v1 = v;
        int c = 0;
        while (1) {
            if (v / 16 == v % 16) {
                c = v / 16;
                break;
            }
            if (v1 / 16 == v1 % 16) {
                c = v1 / 16;
                break;
            }
            --v;
            ++v1;
        }
        if (c >= 0 && c <= 9) return string(2, c + '0');
        return string(2, c - 10 + 'a');
    }
public:
    string similarRGB(string color) {
        string A = color.substr(1, 2);
        A = getC(A);
        string B = color.substr(3, 2);
        B = getC(B);
        string C = color.substr(5, 2);
        C = getC(C);
        string r;
        r += '#' + A + B + C;
        return r;
    }
};
