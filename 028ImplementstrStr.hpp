// 28 Implement strStr()
// Implement strStr().

// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        while(true)
        {
            char *h = haystack, *n = needle;
            while (*n != '\0' && *h == *n)
            {
                h++; 
                n++;
            }
            if (*n == '\0') return haystack;
            if (*h == '\0') return NULL;
            haystack++;
        }
    }
};

class Solution2 {
public:
    const char *strStr(const char *haystack, const char *needle) {
        if (!haystack || !needle) return nullptr;
        int ch = strlen(haystack), cn = strlen(needle);
        if (!cn) return haystack;
        int *m = new int[cn];
        m[0] = -1;
        for (int i = 1; i < cn; i++){
            int b = m[i - 1];
            while (b >= 0){
                if (needle[i - 1] == needle[b]) {
                    m[i] = b + 1;
                    break;
                }
                else b = m[b];
            }
            if (b < 0) m[i] = 0;
        }
        
        int j = 0;
        for (int i = 0; i < ch; i++){
            while (j != -1){
                if (haystack[i] == needle[j]){
                    j++;
                    if (j == cn) return haystack + i - (cn -1);
                    break;
                }
                else j = m[j];
            }
            if (j == -1) j = 0;
        }
        delete[] m;
        return nullptr;
    }
};

