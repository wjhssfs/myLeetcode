// 633. Sum of Square Numbers

// Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

// Example 1:
// Input: 5
// Output: True
// Explanation: 1 * 1 + 2 * 2 = 5
// Example 2:
// Input: 3
// Output: False

class Solution {
public:
    bool judgeSquareSum(int c) {
        int upper = sqrt (c / 2);
        for (int i = 0; i <= upper; ++i) {
            int canSquare = c - i * i;
            int can = (int) sqrt(canSquare);
            if (can * can == canSquare) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0;
        int j=(int)sqrt(c);
        
        while(i<=j){
            int num=i*i+j*j;
            if(num==c){
                return true;
            }else if(num<c){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};