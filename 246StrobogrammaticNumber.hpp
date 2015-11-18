// 246 Strobogrammatic Number

// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

// Write a function to determine if a number is strobogrammatic. The number is represented as a string.

// For example, the numbers "69", "88", and "818" are all strobogrammatic.

class Solution {
public:
    bool isStrobogrammatic(string num) {
        for(int i = 0; i <= num.size()/2; i++) {
            char &left = num[i], &right = num[num.size()-1-i];
            if(
                ((left == right) && (left == '1' || left == '8' || left == '0')) ||
                (((left == '6') && (right == '9')) || ((left == '9') && (right == '6')))
              ) continue;
            return false;
        }
        
        return true;
    }
};