// 8 String to Integer (atoi)
// Implement atoi to convert a string to an integer.
// Hint: Carefully consider all possible input cases. If you want a challenge,
// please do not see below and ask yourself what are the possible input cases.
// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
// You are responsible to gather all the input requirements up front.
// Requirements for atoi:
// The function first discards as many whitespace characters as necessary until the
// first non-whitespace character is found. Then, starting from this character,
// takes an optional initial plus or minus sign followed by as many numerical digits as possible,
// and interprets them as a numerical value.
// The string can contain additional characters after those that form the integral number,
// which are ignored and have no effect on the behavior of this function.
// If the first sequence of non-whitespace characters in str is not a valid integral number,
// or if no such sequence exists because either str is empty or it contains only whitespace characters,
// no conversion is performed.
// If no valid conversion could be performed, a zero value is returned. If the correct value
// is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

class Solution {
public:
	int atoi(const char *str) {
		bool positive = true;
		int ret = 0;
		if (!str) return 0;
		while (isspace(*str)) ++str;
		if (*str == '-' || *str == '+'){
			if (*str == '-') positive = false;
			++str;
		}
		while (isdigit(*str)){
			int cur = (*str - '0');
			if (positive){
				if (INT_MAX / 10 < ret) return INT_MAX;
				else if (INT_MAX - ret * 10 - cur <= 0) return INT_MAX;
				else ret = ret * 10 + cur;
			}
			else{
				if (INT_MIN / 10 > ret) return INT_MIN;
				else if (INT_MIN - ret * 10 + cur >= 0) return INT_MIN;
				else ret = ret * 10  - cur;
			}
			++str;
		}
		return ret;
	}
};

// use long long
class Solution {
public:
    int atoi(const char *str) {
        if (!str) return 0;
        while (*str == ' ') str++;
        bool positive = true;
        if (*str == '+' || *str == '-') {
            positive = *str == '+';
            str++;
        }
        long long res = 0;
        while (isdigit(*str)) {
            res = res * 10 + (*str - '0');
            str++;
        }
        res = positive ? res : -res;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return (int)res;
    }
};

int atoi(const char *str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i++] == '-'); 
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}