// 44 Wildcard Matching 
// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (s == 0 || p == 0) return false;
		if (*s == 0 && *p == 0) return true;
		if (*s == 0) {
			while (*p == '*') p++;
			return *p == 0;
		}
		if (*p == 0) return false;
		if (*s == *p || *p == '?') return isMatch(s + 1, p + 1);
		if (*p == '*'){
			while (*p == '*') p++; //eliminate duplicated *
			if (*p == 0) return true;// tailing * match any string
			while (*s){
				auto st = s, pt = p;
				while (*st && (*st == *pt || *pt == '?')) {
					++st;
					++pt;
				}
				if (!*st && !*pt) return true;
				if (*pt == '*') {
					return isMatch(st, pt);//second *, skip all st, pt. Note when isMatch=false, the whole match will fail 
				}
				if (!*st) return false;
				++s;
			}
		}
		return false;
	}
};


class Solution2 {
public:
    bool isMatch(const char *s, const char *p) {
        const char *sBackup = NULL, *pBackup = NULL;
        while (*s != '\0') {
            if (*p == '?' || *s == *p) {
                s++;
                p++;
            } else if (*p == '*') {
                while (*p == '*') p++;
                if (*p == '\0') return true;
                sBackup = s;
                pBackup = p;
            } else {
                if (!sBackup) return false;
                s = ++sBackup;
                p = pBackup;
            }
        }
        while (*p == '*') p++;
        return *s == '\0' && *p == '\0';
    }
};