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

int readN(char *buf, int n)
{
	static char buf4[4]; // statics are evil
	static int nBuf4;
	int nLeft = n;
	if (!nLeft || !buf) return 0;
	int nMove = min(nLeft, nBuf4);
	memcpy(buf, buf4, nMove);
	nBuf4 -= nMove;	nLeft -= nMove;
	memmove(buf4, buf4 + nMove, nBuf4);
	while (nLeft >= 4){
		int nCurRead = read4(buf + n - nLeft);
		nLeft -= nCurRead;
		if (nCurRead != 4) return n - nLeft;
	}
	if (nLeft>0){
		nBuf4 = read4(buf4);
		int nMove = min(nLeft, nBuf4);
		memcpy(buf + n - nLeft, buf4, nMove);
		nBuf4 -= nMove;	nLeft -= nMove;
		memmove(buf4, buf4 + nMove, nBuf4);
	}
	return n - nLeft;
}

class Solution {
public:
    Solution():buf4Index(0), buf4Read(0){}
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
    	int cnt = 0;
        while(cnt < n){
            if(buf4Index == 0)
                buf4Read = read4(buf4);
            if(buf4Read == 0)  break;
            while(cnt < n && buf4Index < buf4Read)
                buf[cnt++] = buf4[buf4Index++];
            if(buf4Index == buf4Read)  buf4Index = 0;
        }
        return cnt;
    }
private:
    char buf4[4];
    int buf4Index;
    int buf4Read;
};