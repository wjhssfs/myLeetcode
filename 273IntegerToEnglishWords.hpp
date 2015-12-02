// 273 Integer to English Words
// Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.

// For example,
// 123 -> "One Hundred Twenty Three"
// 12345 -> "Twelve Thousand Three Hundred Forty Five"
// 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// Hint:

// Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
// Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
// There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)

class Solution {
public:
    string numberToWords(int num) {
        if(!num) return "Zero";
        string output;
        int billion = num / 1000000000;
        gen(output, billion, "Billion");
        num -= billion * 1000000000;
        int million = num /1000000;
        gen(output, million, "Million");
        num -= million * 1000000;
        int thousand = num /1000;
        gen(output, thousand, "Thousand");
        num -= thousand * 1000;
        gen(output, num, "");
        return output;
    }
private:
    void gen(string &output, int num, string suffix){
        if(!num) return;
        if(num >= 100){
            int hundred = num / 100;
            output += (output.empty()?"":" ") + getSpecial(hundred) + " Hundred";
            num -= hundred * 100;
        }
        
        if(num){
            if(num < 20) {
                output += (output.empty()?"":" ") + getSpecial(num);
            }else{
                int tenth = num/10*10;
                output += (output.empty()?"":" ") + getSpecial(tenth);
                num -= tenth;
                if(num)
                    output += " " + getSpecial(num);
            }
        }
        if(!suffix.empty()) output += " " + suffix;
    }
    
    string getSpecial(int n) {
        switch (n){
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
            case 20: return "Twenty";
            case 30: return "Thirty";
            case 40: return "Forty";
            case 50: return "Fifty";
            case 60: return "Sixty";
            case 70: return "Seventy";
            case 80: return "Eighty";
            case 90: return "Ninety";
            default: return "";
        }
    }
};
