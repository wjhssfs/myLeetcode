// 29 Divide Two Integers 
// Divide two integers without using multiplication, division and mod operator.

// If it is overflow, return MAX_INT.

class Solution {
public:
    int divide(int dividend, int divisor) {
    	assert(divisor != 0);
        long long llDividend = abs((long long)dividend), llDivisor = abs((long long)divisor);
        bool flag = dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0;
        int res = 0;
        while(llDividend >= llDivisor){
        	long long curDividend = llDivisor, tempRes = 1;
        	while((curDividend << 1) <= llDividend){
        		curDividend <<= 1;
        		tempRes <<= 1;
        	}
        	llDividend -= curDividend;
        	res += tempRes;
        }
        return flag? -res:res;
    }
};