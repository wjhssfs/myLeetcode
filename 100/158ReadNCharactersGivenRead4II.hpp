// 158 Read N Characters Given Read4 II - Call multiple times
// The API: int read4(char *buf) reads 4 characters at a time from a file.
// The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
// By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
// Note:
// The read function may be called multiple times. 

int read4(char *buf){ // function body added for testing
	static char *internal = "this is a string";
	static int p = 0;
	for (int i = 0; i < 4; i++){
		if (!internal[p]) return i;
		buf[i] = internal[p++];
	}
	return 4;
}

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    char buf4[4];
    int cap = 0;
    int cur = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n && cur != cap) buf[i++] = buf4[cur++];        
        while (n - i >= 4) {
            int r = read4(&buf[i]);
            i += r;
            if (r < 4) return i;
        }
        
        if (i < n) {
            cap = read4(buf4);
            cur = 0;
            while (i < n && cur != cap) buf[i++] = buf4[cur++];
        }
        return i;
    }
};

class Solution {
    char buf4[4];
    int cap = 0;
    int cur = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            if (cur == cap) {
                cap = read4(buf4);
                cur = 0;
            }
            if (cap == 0) break;
            if (cur != cap) buf[i++] = buf4[cur++];
        }
        return i;
    }
};