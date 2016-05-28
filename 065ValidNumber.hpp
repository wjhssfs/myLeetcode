// 65 Valid Number 
// Validate if a given string is numeric.
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
class Solution {
public:
	bool isNumber(const char *s) {
		bool hasBaseDigit = false;
		bool eDigitValid = true;
		while (*s == ' ') s++;
		if (*s == '+' || *s == '-') s++;
		while (isdigit(*s)) {
			s++;
			hasBaseDigit = true;
		}
		if (*s == '.')s++;
		while (isdigit(*s)) {
			s++;
			hasBaseDigit = true;
		}
		if (*s == 'e') {
			eDigitValid = false;
			s++;
			if (*s == '+' || *s == '-') s++;
			while (isdigit(*s)) {
				s++; eDigitValid = true;
			}
		}
		while (*s == ' ') s++;
		return *s == 0 && hasBaseDigit && eDigitValid;
	}
};

// https://leetcode.com/discuss/9013/a-simple-solution-in-cpp
bool isNumber(const char *s) 
{
    int i = 0;

    // skip the whilespaces
    for(; s[i] == ' '; i++) {}

    // check the significand
    if(s[i] == '+' || s[i] == '-') i++; // skip the sign if exist

    int n_nm, n_pt;
    for(n_nm=0, n_pt=0; (s[i]<='9' && s[i]>='0') || s[i]=='.'; i++)
        s[i] == '.' ? n_pt++:n_nm++;       
    if(n_pt>1 || n_nm<1) // no more than one point, at least one digit
        return false;

    // check the exponent if exist
    if(s[i] == 'e') {
        i++;
        if(s[i] == '+' || s[i] == '-') i++; // skip the sign

        int n_nm = 0;
        for(; s[i]>='0' && s[i]<='9'; i++, n_nm++) {}
        if(n_nm<1)
            return false;
    }

    // skip the trailing whitespaces
    for(; s[i] == ' '; i++) {}

    return s[i]==0;  // must reach the ending 0 of the string
}
class Solution2 {
public:
    bool isNumber(const char *s) {
        enum InputType {INVALID, SPACE, SIGN, DIGIT, DOT, EXPONENT};
        int transitionTable[][SPACEEND] = 
        { /* 0   1   2   3   4   5  */
             0,  1,  2,  3,  4,  0, // 0: INVALID
             0,  1,  2,  3,  4,  0, // 1: SPACE
             0,  0,  0,  3,  4,  0, // 2: SIGN
             0,  6,  0,  3,  7,  5, // 3: DIGIT
             0,  0,  0,  7,  0,  0, // 4: DOT
             0,  0,  2,  8,  0,  0, // 5: EXPONENT
             0,  6,  0,  0,  0,  0, // 6: END WITH SPACE
             0,  6,  0,  7,  0,  5, // 7: DOT AND DIGIT
             0,  6,  0,  8,  0,  0, // 8: END WITH SPACE OR DIGIT
        };
        
        InputType last = INVALID;
        while (*s != '\0')
        {
            InputType state = INVALID;
            if (*s == ' ')
                state = SPACE;
            else if (isdigit(*s))
                state = DIGIT;
            else if (*s == '+' || *s == '-')
                state = SIGN;
            else if (*s == 'e')
                state = EXPONENT;
            else if (*s == '.')
                state = DOT;
            last = (InputType) transitionTable[last][state];
            if (last == INVALID) return false;
            s++;
        }
        bool validFinal[] = {0, 0, 0, 1, 0, 0, 1, 1, 1};
        return validFinal[last];
    }
};