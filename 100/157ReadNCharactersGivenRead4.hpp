// 157 Read N Characters Given Read4
// The API: int read4(char *buf) reads 4 characters at a time from a file.
// The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
// By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
// Note:
// The read function will only be called once for each test case.

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int len = 0;
        int m = INT_MAX;
        while(len+4<=n) {
            m = read4(buf+len);
            len += m;
            if(m<4) break;
        }
        if(len==n || m<4) return len;

        char remain[4] = {};
        m = min(read4(remain),n-len);
        for(int i = 0; i<m; i++) buf[len++] = remain[i];
        return len;
    }
};